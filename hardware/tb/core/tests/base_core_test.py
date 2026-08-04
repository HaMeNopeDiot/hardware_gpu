#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Base core test
# Date: 2026/06
#------------------------------------------------------------------------------#

import cocotb
import numpy as np

from core.tests.base_itest  import BaseCoreTest
from fpu.fppconverter import hex_ieee754_to_float, float_to_i754

from core.core_enums      import RoundModeE
from utility.defines      import VID_ADDR

from core.ahb_slave       import AHBSize

from core.core_enums import CoreOp

class ISACheckTest(BaseCoreTest):
    async def do_all_i(self): # 20.3
        # fill mem
        rng = np.random.default_rng()
        a = []
        for i in range (4):
            random_float = rng.random(dtype=np.float32) * 2
            a.append(random_float)

        for i in range (4):
            self.ahb_slave_lsu.write_memory(0x1020 + i * (1 << 2), 2, float_to_i754(a[i], 32))


        # form inst
        self.load_i(op=CoreOp.ADDI, imm = 0x004  , rd_addr = 30, rs1_addr = 30                     )
        self.load_i(op=CoreOp.LUI , imm = 0x00001, rd_addr = 1                                     )
        self.load_i(op=CoreOp.ADDI, imm = 0x020  , rd_addr = 1,  rs1_addr = 1                      )
        self.load_i(op=CoreOp.MUL , imm = 0x0D   , rd_addr = 9,  rs1_addr = 30, rs2_addr = VID_ADDR)
        self.load_i(op=CoreOp.ADD , imm = 0x0D   , rd_addr = 10, rs1_addr = 9,  rs2_addr = 1       )
        self.load_i(op=CoreOp.LW  , imm = 0x00   , rd_addr = 2,  rs1_addr = 10                     )
        self.load_i(op=CoreOp.FADD, imm = 0x00   ,
                                            rs1_addr = 2,
                                            rs2_addr = 0,
                                            rs3_addr = 0,
                                            rd_addr  = 3,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.FMUL, imm = 0x00,
                                            rs1_addr = 2,
                                            rs2_addr = 3,
                                            rs3_addr = 0,
                                            rd_addr = 4,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.FDIV,   imm = 0x00,
                                            rs1_addr = 4,
                                            rs2_addr = 3,
                                            rs3_addr = 0,
                                            rd_addr  = 5,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.FSQRT,  imm = 0x00,
                                            rs1_addr = 2,
                                            rs2_addr = 1,
                                            rs3_addr = 4,
                                            rd_addr  = 6,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.FNEG,   imm = 0x00,
                                            rs1_addr = 6,
                                            rs2_addr = 1,
                                            rs3_addr = 1,
                                            rd_addr  = 7,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.FMAX,   imm = 0x00,
                                            rs1_addr = 5,
                                            rs2_addr = 6,
                                            rs3_addr = 0,
                                            rd_addr  = 8,
                                            extra=RoundModeE.RTZ.value)
        self.load_i(CoreOp.SW,  imm = 0x40,   rd_addr = 0,  rs1_addr = 10, rs2_addr = 6)
        self.load_i(CoreOp.RET, imm = 0x00,   rd_addr = 0)

        # do
        await self.launch_program()
        await self.wait_until_done()

        ifpu = []
        for i in range(6):
            itmp = self.load_i(CoreOp.SW,
                                imm = 0x60 + i * 16, # 4 threads with WORD Size of offset (4 * 4)
                                rd_addr = 0, # not used
                                rs1_addr = 10,
                                rs2_addr = 3 + i)
            ifpu.append(itmp)
        self.load_i(CoreOp.RET,   imm = 0x00,    rd_addr = 0)


        await self.launch_program()
        await self.wait_until_done()

        r_fpu_res = []
        for i in range(6):
            r_fpu = []
            for j in range(4):
                r_addr = 0x1080 + ((i * 4) + j) * (1 << 2)
                r_tmp = self.ahb_slave_lsu.read_memory(r_addr, AHBSize.WORD.value)
                cocotb.log.info(f"- A: {hex(r_addr)}; D: {r_tmp}")
                r_val = hex_ieee754_to_float(hex(r_tmp), 32)
                r_fpu.append(r_val)
            r_fpu_res.append(r_fpu)

        # check results
        r_fpu_add  = r_fpu_res[0]
        r_fpu_mul  = r_fpu_res[1]
        r_fpu_div  = r_fpu_res[2]
        r_fpu_sqrt = r_fpu_res[3]
        r_fpu_neg  = r_fpu_res[4]
        r_fpu_max  = r_fpu_res[5]

        eps = 1e-5
        for i in range(4):
            assert abs(a[i]                         - r_fpu_add[i] ) < eps, "ADD FPU RES not match"
            assert abs(a[i] * a[i]                  - r_fpu_mul[i] ) < eps, "MUL FPU RES not match"
            assert abs(a[i]                         - r_fpu_div[i] ) < eps, "DIV FPU RES not match"
            assert abs(np.sqrt(a[i])                - r_fpu_sqrt[i]) < eps, "SQRT FPU RES not match"
            assert abs(-np.sqrt(a[i])               - r_fpu_neg[i] ) < eps, "NEG FPU RES not match"
            assert abs(max(a[i], np.sqrt(a[i]))     - r_fpu_max[i] ) < eps, "MAX FPU RES not match"


    async def body(self):
        await self.do_all_i()
