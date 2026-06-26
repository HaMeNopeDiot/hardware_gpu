#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Thread model
# Date: 2026/06
#------------------------------------------------------------------------------#


import math

import cocotb

from utility.defines    import DW, VID_ADDR, ZERO_ADDR, THREADS_CNT

from core.core_enums    import CoreOp
from core.core_instr_item   import CoreInstItem

from fpu.fppconverter import ieee754_to_float, float_to_i754

from collections import defaultdict

class ThreadModel():
    def __init__(self,
                 name: str = "",
                 log = cocotb.log,
                 dw: int = DW,
                 regfile_sz:int = 32,
                 vid_addr: int = VID_ADDR,
                 zero_addr: int = ZERO_ADDR):
        # safe parameters
        self.name = name
        self.log = log
        self._dw = dw
        self._regfile_sz = regfile_sz
        self._vid_addr = vid_addr
        self._zero_addr = zero_addr
        # initial
        self._aw = math.ceil(math.log2(self._regfile_sz))
        self._en = 0
        self._regfile_mem = defaultdict(lambda: 0x00)

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

    def _fpu_calc(self, instr: CoreInstItem, op: CoreOp):
        rs1_addr = instr.rs1_addr
        rs2_addr = instr.rs2_addr
        rs1_i754 = self.read_regfile(rs1_addr)
        rs2_i754 = self.read_regfile(rs2_addr)
        cocotb.log.debug(f"rs1: {rs1_i754} from {rs1_addr}; rs2: {rs2_i754} from {rs2_addr};")
        if rs1_i754 != 0:
            rs1 = ieee754_to_float(hex(rs1_i754), self._dw)
        else:
            rs1 = 0
        if rs2_i754 != 0:
            rs2 = ieee754_to_float(hex(rs2_i754), self._dw)
        else:
            rs2 = 0
        match op:
            case CoreOp.FADD:
                rd = rs1 + rs2
            case CoreOp.FMUL:
                rd = rs1 * rs2
            case CoreOp.FDIV:
                rd = rs1 / rs2
            case CoreOp.FSQRT:
                rd = math.sqrt(rs1)
            case CoreOp.FNEG:
                rd = -rs1
            case CoreOp.FMAX:
                rd = max(rs1, rs2)
            case _:
                assert False, f"Unknown Core Op in fpu calc: {op}"
        rd_i754 = float_to_i754(rd, self._dw)
        self.write_regfile(instr.rd_addr, rd_i754)

    def handle_op(self, instr: CoreInstItem, data: int = 0) -> int:
        op = instr.get_op()

        rd_addr = instr.rd_addr
        rs1_addr = instr.rs1_addr
        rs2_addr = instr.rs2_addr
        imm = instr.imm
        match op:
            case CoreOp.LW:
                self.write_regfile(rd_addr, data)
            case CoreOp.SW:
                return self.read_regfile(rs2_addr)
            case CoreOp.LUI:
                self.write_regfile(rd_addr, imm << 12)
            case CoreOp.ADDI:
                rs1 = self.read_regfile(rs1_addr)
                self.write_regfile(rd_addr, rs1 + imm)
            case CoreOp.FADD:
                self._fpu_calc(instr, op)
            case CoreOp.FMUL:
                self._fpu_calc(instr, op)
            case CoreOp.FDIV:
                self._fpu_calc(instr, op)
            case CoreOp.FSQRT:
                self._fpu_calc(instr, op)
            case CoreOp.FNEG:
                self._fpu_calc(instr, op)
            case CoreOp.FMAX:
                self._fpu_calc(instr, op)
            case CoreOp.ADD:
                rs1 = self.read_regfile(rs1_addr)
                rs2 = self.read_regfile(rs2_addr)
                self.write_regfile(rd_addr, rs1 + rs2)
            case CoreOp.MUL:
                rs1 = self.read_regfile(rs1_addr)
                rs2 = self.read_regfile(rs2_addr)
                self.write_regfile(rd_addr, rs1 * rs2)
            case CoreOp.RET:
                self.log.info(f"{self.name} thread stopped")
                self._en = 0
            case _:
                assert False, f"Unknown Core Operation: {op}"

    def set_vid(self, vid: int):
        self._check_data(vid)
        self._regfile_mem[self._vid_addr] = vid

    def launch(self):
        self.log.info(f"{self.name} thread launched")
        self._en = 1