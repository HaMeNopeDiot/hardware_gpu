#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: JAL and JALR instructions core test
# Date: 2026/08
#------------------------------------------------------------------------------#

import cocotb

from core.tests.base_itest  import BaseCoreTest
from core.ahb_slave         import AHBSize

from core.core_op           import CoreOp


from fpu.fppconverter     import float_to_i754, ieee754_to_float

from utility.defines      import VID_ADDR, THREADS_CNT

import numpy as np

class JalTest(BaseCoreTest):
    async def body(self):
        # First thread
        self.load_i(CoreOp.LUI , rd_addr = 1,  imm= 0x00000                    )
        self.load_i(CoreOp.ADDI, rd_addr = 1,  rs1_addr= 1,         imm=4      )
        self.load_i(CoreOp.MUL , rd_addr = 2,  rs1_addr= VID_ADDR,  rs2_addr=1 )
        self.load_i(CoreOp.LUI , rd_addr = 4,  imm=0x2000                      )
        self.load_i(CoreOp.ADDI, rd_addr = 4,  rs1_addr=4, imm=0x067           )
        self.load_i(CoreOp.JAL,  rd_addr = 5,  imm = 0x40                      )
        self.load_i(CoreOp.ADDI, rd_addr = 4,  rs1_addr=4, imm=0x1             )
        self.load_i(CoreOp.ADDI, rd_addr = 4,  rs1_addr=4, imm=0x2             )
        self.load_i(CoreOp.JALR, rd_addr = 6,  rs1_addr=5, imm=0x0             )
        self.load_i(CoreOp.ADDI, rd_addr = 7,  rs1_addr=7, imm=0x3             )
        self.load_i(CoreOp.ADDI, rd_addr = 7,  rs1_addr=7, imm=0x4             )
        self.load_i(CoreOp.SW  , rs1_addr = 2, imm=0x80, rs2_addr=7            )
        self.load_i(CoreOp.SW  , rs1_addr = 2, imm=0x90, rs2_addr=4            )
        self.load_i(CoreOp.RET                                                 )


        await self.launch_program()
        await self.wait_until_done()

        res = []
        reg_byte_num =  (1 << AHBSize.WORD.value)
        for i in range(THREADS_CNT):
            tmp = self.ahb_slave_lsu.read_word(0x80 + i * reg_byte_num)
            res.append(tmp)
            cocotb.log.info(f"{i} result: {tmp:08x}")

        for i in range(THREADS_CNT):
            tmp = self.ahb_slave_lsu.read_word(0x90 + i * reg_byte_num)
            res.append(tmp)
            cocotb.log.info(f"{i} result: {tmp:08x}")