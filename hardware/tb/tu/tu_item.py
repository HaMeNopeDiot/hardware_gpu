# --------------------------------------------------------------
#  tu_item.py
# --------------------------------------------------------------
from pyuvm import utility_classes

from utility.enums  import OperationE, RoundModeE, DirectionE
from utility.enums  import DEFAULT_F_T

from fpu.fppconverter import float_to_i754

class ThreadUnitCommandItem():
    def __init__(self,
                 operands_addr: list[int, int, int],
                 result_addr: int,
                 op_code: OperationE,
                 rnd_mode: RoundModeE = RoundModeE.RNE,
                 op_mod: int = 0,
                 tag: int = 0):
        self._op_addr: list = operands_addr
        self._res_addr: int = result_addr
        self._op_code: OperationE = op_code
        self._op_mod: int = op_mod
        self._tag: int = tag
        self._rnd_mode: RoundModeE = RoundModeE.RNE

class Lsu2TreadUnitCommandItem():
    def __init__(self, rw = DirectionE.READ, addr: int = 0, data: float = 0):
        self._rw: DirectionE = rw
        self._addr: int = addr
        self._data = float_to_i754(data, self._f_fmt_to_width(DEFAULT_F_T))

