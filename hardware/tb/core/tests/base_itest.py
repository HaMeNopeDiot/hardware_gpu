#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Base core itest
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb
from cocotb.triggers    import Timer, ClockCycles

from core.ahb_slave       import AHBSlaveModel
from core.apb_master      import APB4Master

from utility.defines    import DW

from numbers import Real
from decimal import Decimal
from utility.addresess import CSRAddr

from utility.defines    import CORES_CNT, THREADS_CNT, HZ

async def clock_generator(clk, time: Real | Decimal, unit: str = "step"):
    while True:
        clk.value = 0
        await Timer(time, unit)
        clk.value = 1
        await Timer(time, unit)

async def make_reset(clk, rst_n):
    rst_n.value = 1
    await ClockCycles(clk, 1)
    rst_n.value = 0
    await ClockCycles(clk, 1)
    rst_n.value = 1

class BaseCoreTest:
    def __init__(self, dut, name: str = "test"):
        self.name = name
        self.dut = dut
        self.clk = dut.clk
        self.rst_n = dut.rst_n
        self.ahb_slave_lsu = None
        self.ahb_slave_ftc = None
        self.apb_master_csr = None


    async def prebody(self):
        clk = self.clk
        rst_n = self.rst_n
        dut = self.dut
        cocotb.start_soon(clock_generator(clk, 10, unit="ns"))
        # make reset
        await make_reset(clk, rst_n)

        self.ahb_slave_lsu = AHBSlaveModel(dut,
                                name = "lsu",
                                memory_size=2 ** 32,
                                data_width=DW, log= cocotb.log, wait_states=0)

        self.ahb_slave_ftc = AHBSlaveModel(dut,
                            name = "ftc",
                            memory_size=2 ** 32,
                            data_width=DW, log= cocotb.log, wait_states=0)

        self.apb_master_csr = APB4Master(dut,
                                    prefix = "csr",
                                    clock = dut.clk,
                                    reset = dut.rst_n)

        await self.apb_master_csr.write(CSRAddr.CORE_VID.value       , 0x0, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x4 , 0x1, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x8 , 0x2, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0xC , 0x3, 0b1111)

    async def body(self):
        pass # virtual

    async def postbody(self):
        await ClockCycles(self.clk, 10)
        self.ahb_slave_lsu.stop()
        self.ahb_slave_ftc.stop()

    async def run(self):
        await self.prebody()
        await self.body()
        await self.postbody()

    async def cnt_busy_cycles(self, cnt_instr: int):
        wait_busy = 0
        while (self.dut.busy_o.value == 0):
            await ClockCycles(self.clk, 1)
            wait_busy += 1
            assert wait_busy < 10000, "TIME OUT"

        wait_untill_busy = 0
        while (self.dut.busy_o.value == 1):
            await ClockCycles(self.clk, 1)
            wait_untill_busy += 1
            assert wait_untill_busy < 10000, "TIME OUT"

        assert wait_untill_busy > 2, "no"
        wait_untill_busy -= 2
        # res
        cpi = float(wait_untill_busy / cnt_instr)
        tflops = (HZ * CORES_CNT * (THREADS_CNT * (1 / cpi))) * 1e-12
        cocotb.log.warning(f"WAIT BUSY CYCLES: {wait_untill_busy}")
        cocotb.log.warning(f"Hz / CI: {cpi}")
        cocotb.log.warning(f"MIPS: {HZ / (cpi * 1e+6)}")
        cocotb.log.warning(f"TFLOPS: {tflops}")
