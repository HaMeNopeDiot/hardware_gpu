#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Regfile model
# Date: 2026/06
#------------------------------------------------------------------------------#

import math
import cocotb
from collections import defaultdict

from utility.defines    import DW, THREADS_CNT, REGFILE_SZ, VID_ADDR, ZERO_ADDR

from core.thread_model  import ThreadModel
from core.core_enums    import CoreOp
from core.core_instr_item   import CoreInstItem

from fpu.fppconverter import ieee754_to_float, float_to_i754


class RegfileModel():
    def __init__(self,
                 name: str      = "regfile",
                 log            = cocotb.log,
                 dw             = DW,
                 tu_num         = THREADS_CNT,
                 regfile_size   = REGFILE_SZ,
                 vid_addr: int   = VID_ADDR,
                 zero_addr: int = ZERO_ADDR):
        self.name           = name
        self.log            = log
        self._dw            = dw
        self._tu_num        = tu_num
        self._regfile_sz    = regfile_size
        self._vid_addr = vid_addr
        self._zero_addr = zero_addr
        # initial
        self._aw = math.ceil(math.log2(self._regfile_sz))
        self._bytes_num     = math.ceil(self._dw / 8)
        self._regile_mem    = defaultdict(lambda: 0x00)

    def _check_addr(self, addr: int, throw_assert: bool = True) -> int:
        if not(addr < self._regfile_sz or addr >= 0):
            self.log.error(f"Incorrect address sended in Core Model. Addr must be: 0 <= {addr} < {self._dw} ")
            if throw_assert:
                assert addr < self._regfile_sz or addr >= 0, f"Incorrect address"
            else:
                return -1
        return 0

    def _check_data(self, data: int, throw_assert: bool = True) -> int:
        if not(data >= 0 or data < (1 << self._dw)):
            self.log.error(f"Incorrect data sended in Core Model. Data must be: 0 <= {data} < {1 << self._dw}")
            if throw_assert:
                assert data >= 0 or data < (1 << self._dw), f"Incorrect data"
            else:
                return -1
        return 0

    def write_regfile(self, addr: int, data: int):
        self._check_addr(addr)
        self._check_data(data)
        if addr == self._vid_addr:
            self.log.warning(f"Attempt to directly write in VID address. VID register is Read Only.")
        elif addr == self._zero_addr:
            self.log.warning(f"Attempt to directly write in ZERO address. ZERO register is Read Only")
        else:
            self.log.debug(f"{self.name} thread: try to write in addr: {addr} data: {data}")
            self._regfile_mem[addr] = data
            self.log.debug(f"Writed {self._regfile_mem[addr]} in {addr}")

    def read_regfile(self, addr: int) -> int:
        self._check_addr(addr)
        return self._regfile_mem[addr]

    def print(self, max_regs_in_col: int = 8):
        mric = max_regs_in_col
        self.log.info(f"Thread print: {self.name}")
        for i in range(self._regfile_sz):
            reg = self._regfile_mem[i]
            if i % mric == mric - 1:
                print(f" {reg:08x}", end="\n")
            elif i % mric == 0:
                print(f"{i:03x}:{(i+8):03x}: {reg:08x}", end="")
            else:
                print(f" {reg:08x}", end="")