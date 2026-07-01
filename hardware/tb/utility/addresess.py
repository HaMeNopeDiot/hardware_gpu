# --------------------------------------------------------------
#  addresses.py
# --------------------------------------------------------------
from enum import Enum

from utility.defines    import BYTES_CNT

class CSRAddr(Enum):
    CORE_CTRL = 0x0 * BYTES_CNT
    CORE_STAT = 0x1 * BYTES_CNT
    CORE_PC   = 0x2 * BYTES_CNT
    TU_EN     = 0x3 * BYTES_CNT
    CORE_VID  = 0x5 * BYTES_CNT