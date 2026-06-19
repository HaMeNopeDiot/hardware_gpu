#-----------------------------------------------------------------------------//
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# ----------------------------------------------------------------------------//
# Purpose: Core Enums
# Date: 2026/06
#-----------------------------------------------------------------------------//
from enum import Enum

class InstTE(Enum):
    UPP   = 0
    LOAD  = 1
    FPU   = 2
    STORE = 3

class LoadOpTE(Enum): # L-type operation type enum
    LW      = 0
    ADDI    = 1

class StoreOpTE(Enum): # S-type opertation type enum
    SW      = 0
    ADD     = 1
    MUL     = 2

class FPUopTE(Enum): # F-type operation type enum
    ADD     = 0b00010
    MUL     = 0b00011
    DIV     = 0b00100
    SQRT    = 0b00101
    NEG     = 0b00110
    MAX     = 0b00111

class UPPopTE(Enum): # U-type operation type enum
    LUI     = 0b00000
    RET     = 0b00001

class RoundModeE(Enum):
    RNE = 0b000 # to nearest, tie to even (default)
    RTZ = 0b001 # toward zero
    RDN = 0b010 # toward negative infinity
    RUP = 0b011 # toward positive infinity
    RMM = 0b100 # to nearest, tie away from zero
    ROD = 0b101 # to odd
    DYN = 0b111 # risc-v dynamic RM, invalid if passed to operations
