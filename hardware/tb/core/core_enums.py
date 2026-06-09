#-----------------------------------------------------------------------------//
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# ----------------------------------------------------------------------------//
# Purpose: Core Enums
# Date: 2026/06
#-----------------------------------------------------------------------------//
from enum import Enum

class InstTE(Enum):
    NONE = 0
    LSU  = 1
    FPU  = 2
    UPP  = 3

class LSUOpTE(Enum): # LSU operation type enum
    LW      = 0
    SW      = 1
    ADDI    = 2
    ADD     = 3
    MUL     = 4

class FPUopTE(Enum): # FPU operation type enum
    ADD     = 0b00010,
    MUL     = 0b00011,
    DIV     = 0b00100,
    SQRT    = 0b00101,
    NEG     = 0b00110,
    MAX     = 0b00111

class UPPopTE(Enum): # UPP operation type enum
    DUM     = 0b00000