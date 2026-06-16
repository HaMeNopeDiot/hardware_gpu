# ahb_slave.py

import cocotb
from cocotb.triggers import RisingEdge, ReadOnly
from cocotb.types import LogicArray
from enum import IntEnum
from collections import defaultdict


class AHBTransType(IntEnum):
    """AHB Transfer Types (HTRANS)"""
    IDLE   = 0b00
    BUSY   = 0b01
    NONSEQ = 0b10
    SEQ    = 0b11


class AHBRespType(IntEnum):
    """AHB Response Types (HRESP)"""
    OKAY  = 0
    ERROR = 1


class AHBSize(IntEnum):
    """AHB Transfer Sizes (HSIZE)"""
    BYTE      = 0b000  # 8 bits
    HALFWORD  = 0b001  # 16 bits
    WORD      = 0b010  # 32 bits
    DWORD     = 0b011  # 64 bits
    FOURWORD  = 0b100  # 128 bits
    EIGHTWORD = 0b101  # 256 bits


class AHBBurstType(IntEnum):
    """AHB Burst Types (HBURST)"""
    SINGLE = 0b000
    INCR   = 0b001
    WRAP4  = 0b010
    INCR4  = 0b011
    WRAP8  = 0b100
    INCR8  = 0b101
    WRAP16 = 0b110
    INCR16 = 0b111


class BinFakeValue:
    def __init__(self, value = 0):
        self.value = value

class AHBSlaveModel:
    """
    AHB-Lite Slave Bus Functional Model.

    Features:
    - Configurable memory size and data width
    - Supports BYTE, HALFWORD, WORD, DWORD accesses
    - Pipeline-aware (address phase / data phase)
    - Configurable wait states
    - Error response generation for out-of-range addresses
    - Optional read/write callbacks
    - Burst transfer support
    - Byte-lane masking based on HSIZE

    Parameters:
        dut:            cocotb DUT handle
        name:           Signal prefix (e.g., "" or "ahb_")
        clock:          Clock signal
        memory_size:    Memory size in bytes (default 4KB)
        data_width:     Data bus width in bits (default 32)
        wait_states:    Number of wait states per transfer (default 0)
        error_addr:     Set of addresses that generate ERROR response
    """

    def __init__(
        self,
        dut,
        name="",
        clock=None,
        memory_size=4096,
        data_width=32,
        wait_states=0,
        error_addr=None,
        log=None,
    ):
        self.dut = dut
        self.name = name
        self.clock = clock or dut.clk
        self.memory_size = memory_size
        self.data_width = data_width
        self.byte_width = data_width // 8
        self.wait_states = wait_states
        self.error_addresses = error_addr or set()
        self.log = log or dut._log

        # Internal memory (byte-addressable)
        self.memory = defaultdict(lambda: 0x00)

        # Callbacks
        self.read_callback = None
        self.write_callback = None

        # --- Resolve signal names ---
        prefix = name + "_" if name else ""
        # Inputs from master
        self.hsel      = BinFakeValue(1) # self._get_signal(f"{prefix}_hsel")
        self.haddr     = self._get_signal(f"{prefix}haddr")
        self.htrans    = self._get_signal(f"{prefix}htrans")
        self.hwrite    = self._get_signal(f"{prefix}hwrite")
        self.hsize     = self._get_signal(f"{prefix}hsize")
        self.hburst    = self._get_signal(f"{prefix}hburst")
        self.hwdata    = self._get_signal(f"{prefix}hwdata")
        self.hready_in = self._get_signal(f"{prefix}hreadyin", optional=True)

        # Outputs to master
        self.hrdata  = self._get_signal(f"{prefix}hrdata")
        self.hready  = self._get_signal(f"{prefix}hready")
        self.hresp   = self._get_signal(f"{prefix}hresp")

        # HRESETn
        self.hresetn = self._get_signal(f"{prefix}rst_n", optional=True) or \
                       self._get_signal("rst_n", optional=True)

        # Pipeline registers (address phase → data phase)
        self._addr_phase_valid = False
        self._addr_phase_addr  = 0
        self._addr_phase_write = False
        self._addr_phase_size  = 0
        self._addr_phase_burst = 0
        self._addr_phase_error = False

        # Statistics
        self.stats = {
            "reads": 0,
            "writes": 0,
            "errors": 0,
            "idle_cycles": 0,
        }

        # Initialize outputs
        self._init_outputs()

        # Start the main coroutine
        self._running = True
        self._coro = cocotb.start_soon(self._run())

    def _get_signal(self, signal_name, optional=False):
        """Resolve a signal from the DUT by name."""
        try:
            return getattr(self.dut, signal_name)
        except AttributeError:
            if optional:
                return None
            raise AttributeError(
                f"AHBSlaveModel: Required signal '{signal_name}' not found on DUT"
            )

    def _init_outputs(self):
        """Initialize output signals to default values."""
        self.hrdata.value = 0
        self.hready.value = 1
        self.hresp.value = AHBRespType.OKAY

    # -------------------------------------------------------------------------
    # Memory Access Helpers
    # -------------------------------------------------------------------------

    def _get_byte_mask(self, addr, size):
        """
        Calculate byte enables based on address and size.

        Returns:
            (offset, num_bytes): byte offset within the data word and number of bytes
        """
        num_bytes = 1 << size  # 2^size bytes
        # Align to natural boundary within the data word
        offset = addr % self.byte_width
        return offset, num_bytes

    def read_memory(self, addr, size):
        """
        Read from internal memory.

        Args:
            addr: Byte address
            size: HSIZE value (0=byte, 1=half, 2=word, etc.)

        Returns:
            Data value read from memory
        """
        num_bytes = 1 << size
        aligned_addr = addr & ~(num_bytes - 1)  # Natural alignment

        value = 0
        for i in range(num_bytes):
            value |= self.memory[aligned_addr + i] << (8 * i)

        return value

    def write_memory(self, addr, size, data):
        """
        Write to internal memory.

        Args:
            addr: Byte address
            size: HSIZE value
            data: Data to write
        """
        num_bytes = 1 << size
        aligned_addr = addr & ~(num_bytes - 1)

        for i in range(num_bytes):
            self.memory[aligned_addr + i] = (data >> (8 * i)) & 0xFF

    def read_word(self, addr):
        """Convenience: read a 32-bit word from memory."""
        return self.read_memory(addr, AHBSize.WORD)

    def write_word(self, addr, data):
        """Convenience: write a 32-bit word to memory."""
        self.write_memory(addr, AHBSize.WORD, data)

    def fill_memory(self, start_addr, data_list, size=AHBSize.WORD):
        """Fill memory with a list of values starting at start_addr."""
        num_bytes = 1 << size
        for i, data in enumerate(data_list):
            self.write_memory(start_addr + i * num_bytes, size, data)

    def dump_memory(self, start_addr, length):
        """Dump memory contents for debugging."""
        self.log.info(f"Memory dump: 0x{start_addr:08X} - 0x{start_addr+length-1:08X}")
        for addr in range(start_addr, start_addr + length, self.byte_width):
            word = self.read_memory(addr, AHBSize.WORD)
            self.log.info(f"  [0x{addr:08X}] = 0x{word:08X}")

    # -------------------------------------------------------------------------
    # Data Phase Processing
    # -------------------------------------------------------------------------

    def _build_read_data(self, addr, size):
        """
        Build the HRDATA value, placing the read bytes in the correct
        byte lanes for the bus width.
        """
        num_bytes = 1 << size
        aligned_addr = addr & ~(num_bytes - 1)

        # Read the raw value from memory
        raw_value = self.read_memory(aligned_addr, size)

        # Place in correct byte lane within the data word
        byte_offset = aligned_addr % self.byte_width
        hrdata = raw_value << (8 * byte_offset)

        return hrdata & ((1 << self.data_width) - 1)

    def _extract_write_data(self, addr, size, hwdata):
        """
        Extract write data from the correct byte lanes of HWDATA.
        """
        num_bytes = 1 << size
        aligned_addr = addr & ~(num_bytes - 1)
        byte_offset = aligned_addr % self.byte_width

        # Extract from correct byte lanes
        mask = (1 << (8 * num_bytes)) - 1
        data = (hwdata >> (8 * byte_offset)) & mask

        return data

    # -------------------------------------------------------------------------
    # Main Coroutine
    # -------------------------------------------------------------------------

    async def _run(self):
        """Main AHB slave state machine."""

        self.log.info("AHBSlaveModel started")

        while self._running:
            await RisingEdge(self.clock)

            # Check reset
            if self.hresetn is not None and self.hresetn.value == 0:
                self._reset()
                continue

            # Check if upstream is ready (for multi-layer systems)
            if self.hready_in is not None and self.hready_in.value == 0:
                continue

            # ---- DATA PHASE (process previous address phase) ----
            await self._process_data_phase()

            # ---- ADDRESS PHASE (latch current address) ----
            await ReadOnly()  # Sample inputs at ReadOnly to avoid race
            self._sample_address_phase()

    async def _process_data_phase(self):
        """Process the data phase of the pipeline."""
        if self._addr_phase_valid:
            # self.log.error(f"AHB TXN CPTR")

            # Handle wait states
            for _ in range(self.wait_states):
                self.hready.value = 0
                self.hresp.value = AHBRespType.OKAY
                await RisingEdge(self.clock)

            # Check for error response
            if self._addr_phase_error:
                await self._error_response()
                return

            if self._addr_phase_write:
                # --- WRITE Data Phase ---
                hwdata = int(self.hwdata.value)
                wdata = self._extract_write_data(
                    self._addr_phase_addr,
                    self._addr_phase_size,
                    hwdata,
                )
                self.write_memory(
                    self._addr_phase_addr,
                    self._addr_phase_size,
                    wdata,
                )
                self.stats["writes"] += 1

                self.log.debug(
                    f"WRITE: addr=0x{self._addr_phase_addr:08X} "
                    f"size={self._addr_phase_size} "
                    f"data=0x{wdata:08X} (hwdata=0x{hwdata:08X})"
                )

                if self.write_callback:
                    self.write_callback(
                        self._addr_phase_addr,
                        self._addr_phase_size,
                        wdata,
                    )
            else:
                # --- READ Data Phase ---
                hrdata = self._build_read_data(
                    self._addr_phase_addr,
                    self._addr_phase_size,
                )
                self.hrdata.value = hrdata
                self.stats["reads"] += 1

                self.log.debug(
                    f"READ:  addr=0x{self._addr_phase_addr:08X} "
                    f"size={self._addr_phase_size} "
                    f"data=0x{hrdata:08X}"
                )

                if self.read_callback:
                    self.read_callback(
                        self._addr_phase_addr,
                        self._addr_phase_size,
                        hrdata,
                    )

            # Signal transfer complete
            self.hready.value = 1
            self.hresp.value = AHBRespType.OKAY

        else:
            # No valid transfer in data phase
            self.hready.value = 1
            self.hresp.value = AHBRespType.OKAY
            self.stats["idle_cycles"] += 1

    def _sample_address_phase(self):
        """Sample and latch address phase signals."""

        try:
            hsel   = int(self.hsel.value)
            htrans = int(self.htrans.value)
        except ValueError:
            # X/Z on bus
            self._addr_phase_valid = False
            return

        # Check for valid transfer
        if hsel and htrans in (AHBTransType.NONSEQ, AHBTransType.SEQ):
            self._addr_phase_valid = True
            self._addr_phase_addr  = int(self.haddr.value)
            self._addr_phase_write = int(self.hwrite.value) == 1
            self._addr_phase_size  = int(self.hsize.value)
            self._addr_phase_burst = int(self.hburst.value)

            # Check for error conditions
            self._addr_phase_error = self._check_error(
                self._addr_phase_addr,
                self._addr_phase_size,
            )
        else:
            self._addr_phase_valid = False

    def _check_error(self, addr, size):
        """Check if the transfer should produce an error response."""
        num_bytes = 1 << size

        # Out of range
        if addr + num_bytes > self.memory_size:
            self.log.warning(
                f"ERROR: Address 0x{addr:08X} out of range "
                f"(memory_size=0x{self.memory_size:X})"
            )
            return True

        # Explicit error address
        if addr in self.error_addresses:
            self.log.warning(f"ERROR: Address 0x{addr:08X} in error set")
            return True

        # Alignment check
        if addr & (num_bytes - 1):
            self.log.warning(
                f"ERROR: Unaligned access addr=0x{addr:08X} size={size}"
            )
            return True

        return False

    async def _error_response(self):
        """
        Generate a two-cycle AHB error response per protocol spec.

        Cycle 1: HREADY=0, HRESP=ERROR
        Cycle 2: HREADY=1, HRESP=ERROR
        """
        self.stats["errors"] += 1

        # First cycle of error
        self.hready.value = 0
        self.hresp.value = AHBRespType.ERROR
        await RisingEdge(self.clock)

        # Second cycle of error
        self.hready.value = 1
        self.hresp.value = AHBRespType.ERROR

        self._addr_phase_valid = False  # Cancel any latched transfer

    def _reset(self):
        """Reset internal state."""
        self._addr_phase_valid = False
        self._addr_phase_addr = 0
        self._addr_phase_write = False
        self._addr_phase_size = 0
        self._addr_phase_error = False
        self._init_outputs()
        self.log.info("AHBSlaveModel: Reset")

    # -------------------------------------------------------------------------
    # Control API
    # -------------------------------------------------------------------------

    def stop(self):
        """Stop the slave model coroutine."""
        self._running = False

    def clear_memory(self):
        """Clear all memory contents."""
        self.memory.clear()

    def set_wait_states(self, wait_states):
        """Dynamically change the number of wait states."""
        self.wait_states = wait_states

    def add_error_address(self, addr):
        """Add an address to the error set."""
        self.error_addresses.add(addr)

    def remove_error_address(self, addr):
        """Remove an address from the error set."""
        self.error_addresses.discard(addr)

    def get_stats(self):
        """Return transfer statistics."""
        return dict(self.stats)

    def reset_stats(self):
        """Reset statistics counters."""
        self.stats = {k: 0 for k in self.stats}