#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Core Operation Class
# Date: 2026/06
#------------------------------------------------------------------------------#

from core.core_enums import InstTE, LoadOpTE, FPUopTE, UPPopTE, StoreOpTE, VOpTE
from core.core_enums import CoreOp
import cocotb

class CoreOperation():
    def __init__(self, core_op = None, name = "instr", logger = cocotb.log):
        self.op: CoreOp = core_op
        self.name = name
        self.logger = logger

    def _parse_u_type_op(self, op: UPPopTE):
        match op:
            case UPPopTE.LUI:
                return CoreOp.LUI
            case UPPopTE.RET:
                return CoreOp.RET
            case UPPopTE.JAL:
                return CoreOp.JAL
            case _:
                assert False, f"Unknown {self.name} operation type"

    def _parse_l_type_op(self, op: LoadOpTE):
        match op:
            case LoadOpTE.LW:
                return CoreOp.LW
            case LoadOpTE.ADDI:
                return CoreOp.ADDI
            case LoadOpTE.JALR:
                return CoreOp.JALR
            case _:
                assert False, f"Unknown {self.name} operation type"

    def _parse_f_type_op(self, op: FPUopTE):
        match op:
            case FPUopTE.ADD:
                return CoreOp.FADD
            case FPUopTE.MUL:
                return CoreOp.FMUL
            case FPUopTE.DIV:
                return CoreOp.FDIV
            case FPUopTE.SQRT:
                return CoreOp.FSQRT
            case FPUopTE.NEG:
                return CoreOp.FNEG
            case FPUopTE.MAX:
                return CoreOp.FMAX
            case _:
                assert False, f"Unknown {self.name} operation type"

    def _parse_s_type_op(self, op: StoreOpTE):
        match op:
            case StoreOpTE.ADD:
                return CoreOp.ADD
            case StoreOpTE.MUL:
                return CoreOp.MUL
            case StoreOpTE.SW:
                return CoreOp.SW
            case _:
                assert False, f"Unknown {self.name} operation type"

    def set_op_from_instr(self, instr_op: InstTE) -> CoreOp:
        # print(type(instr_op))
        if isinstance(instr_op, UPPopTE):
            self.op = self._parse_u_type_op(instr_op)
        elif isinstance(instr_op, LoadOpTE):
            self.op = self._parse_l_type_op(instr_op)
        elif isinstance(instr_op, FPUopTE):
            self.op = self._parse_f_type_op(instr_op)
        elif isinstance(instr_op, StoreOpTE):
            self.op = self._parse_s_type_op(instr_op)
        else:
            assert isinstance(instr_op, (LoadOpTE, StoreOpTE, UPPopTE, FPUopTE)), "Unknown instruction type"

    def get_instr_from_op(self) -> VOpTE:
        match self.op:
            case CoreOp.LW:
                return LoadOpTE.LW
            case CoreOp.SW:
                return StoreOpTE.SW
            case CoreOp.LUI:
                return UPPopTE.LUI
            case CoreOp.ADDI:
                return LoadOpTE.ADDI
            case CoreOp.FADD:
                return FPUopTE.ADD
            case CoreOp.FMUL:
                return FPUopTE.MUL
            case CoreOp.FDIV:
                return FPUopTE.DIV
            case CoreOp.FSQRT:
                return FPUopTE.SQRT
            case CoreOp.FNEG:
                return FPUopTE.NEG
            case CoreOp.FMAX:
                return FPUopTE.MAX
            case CoreOp.ADD:
                return StoreOpTE.ADD
            case CoreOp.MUL:
                return StoreOpTE.MUL
            case CoreOp.RET:
                return UPPopTE.RET
            case CoreOp.JAL:
                return UPPopTE.JAL
            case CoreOp.JALR:
                return LoadOpTE.JALR