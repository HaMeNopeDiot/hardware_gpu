#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: VKCUBE core test
# Date: 2026/06
#------------------------------------------------------------------------------#

import struct

import cocotb
from cocotb.triggers      import ClockCycles

from core.tests.base_itest  import BaseCoreTest
from core.core_instr_item   import CoreInstItem
from core.ahb_slave         import AHBSize
from core.models.core_model import CoreModel
from core.instr_item        import InstItem
from core.core_enums        import RoundModeE

from core.core_op           import CoreOp

from fpu.fppconverter     import float_to_i754, ieee754_to_float

from utility.bin_unpack   import unpack_bin_file, read_vbuffer
from utility.addresess    import CSRAddr, POSITION_BASE_ADDR
from utility.defines      import VID_ADDR, THREADS_CNT

import numpy as np

class ThreadEnTest(BaseCoreTest):
    async def body(self):

        # First thread
        InstItem(CoreInstItem(CoreOp.LUI , rd_addr=4, imm=0x2000), self.ahb_slave_ftc, 0x4)
        InstItem(CoreInstItem(CoreOp.ADDI, rd_addr=4, rs1_addr=4, imm=0x067), self.ahb_slave_ftc, 0x8)
        InstItem(CoreInstItem(CoreOp.RET), self.ahb_slave_ftc, 0xC)

        cocotb.start_soon(self.cnt_busy_cycles(1))

        await self.apb_master_csr.write(CSRAddr.TU_EN.value    , 0b0001)
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4   )
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1   )

        # wait
        while (self.dut.busy_o.value == 1):
           await ClockCycles(self.clk, 1)


        # Second thread we will skip
        # Third thread
        reg_byte_num =  (1 << AHBSize.WORD.value)
        rng = np.random.default_rng()
        a = []
        for i in range (2):
            random_float = rng.random(dtype=np.float32) * 2
            a.append(random_float)
            self.ahb_slave_lsu.write_word(0x1000 + i * reg_byte_num, float_to_i754(a[i], 32))

        InstItem(CoreInstItem(CoreOp.LUI , rd_addr = 1, imm=0x0000_1), self.ahb_slave_ftc, 0x4)
        InstItem(CoreInstItem(CoreOp.LW  , rs1_addr= 1, rd_addr = 2), self.ahb_slave_ftc, 0x8)
        InstItem(CoreInstItem(CoreOp.LW  , rs1_addr= 1, rd_addr = 3, imm=0x1), self.ahb_slave_ftc, 0xC)
        InstItem(CoreInstItem(CoreOp.ADD , rs1_addr= 2, rs2_addr= 3, rd_addr=4), self.ahb_slave_ftc, 0x10)
        InstItem(CoreInstItem(CoreOp.RET), self.ahb_slave_ftc, 0x14)


        await self.apb_master_csr.write(CSRAddr.TU_EN.value    , 0b0100)
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4   )
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1   )

        # Fourth + Second thread
        InstItem(CoreInstItem(CoreOp.LUI , rd_addr=1, imm=0x11111), self.ahb_slave_ftc, 0x4)
        InstItem(CoreInstItem(CoreOp.ADDI, rd_addr=1, rs1_addr=1, imm=0x267), self.ahb_slave_ftc, 0x8)
        InstItem(CoreInstItem(CoreOp.LUI , rd_addr=2, imm=0x77777), self.ahb_slave_ftc, 0xC)
        InstItem(CoreInstItem(CoreOp.ADDI, rd_addr=2, rs1_addr=2, imm=0x421), self.ahb_slave_ftc, 0x10)
        InstItem(CoreInstItem(CoreOp.ADD,  rs1_addr=1, rs2_addr=2, rd_addr=4), self.ahb_slave_ftc, 0x14)
        InstItem(CoreInstItem(CoreOp.RET), self.ahb_slave_ftc, 0x18)

        await self.apb_master_csr.write(CSRAddr.TU_EN.value    , 0b1010)
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4   )
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1   )

        # unload
        InstItem(CoreInstItem(CoreOp.SW, rs1_addr=VID_ADDR, imm=0x10, rs2_addr=4), self.ahb_slave_ftc, 0x4)
        InstItem(CoreInstItem(CoreOp.RET), self.ahb_slave_ftc, 0x8)

        await self.apb_master_csr.write(CSRAddr.TU_EN.value    , 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4   )
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1   )

        res = []
        for i in range(THREADS_CNT):
            tmp = self.ahb_slave_lsu.read_word(0x10 + i * reg_byte_num)
            res.append(tmp)

        cocotb.log.info(f"Result: {res}")