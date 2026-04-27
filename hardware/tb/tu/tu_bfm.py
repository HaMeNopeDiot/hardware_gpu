# --------------------------------------------------------------
#  tu_bfm.py
# --------------------------------------------------------------
from pyuvm import utility_classes

from tu.tu_item import ThreadUnitCommandItem
from utility.enums  import OperationE, RoundModeE, DirectionE

from enum import Enum
import math

class ThreadUnitBfm(metaclass=utility_classes.Singleton):
    def __init__(self,
                 dut,
                 clk_name: str = "clk_i",
                 rst_name: str = "rst_ni"):
        """
        Параметры
        ----------
        dut        – объект `cocotb.top` (или переданный в тесте `dut`);
        clk_name   – имя сигнала тактовой частоты (по умолчанию «clk_i»);
        rst_name   – имя сигнала активного‑low сброса (по умолчанию «rst_ni»).
        """
        self.dut = dut

        # -------------------  Main signals  --------------------- #
        self.clk            = getattr(dut, clk_name)
        self.rst_n          = getattr(dut, rst_name)

        # ------------------  Input signals   -------------------- #
        self.lsu_cmd        = getattr(dut, "lsu_cmd")
        self.lsu_cmd_active = getattr(dut, "lsu_cmd_active")
        self.dec_cmd        = getattr(dut, "dec_cmd")
        self.dec_cmd_active = getattr(dut, "dec_cmd_active")
        # ------------------  Output signals  -------------------- #
        self.data_o         = getattr(dut, "data_o")
        self.valid_out      = getattr(dut, "valid_o")
        self.thread_info    = getattr(dut, "thread_info")

        self.WIDTH        = int(len(self.data_o)) # битность результата
        self.REGFILE_SIZE = 8                     # fixme
        self.TAG_SIZE     = 4                     # fixme

    def drive_idle(self):
        self.lsu_cmd.value        = 0
        self.lsu_cmd_active.value = 0
        self.dec_cmd.value        = 0
        self.dec_cmd_active.value = 0

    def get_mask_by_enum(self, enum: Enum) -> int:
        width = math.ceil(math.log2(max(enum)))
        return (1 << width) - 1


    def drive_dec_cmd(self, dec_cmd: ThreadUnitCommandItem):
        op_code_tmp = dec_cmd._op_code.value & self.get_mask_by_enum(OperationE)
        op_mode_tmp = dec_cmd._op_mod & 0b1
        # addreses
        addr_mask = (1 << self.REGFILE_SIZE) - 1
        addr_f_l = []
        for i in range(len(dec_cmd._op_addr)):
            addr_f_l.append(dec_cmd._op_addr[i] & addr_mask)
        addr_f_tmp = (addr_f_l[0] << self.REGFILE_SIZE) | (addr_f_l[1] << self.REGFILE_SIZE * 2) | (addr_f_l[2])
        addr_r_tmp = dec_cmd._res_addr & (1 << self.REGFILE_SIZE) - 1
        tag_tmp = dec_cmd._tag & (1 << self.TAG_SIZE) - 1
        rnd_tmp = dec_cmd._rnd_mode.value & self.get_mask_by_enum(RoundModeE)
        # Pack all
        result = 0
