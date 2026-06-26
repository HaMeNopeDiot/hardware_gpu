# --------------------------------------------------------------
#  utility.py
# --------------------------------------------------------------
from enum import Enum

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

class DirectionE(Enum):
    READ = 0
    WRITE = 1

