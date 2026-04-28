# --------------------------------------------------------------
#  tu_item.py
# --------------------------------------------------------------
from pyuvm import utility_classes

from utility.enums  import OperationE, RoundModeE, DirectionE
from utility.enums  import DEFAULT_F_T

from fpu.fppconverter import float_to_i754

import math
from enum import Enum

import cocotb

class TUItem():
    def __init__(self):
        pass

    def get_w_by_enum(self, enum: Enum) -> int:
        values = [e.value for e in enum]
        if not values: return 0
        return math.ceil(math.log2(max(values)))


    def get_mask_by_enum(self, enum: Enum) -> int:
        width = self.get_w_by_enum(enum)
        return (1 << width) - 1

    def pack2bs(self) -> int:
        pass

class TUCmdItem(TUItem):
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

    def pack2bs(self, regfile_sz: int = 8, tag_sz = 4) -> int:
        op_code_tmp = self._op_code.value & self.get_mask_by_enum(OperationE)
        op_mode_tmp = self._op_mod & 0b1
        # addreses
        regfile_w = math.ceil(math.log2(regfile_sz))
        addr_mask = (1 << regfile_w) - 1
        addr_f_l = []
        for i in range(len(self._op_addr)):
            addr_f_l.append(self._op_addr[i] & addr_mask)
        addr_f_tmp =  (addr_f_l[0] << regfile_w * 2) \
                    | (addr_f_l[1] << regfile_w) \
                    | (addr_f_l[2])
        addr_r_tmp = self._res_addr & (1 << regfile_w) - 1
        tag_w = math.ceil(math.log2(tag_sz))
        tag_tmp = self._tag & (1 << tag_w) - 1
        rnd_tmp = self._rnd_mode.value & self.get_mask_by_enum(RoundModeE)
        # get shifters
        shift_l = [0]
        shift_l.append(shift_l[0] + self.get_w_by_enum(RoundModeE)) # tag
        shift_l.append(shift_l[1] + tag_w) # addr res
        shift_l.append(shift_l[2] + regfile_w) # addresses
        shift_l.append(shift_l[3] + regfile_w * 3) # op_mod
        shift_l.append(shift_l[4] + 1) # 0
        cocotb.log.debug(f"offsets:"  \
                           f" {shift_l[0]};" \
                           f" {shift_l[1]};" \
                           f" {shift_l[2]};" \
                           f" {shift_l[3]};" \
                           f" {shift_l[4]}")
        # Pack it up
        result  = (rnd_tmp     << shift_l[0]) \
                | (tag_tmp     << shift_l[1]) \
                | (addr_r_tmp  << shift_l[2]) \
                | (addr_f_tmp  << shift_l[3]) \
                | (op_mode_tmp << shift_l[4]) \
                | (op_code_tmp << shift_l[5])
        cocotb.log.debug(f"result: {bin(result)}")
        return result

class Lsu2TUCmdItem(TUItem):
    def __init__(self,
                 rw = DirectionE.READ,
                 addr: int = 0,
                 data: float = 0,
                 data_w: int = 64):
        self._rw: DirectionE = rw
        self._addr: int = addr
        self._data_w: int = data_w
        self._data = float_to_i754(data, data_w)

    def pack2bs(self, regfile_sz: int = 8) -> int:
        regfile_w = math.ceil(math.log2(regfile_sz))
        rw_tmp = self._rw.value
        addr_tmp = self._addr & ((1 << regfile_w) - 1)
        data_tmp = self._data & ((1 << self._data_w) - 1)
        # Pack it up
        result = data_tmp | addr_tmp << self._data_w | rw_tmp << (self._data_w + regfile_w)
        return result