#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Base core itest
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb
from cocotb.triggers            import Timer, ClockCycles

from core.ahb_slave             import AHBSlaveModel
from core.ahb_slave             import AHBSize
from core.apb_master            import APB4Master
from core.models.core_model     import CoreModel
from core.models.regfile_model  import RegfileModel

from utility.defines    import DW

from numbers import Real
from decimal import Decimal
from utility.addresess import CSRAddr

from utility.defines    import CORES_CNT, THREADS_CNT, HZ, REGFILE_SZ

from core.core_op   import CoreOp
from core.inst_sheduler     import InstSheduler

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
        self.ahb_slave_lsu  = None
        self.ahb_slave_ftc  = None
        self.apb_master_csr = None
        self.inst_sheduler  = InstSheduler(name="sheduler")
        self.core_model     = CoreModel(name="core")

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

        self.inst_sheduler.if_slave_model = self.ahb_slave_ftc

        await self.apb_master_csr.write(CSRAddr.TU_EN.value             , 0b1111, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value          , 0x0   , 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x4    , 0x1   , 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x8    , 0x2   , 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0xC    , 0x3   , 0b1111)

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

    async def unload_all_regfiles(self, iaddr):
        # dump from regfiles to memory
        jcell = (1 << AHBSize.WORD.value)
        self.inst_sheduler.cur_start_pc = iaddr
        for thread_idx in range(THREADS_CNT):
            thread_ofs = thread_idx * (REGFILE_SZ + 1)
            pc_start_addr = iaddr + thread_ofs * jcell
            cocotb.log.debug(f"Make thread-{thread_idx} instructions with {pc_start_addr:08x} offset")
            for reg_idx in range(REGFILE_SZ):
                addr_ofs = (thread_ofs + reg_idx) * jcell
                self.load_i(op=CoreOp.SW, imm = addr_ofs, rs2_addr = reg_idx)
                cocotb.log.debug(f"Sended instruction for {reg_idx}-reg by {(iaddr + addr_ofs):08x} address")

            self.load_i(op=CoreOp.RET)
            cocotb.log.debug(f"Sended instruction EoP by {(iaddr + addr_ofs + jcell):08x} address")

            thread_en_mask = 1 << thread_idx
            cocotb.log.debug(f"thread_en_mask: {thread_en_mask}")
            await self.launch_program(thread_en_mask)
            await self.wait_until_done()

        # load dump from memory
        regfiles: list[RegfileModel] = []
        for thread_idx in range(THREADS_CNT):
            regfile = RegfileModel(name = f"regfile-{thread_idx}")
            cocotb.log.debug(f"THREAD: {thread_idx}")
            thread_ofs = thread_idx * (REGFILE_SZ + 1)
            for reg_idx in range(REGFILE_SZ):
                addr_ofs = (thread_ofs + reg_idx) * jcell
                cocotb.log.debug(f"addr_ofs: {addr_ofs:08x}")
                reg_data = self.ahb_slave_lsu.read_word(addr_ofs)
                regfile.write(reg_idx, reg_data, force=True)
            regfiles.append(regfile)

        cocotb.log.info(f"Readed regfiles from threads:")
        for regfile in regfiles:
            regfile.print()
        cocotb.log.info(f"Readed regfiles from core:")
        self.core_model.print()

        for i in range(THREADS_CNT):
            rf     = regfiles[i]
            thread = self.core_model._threads[i]
            for j in range(REGFILE_SZ):
                rfdata = thread._regfile.read(j)
                tdata = thread.read_regfile(j)
                is_equal = tdata == rfdata
                if not is_equal:
                    cocotb.log.warning(f"Error on {j} index in {i} thread index. {rfdata:08x} <> {tdata:08x}")

    async def launch_program(self, thread_en_mask: int = (1 << THREADS_CNT) - 1, custom_pc: int = -1):
        if custom_pc < 0:
            pc = self.inst_sheduler.get_start_pc()
        else:
            pc = custom_pc
        len_inst = self.inst_sheduler.get_prog_len()
        cocotb.start_soon(self.cnt_busy_cycles(len_inst))
        await self.apb_master_csr.write(CSRAddr.TU_EN.value    , thread_en_mask)
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , pc             )
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1            )

    async def wait_until_done(self):
        # wait
        cocotb.log.info(f"Start to capture end of programm")
        while (self.dut.busy_o.value == 1):
           await ClockCycles(self.clk, 1)
        cocotb.log.info(f"Stop to capture end of programm")

    def load_i(self,
                     op            : CoreOp = None,
                     rs1_addr      : int = 0,
                     rs2_addr      : int = 0,
                     rs3_addr      : int = 0,
                     rd_addr       : int = 0,
                     imm           : int = 0,
                     extra         : int = 0,
                     auto_load_prog: bool = True):
        self.inst_sheduler.load_i (op = op,
                                   rs1_addr = rs1_addr,
                                   rs2_addr = rs2_addr,
                                   rs3_addr = rs3_addr,
                                   rd_addr  = rd_addr,
                                   imm = imm,
                                   extra = extra,
                                   auto_load_prog = auto_load_prog)