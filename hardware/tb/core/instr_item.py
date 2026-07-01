#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Instruction Item For Fetcher
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb

from cocotb.triggers    import Timer, ClockCycles

from core.core_instr_item   import CoreInstItem
from core.ahb_slave         import AHBSlaveModel, AHBSize

DEF_AHB_SZ = AHBSize.WORD

class InstItem():
    def __init__(self,
                 instr: CoreInstItem,
                 ahb_slave_model: AHBSlaveModel,
                 addr: int):
        self.addr = addr
        self.instr = instr
        self.ahb_sm = ahb_slave_model
        cocotb.log.debug(f"instr: 0x{instr.get_machine_code():08x} to addr: {addr:08x}")
        self.ahb_sm.write_memory(addr, DEF_AHB_SZ, instr.get_machine_code())

    async def load_instr(self, clk, dut):
        dut.pc_i.value = self.addr
        dut.en_i.value = 1
        await Timer(1, unit="ns")
        tt = 0
        while(dut.pc_readed_o.value == 0):
            cocotb.log.info(f"{self.addr}: try to catch")
            await ClockCycles(clk, 1)
            await Timer(1, unit="ns")
            tt += 1
            assert tt < 1000, f"Time out in load instr"
        cocotb.log.info(f"{self.addr}: catched")

        await ClockCycles(clk, 1)


