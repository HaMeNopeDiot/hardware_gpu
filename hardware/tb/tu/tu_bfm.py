# --------------------------------------------------------------
#  tu_bfm.py
# --------------------------------------------------------------
from pyuvm import utility_classes

from tu.tu_item import TUCmdItem, Lsu2TUCmdItem
from cocotb.triggers import ClockCycles

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
        self.busy_o         = getattr(dut, "busy_o")

        self.WIDTH        = int(len(self.data_o)) # битность результата
        self.REGFILE_SIZE = 8                     # fixme
        self.TAG_SIZE     = 8                     # fixme
        self.DATA_W       = 64                    # fixme

    def drive_idle(self):
        self.lsu_cmd.value        = 0
        self.lsu_cmd_active.value = 0
        self.dec_cmd.value        = 0
        self.dec_cmd_active.value = 0


    async def drive_dec_cmd(self, dec_cmd: TUCmdItem):
        bs = dec_cmd.pack2bs(self.REGFILE_SIZE, self.TAG_SIZE)
        self.dec_cmd.value = bs
        self.dec_cmd_active.value = 1
        await ClockCycles(self.clk, 1)
        # await ClockCycles(self.clk, 1)
        self.dec_cmd_active.value = 0
        self.dec_cmd.value = 0
        # await ClockCycles(self.clk, 1)

    async def drive_lsu_cmd(self, lsu_cmd: Lsu2TUCmdItem):
        bs = lsu_cmd.pack2bs(self.REGFILE_SIZE)
        self.lsu_cmd.value = bs
        self.lsu_cmd_active.value = 1
        await ClockCycles(self.clk, 1)
        self.lsu_cmd_active.value = 0
        self.lsu_cmd.value = 0
        # await ClockCycles(self.clk, 1)
