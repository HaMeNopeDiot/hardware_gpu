#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: VKCUBE core test
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb

from core.tests.base_itest  import BaseCoreTest
from core.ahb_slave         import AHBSize

from core.core_op           import CoreOp


from fpu.fppconverter     import float_to_i754, ieee754_to_float

from utility.defines      import VID_ADDR, THREADS_CNT

import numpy as np

class ThreadEnTest(BaseCoreTest):
    async def body(self):
        # First thread
        self.inst_sheduler.load_i(CoreOp.LUI , rd_addr=4, imm=0x2000           )
        self.inst_sheduler.load_i(CoreOp.ADDI, rd_addr=4, rs1_addr=4, imm=0x067)
        self.inst_sheduler.load_i(CoreOp.RET                                   )

        await self.launch_programm(thread_en_mask=0b0001)
        await self.wait_until_done()

        # Second thread we will skip
        # Third thread
        reg_byte_num =  (1 << AHBSize.WORD.value)
        rng = np.random.default_rng()
        a = []
        for i in range (2):
            random_float = rng.random(dtype=np.float32) * 2
            a.append(random_float)
            self.ahb_slave_lsu.write_word(0x1000 + i * reg_byte_num, float_to_i754(a[i], 32))

        self.inst_sheduler.load_i(CoreOp.LUI , rd_addr = 1, imm=0x0000_1            )
        self.inst_sheduler.load_i(CoreOp.LW  , rs1_addr= 1, rd_addr = 2             )
        self.inst_sheduler.load_i(CoreOp.LW  , rs1_addr= 1, rd_addr = 3, imm = 0x4  )
        self.inst_sheduler.load_i(CoreOp.FADD, rs1_addr= 2, rs2_addr= 3, rd_addr = 4)
        self.inst_sheduler.load_i(CoreOp.RET                                        )

        await self.launch_programm(thread_en_mask=0b0100)
        await self.wait_until_done()

        # Fourth + Second thread
        self.inst_sheduler.load_i(CoreOp.LUI , rd_addr  = 1, imm      = 0x11111              )
        self.inst_sheduler.load_i(CoreOp.ADDI, rd_addr  = 1, rs1_addr = 1       , imm=0x267  )
        self.inst_sheduler.load_i(CoreOp.LUI , rd_addr  = 2, imm      = 0x77777              )
        self.inst_sheduler.load_i(CoreOp.ADDI, rd_addr  = 2, rs1_addr = 2       , imm=0x421  )
        self.inst_sheduler.load_i(CoreOp.ADD,  rs1_addr = 1, rs2_addr = 2       , rd_addr=4  )
        self.inst_sheduler.load_i(CoreOp.RET                                                 )

        await self.launch_programm(thread_en_mask=0b1010)
        await self.wait_until_done()

        # unload
        self.inst_sheduler.load_i(CoreOp.LUI , rd_addr = 5,         imm= 0x00000             )
        self.inst_sheduler.load_i(CoreOp.ADDI, rs1_addr= 5,         imm=4       , rd_addr=5  )
        self.inst_sheduler.load_i(CoreOp.MUL , rs1_addr= VID_ADDR,  rs2_addr=5  , rd_addr=6  )
        self.inst_sheduler.load_i(CoreOp.SW  , rs1_addr= 6,         imm=0x10    , rs2_addr=4 )
        self.inst_sheduler.load_i(CoreOp.RET                                                 )

        await self.launch_programm()
        await self.wait_until_done()

        res = []
        for i in range(THREADS_CNT):
            tmp = self.ahb_slave_lsu.read_word(0x10 + i * reg_byte_num)
            res.append(tmp)
            cocotb.log.info(f"{i} result: {tmp:08x}")
        assert res[0] == 0x0200_0067, f"data do not match"
        assert res[1] == 0x1111_1267 + 0x7777_7421, f"data do not match"
        assert abs(ieee754_to_float(res[2]))  - (a[0] + a[1]) < 1e-1, f"data do not match"
        assert res[3] == 0x1111_1267 + 0x7777_7421, f"data do not match"