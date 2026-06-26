#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: APB master model
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb
from cocotb.triggers import RisingEdge, ReadOnly, Timer
from enum import IntEnum
from collections import namedtuple
from typing import Optional, List


class APBResp(IntEnum):
    """APB response types"""
    OKAY  = 0
    ERROR = 1


# Named tuple for APB transaction results
APBTransaction = namedtuple('APBTransaction', [
    'addr',       # Address
    'data',       # Write data or Read data
    'write',      # True = write, False = read
    'strb',       # Write strobes
    'prot',       # Protection type
    'resp',       # Response (OKAY/ERROR)
    'duration',   # Number of wait states
])


class APB4Master:
    """
    APB4 Master Bus Functional Model (BFM)

    Supports:
      - Single read/write transfers
      - Burst (back-to-back) transfers
      - Write strobes (PSTRB)
      - Protection signaling (PPROT)
      - Slave error response detection (PSLVERR)
      - Configurable timeout for PREADY
      - Transaction logging

    Generics:
      - ADDR_WIDTH: Address bus width (default 32)
      - DATA_WIDTH: Data bus width (default 32, supports 8/16/32)

    Signals (directly mapped from APB4 spec):
      - PCLK, PRESETn
      - PADDR, PPROT, PSELx, PENABLE, PWRITE, PWDATA, PSTRB
      - PREADY, PRDATA, PSLVERR

    Usage:
        apb_master = APB4Master(dut, "APB", dut.PCLK)
        data = await apb_master.read(0x0000_0000)
        await apb_master.write(0x0000_0004, 0xDEADBEEF)
    """

    def __init__(
        self,
        entity,
        prefix: str,
        clock,
        reset=None,
        reset_active_low: bool = True,
        addr_width: int = 32,
        data_width: int = 32,
        timeout_cycles: int = 1000,
        log=None,
    ):
        """
        Args:
            entity:           cocotb handle to the DUT or interface
            prefix:           Signal name prefix (e.g., "APB" for APB_PADDR, etc.)
                              Use "" if signals have no prefix.
            clock:            Clock signal handle
            reset:            Optional reset signal handle
            reset_active_low: True if reset is active low (PRESETn)
            addr_width:       Address bus width in bits
            data_width:       Data bus width in bits (8, 16, or 32)
            timeout_cycles:   Max cycles to wait for PREADY
            log:              Optional logger
        """
        self.entity = entity
        self.clock = clock
        self.reset = reset
        self.reset_active_low = reset_active_low
        self.addr_width = addr_width
        self.data_width = data_width
        self.strb_width = data_width // 8
        self.timeout_cycles = timeout_cycles
        self.log = log or cocotb.log.getChild(f"APB4Master")

        # Resolve signal names
        self._resolve_signals(entity, prefix)

        # Initialize all outputs to idle state
        self._init_signals()

        self.log.info(
            f"APB4 Master initialized: ADDR_WIDTH={addr_width}, "
            f"DATA_WIDTH={data_width}, STRB_WIDTH={self.strb_width}"
        )

    def _resolve_signals(self, entity, prefix: str):
        """Resolve APB4 signal handles from the entity."""
        sep = "_" if prefix else ""

        # Master-driven signals (outputs)
        self.paddr    = getattr(entity, f"{prefix}{sep}paddr",    None)
        self.pprot    = getattr(entity, f"{prefix}{sep}pprot",    None)
        self.psel     = getattr(entity, f"{prefix}{sep}psel",     None)
        self.penable  = getattr(entity, f"{prefix}{sep}penable",  None)
        self.pwrite   = getattr(entity, f"{prefix}{sep}pwrite",   None)
        self.pwdata   = getattr(entity, f"{prefix}{sep}pwdata",   None)
        self.pstrb    = getattr(entity, f"{prefix}{sep}pstrb",    None)

        # Slave-driven signals (inputs)
        self.pready   = getattr(entity, f"{prefix}{sep}pready",   None)
        self.prdata   = getattr(entity, f"{prefix}{sep}prdata",   None)
        self.pslverr  = getattr(entity, f"{prefix}{sep}pslverr",  None)

        # Verify required signals exist
        required_signals = {
            'PADDR': self.paddr,
            'PSEL': self.psel,
            'PENABLE': self.penable,
            'PWRITE': self.pwrite,
            'PWDATA': self.pwdata,
            'PREADY': self.pready,
            'PRDATA': self.prdata,
        }

        for name, sig in required_signals.items():
            if sig is None:
                raise AttributeError(
                    f"Required APB4 signal '{prefix}{sep}{name}' not found on entity"
                )

        # Optional signals - log warnings
        if self.pstrb is None:
            self.log.warning("PSTRB signal not found; write strobes won't be driven")
        if self.pprot is None:
            self.log.warning("PPROT signal not found; protection won't be driven")
        if self.pslverr is None:
            self.log.warning("PSLVERR signal not found; error responses won't be captured")

    def _init_signals(self):
        """Drive all master outputs to idle/default state."""
        self.paddr.value   = 0
        self.psel.value    = 0
        self.penable.value = 0
        self.pwrite.value  = 0
        self.pwdata.value  = 0

        if self.pstrb is not None:
            self.pstrb.value = 0
        if self.pprot is not None:
            self.pprot.value = 0

    # -------------------------------------------------------------------------
    # Public API
    # -------------------------------------------------------------------------

    async def write(
        self,
        addr: int,
        data: int,
        strb: Optional[int] = None,
        prot: int = 0,
    ) -> APBTransaction:
        """
        Perform a single APB4 write transaction.

        Args:
            addr: Target address
            data: Write data
            strb: Write strobe (default: all bytes enabled)
            prot: Protection type (3-bit PPROT value)

        Returns:
            APBTransaction with result details
        """
        if strb is None:
            strb = (1 << self.strb_width) - 1  # All strobes active

        self._validate_addr(addr)
        self._validate_data(data)
        self._validate_strb(strb)

        return await self._do_transfer(
            addr=addr,
            data=data,
            write=True,
            strb=strb,
            prot=prot,
        )

    async def read(
        self,
        addr: int,
        prot: int = 0,
    ) -> APBTransaction:
        """
        Perform a single APB4 read transaction.

        Args:
            addr: Target address
            prot: Protection type (3-bit PPROT value)

        Returns:
            APBTransaction with result details (data field contains read data)
        """
        self._validate_addr(addr)

        return await self._do_transfer(
            addr=addr,
            data=0,
            write=False,
            strb=0,
            prot=prot,
        )

    async def write_burst(
        self,
        start_addr: int,
        data_list: List[int],
        strb: Optional[int] = None,
        prot: int = 0,
        addr_increment: Optional[int] = None,
    ) -> List[APBTransaction]:
        """
        Perform back-to-back APB4 write transfers.

        Transitions directly from ACCESS → SETUP (no IDLE between transfers)
        for maximum throughput.

        Args:
            start_addr:     Starting address
            data_list:      List of data values to write
            strb:           Write strobes (applied to all transfers)
            prot:           Protection type
            addr_increment: Address increment per transfer (default: DATA_WIDTH/8)

        Returns:
            List of APBTransaction results
        """
        if strb is None:
            strb = (1 << self.strb_width) - 1

        if addr_increment is None:
            addr_increment = self.data_width // 8

        results = []
        for i, data in enumerate(data_list):
            addr = start_addr + i * addr_increment
            is_last = (i == len(data_list) - 1)

            # For back-to-back: next transfer setup overlaps with current complete
            if i == 0:
                txn = await self._do_transfer(
                    addr=addr, data=data, write=True, strb=strb, prot=prot,
                    back_to_back=not is_last,
                )
            else:
                txn = await self._do_transfer_access_phase(
                    addr=addr, data=data, write=True, strb=strb, prot=prot,
                    back_to_back=not is_last,
                )
            results.append(txn)

        return results

    async def read_burst(
        self,
        start_addr: int,
        count: int,
        prot: int = 0,
        addr_increment: Optional[int] = None,
    ) -> List[APBTransaction]:
        """
        Perform back-to-back APB4 read transfers.

        Args:
            start_addr:     Starting address
            count:          Number of reads to perform
            prot:           Protection type
            addr_increment: Address increment per transfer (default: DATA_WIDTH/8)

        Returns:
            List of APBTransaction results
        """
        if addr_increment is None:
            addr_increment = self.data_width // 8

        results = []
        for i in range(count):
            addr = start_addr + i * addr_increment
            is_last = (i == count - 1)

            if i == 0:
                txn = await self._do_transfer(
                    addr=addr, data=0, write=False, strb=0, prot=prot,
                    back_to_back=not is_last,
                )
            else:
                txn = await self._do_transfer_access_phase(
                    addr=addr, data=0, write=False, strb=0, prot=prot,
                    back_to_back=not is_last,
                )
            results.append(txn)

        return results

    async def reset_bus(self):
        """Reset all APB signals to idle state."""
        self._init_signals()
        await RisingEdge(self.clock)

    async def wait_reset_done(self):
        """Wait for reset de-assertion."""
        if self.reset is None:
            self.log.warning("No reset signal connected, skipping wait")
            return

        if self.reset_active_low:
            while self.reset.value == 0:
                await RisingEdge(self.clock)
        else:
            while self.reset.value == 1:
                await RisingEdge(self.clock)

        # Wait one more clock after reset de-assertion
        await RisingEdge(self.clock)
        self.log.info("Reset de-asserted")

    # -------------------------------------------------------------------------
    # Internal Transfer Engine
    # -------------------------------------------------------------------------

    async def _do_transfer(
        self,
        addr: int,
        data: int,
        write: bool,
        strb: int,
        prot: int,
        back_to_back: bool = False,
    ) -> APBTransaction:
        """
        Execute a complete APB4 transfer (SETUP + ACCESS phases).

        APB4 State Machine:
            IDLE → SETUP: Assert PSEL, drive PADDR/PWDATA/PWRITE/PSTRB/PPROT
            SETUP → ACCESS: Assert PENABLE
            ACCESS → IDLE/SETUP: Wait for PREADY, sample PRDATA/PSLVERR
        """
        # =====================================================================
        # SETUP Phase (T1)
        # =====================================================================
        await RisingEdge(self.clock)

        self.psel.value    = 1
        self.penable.value = 0
        self.paddr.value   = addr
        self.pwrite.value  = 1 if write else 0
        self.pwdata.value  = data if write else 0

        if self.pstrb is not None:
            self.pstrb.value = strb if write else 0
        if self.pprot is not None:
            self.pprot.value = prot

        self.log.debug(
            f"SETUP: {'WRITE' if write else 'READ'} addr=0x{addr:08X}"
            f"{f' data=0x{data:08X}' if write else ''}"
            f"{f' strb=0x{strb:X}' if write else ''}"
        )

        # =====================================================================
        # ACCESS Phase (T2+)
        # =====================================================================
        return await self._do_access_phase(
            addr=addr, data=data, write=write, strb=strb, prot=prot,
            back_to_back=back_to_back,
        )

    async def _do_access_phase(
        self,
        addr: int,
        data: int,
        write: bool,
        strb: int,
        prot: int,
        back_to_back: bool = False,
    ) -> APBTransaction:
        """Execute the ACCESS phase of a transfer."""
        await RisingEdge(self.clock)
        self.penable.value = 1

        # Wait for PREADY with timeout
        wait_states = 0
        while True:
            await RisingEdge(self.clock)

            # Sample PREADY at rising edge
            pready_val = self.pready.value

            if pready_val == 1:
                break

            wait_states += 1
            if wait_states >= self.timeout_cycles:
                self.log.error(
                    f"TIMEOUT: PREADY not asserted after {self.timeout_cycles} cycles "
                    f"for {'WRITE' if write else 'READ'} addr=0x{addr:08X}"
                )
                self._init_signals()
                raise TimeoutError(
                    f"APB4 PREADY timeout after {self.timeout_cycles} wait states"
                )

        # =====================================================================
        # Sample Response (at the rising edge where PREADY=1)
        # =====================================================================
        rdata = 0
        if not write:
            rdata = self.prdata.value

        resp = APBResp.OKAY
        if self.pslverr is not None:
            try:
                resp = APBResp(self.pslverr.value)
            except ValueError:
                resp = APBResp.ERROR

        if resp == APBResp.ERROR:
            self.log.warning(
                f"SLVERR: {'WRITE' if write else 'READ'} addr=0x{addr:08X}"
            )

        self.log.debug(
            f"ACCESS COMPLETE: {'WRITE' if write else 'READ'} addr=0x{addr:08X}"
            f"{f' rdata=0x{rdata:08X}' if not write else ''}"
            f" resp={resp.name} wait_states={wait_states}"
        )

        # Transition to IDLE or next SETUP
        if not back_to_back:
            # Return to IDLE
            self.psel.value    = 0
            self.penable.value = 0
            self.paddr.value   = 0
            self.pwrite.value  = 0
            self.pwdata.value  = 0
            if self.pstrb is not None:
                self.pstrb.value = 0
            if self.pprot is not None:
                self.pprot.value = 0

        txn = APBTransaction(
            addr=addr,
            data=rdata if not write else data,
            write=write,
            strb=strb,
            prot=prot,
            resp=resp,
            duration=wait_states + 2,  # SETUP(1) + ENABLE(1) + wait_states
        )

        return txn

    async def _do_transfer_access_phase(
        self,
        addr: int,
        data: int,
        write: bool,
        strb: int,
        prot: int,
        back_to_back: bool = False,
    ) -> APBTransaction:
        """
        For back-to-back transfers: the previous ACCESS phase completion
        overlaps with this transfer's SETUP phase.

        At this point, PSEL is already high and PENABLE just went low
        (handled by driving new address/data here).
        """
        # Drive new SETUP while PSEL stays asserted
        self.penable.value = 0
        self.paddr.value   = addr
        self.pwrite.value  = 1 if write else 0
        self.pwdata.value  = data if write else 0

        if self.pstrb is not None:
            self.pstrb.value = strb if write else 0
        if self.pprot is not None:
            self.pprot.value = prot

        self.log.debug(
            f"SETUP (B2B): {'WRITE' if write else 'READ'} addr=0x{addr:08X}"
            f"{f' data=0x{data:08X}' if write else ''}"
        )

        return await self._do_access_phase(
            addr=addr, data=data, write=write, strb=strb, prot=prot,
            back_to_back=back_to_back,
        )

    # -------------------------------------------------------------------------
    # Validation Helpers
    # -------------------------------------------------------------------------

    def _validate_addr(self, addr: int):
        """Validate address is within bus width."""
        max_addr = (1 << self.addr_width) - 1
        if addr < 0 or addr > max_addr:
            raise ValueError(
                f"Address 0x{addr:X} out of range for {self.addr_width}-bit bus "
                f"(max 0x{max_addr:X})"
            )

    def _validate_data(self, data: int):
        """Validate data is within bus width."""
        max_data = (1 << self.data_width) - 1
        if data < 0 or data > max_data:
            raise ValueError(
                f"Data 0x{data:X} out of range for {self.data_width}-bit bus "
                f"(max 0x{max_data:X})"
            )

    def _validate_strb(self, strb: int):
        """Validate strobe is within range."""
        max_strb = (1 << self.strb_width) - 1
        if strb < 0 or strb > max_strb:
            raise ValueError(
                f"Strobe 0x{strb:X} out of range (max 0x{max_strb:X})"
            )