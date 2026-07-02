#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Thread model
# Date: 2026/06
#------------------------------------------------------------------------------#


import math

import cocotb

from utility.defines                import DW, VID_ADDR, ZERO_ADDR, THREADS_CNT

from core.core_enums                import CoreOp, FPU_OP
from core.core_instr_item           import CoreInstItem
from core.models.regfile_model      import RegfileModel

from fpu.fppconverter       import hex_ieee754_to_float, ieee754_to_float, float_to_i754

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
        self._regfile = RegfileModel(
            name = f"regfile-{self.name}",
            log = self.log,
            dw = self._dw,
            regfile_size = self._regfile_sz,
            vid_addr = self._vid_addr,
            zero_addr = self._zero_addr
        )

    def write_regfile(self, addr: int, data: int):
        self._regfile.write(addr, data)

    def read_regfile(self, addr: int) -> int:
        return self._regfile.read(addr)

    def _fpu_op_calc(self, op: CoreOp, rs1: float, rs2: float) -> float:
        rd = 0
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
        return rd

    def _fpu_calc(self, instr: CoreInstItem, op: CoreOp):
        rs1_addr = instr.rs1_addr
        rs2_addr = instr.rs2_addr
        # read registers from setted address
        rs1_i754 = self.read_regfile(rs1_addr)
        rs2_i754 = self.read_regfile(rs2_addr)
        cocotb.log.debug(f"rs1: {rs1_i754} from {rs1_addr}; rs2: {rs2_i754} from {rs2_addr};")
        # If we use FPU operation we need to convert data for FPU to float from ieee754
        rs1 = ieee754_to_float(rs1_i754, self._dw)
        rs2 = ieee754_to_float(rs2_i754, self._dw)
        # Operate
        rd = self._fpu_op_calc(op, rs1, rs2)
        # Convert float result to ieee754
        rd_i754 = float_to_i754(rd, self._dw)
        # Write result in regfile
        self.write_regfile(instr.rd_addr, rd_i754)

    def handle_op(self, instr: CoreInstItem, data: int = 0) -> int:
        op = instr.op

        rd_addr = instr.rd_addr
        rs1_addr = instr.rs1_addr
        rs2_addr = instr.rs2_addr
        imm = instr.imm

        if op in FPU_OP:
            self._fpu_calc(instr, op)
        else:
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
        self._regfile.write(self._vid_addr, vid, force=True)

    def launch(self):
        self.log.info(f"{self.name} thread launched")
        self._en = 1

    def print(self, max_regs_in_col: int = 8):
        self._regfile.print(max_regs_in_col)
