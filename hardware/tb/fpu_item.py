# --------------------------------------------------------------
#  fpnew_item.py
# --------------------------------------------------------------
from enum import Enum

from fppconverter import float_to_ieee754, ieee754_to_float, float_to_i754

class OperationE(Enum):
    FMADD = 0       # op[0] * op[1] + op[2]
    FNMSUB = 1      # op[0] * op[1] - op[2]
    ADD = 2         # op[1] + op[2]
    MUL = 3         # op[0] * op[1]
    DIV = 4         # op[0] / op[1]
    SQRT = 5        # sqrt(op[0])
    SGNJ = 6        # (op[0] * sign(op[1])) * -1
    MINMAX = 7      # min
    CMP = 8
    CLASSIFY = 9
    F2F = 10
    F2I = 11
    I2F = 12
    CPKAB = 13
    CPKCD = 14
    ADDS = 15

class RoundModeE(Enum):
    RNE = 0 # Nearest, tie to Even
    RTZ = 1 # Toward zero
    RDN = 2 # Toward negative infinity
    RUP = 3 # Toward positive infinity
    RMM = 4 # To nearest, tie away from zero
    ROD = 5 # To odd
    DYN = 6 # RISC-V Dynamic RM, invalid if passed to operation

class FpFormatE(Enum):
    FP32    = 0
    FP64    = 1
    FP16    = 2
    FP8     = 3
    FP16ALT = 4

class IntFormatE(Enum):
    INT8    = 0
    INT16   = 1
    INT32   = 2
    INT64   = 3

DEFAULT_F_T = FpFormatE.FP64
DEFAULT_I_T = IntFormatE.INT64

class FPUItem():
    def __init__(self,
                operands: list[float, float, float],
                op_code: OperationE,
                op_mod: int = 0,
                rnd_mode: RoundModeE = RoundModeE.RNE,
                src_fmt: FpFormatE = DEFAULT_F_T,
                dst_fmt: FpFormatE = DEFAULT_F_T,
                int_fmt: IntFormatE = DEFAULT_I_T,
                tag: int = 0
                 ):
        self._op_code: OperationE = op_code
        self._op_mod: int = op_mod
        self._rnd_mode: RoundModeE = rnd_mode
        self._src_fmt: FpFormatE = src_fmt
        self._dst_fmt: FpFormatE = dst_fmt
        self._int_fmt: IntFormatE = int_fmt
        self._tag: int = tag
        self._operands = [
            float_to_i754(operands[0], self._f_fmt_to_width(src_fmt)),
            float_to_i754(operands[1], self._f_fmt_to_width(src_fmt)),
            float_to_i754(operands[2], self._f_fmt_to_width(src_fmt))
                        ]
        self._simd_mask_i: int = 0
        self._vectorial_op_i: int = 0


    def _f_fmt_to_width(self, format: FpFormatE) -> int:
        match format:
            case FpFormatE.FP8:     return 8
            case FpFormatE.FP16:    return 16
            case FpFormatE.FP16ALT: return 16
            case FpFormatE.FP32:    return 32
            case FpFormatE.FP64:    return 64
            case _:                 return -1
