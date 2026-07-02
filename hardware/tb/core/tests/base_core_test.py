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
from core.core_instr_item import CoreInstItem
from core.instr_item      import InstItem
from utility.addresess    import CSRAddr
from utility.defines      import VID_ADDR

from cocotb.triggers      import ClockCycles
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
        ilc0 = InstItem(CoreInstItem(op=CoreOp.ADDI, imm = 0x004  , rd_addr = 30, rs1_addr = 30), self.ahb_slave_ftc, 0x04)
        iuc1 = InstItem(CoreInstItem(op=CoreOp.LUI , imm = 0x00001, rd_addr = 1), self.ahb_slave_ftc, 0x08)
        ilc1 = InstItem(CoreInstItem(op=CoreOp.ADDI, imm = 0x020  , rd_addr = 1, rs1_addr = 1), self.ahb_slave_ftc, 0x0C)
        isc2 = InstItem(CoreInstItem(op=CoreOp.MUL , imm = 0x0D   , rd_addr = 9,  rs1_addr = 30, rs2_addr = VID_ADDR), self.ahb_slave_ftc, 0x10)
        isc1 = InstItem(CoreInstItem(op=CoreOp.ADD , imm = 0x0D   , rd_addr = 10, rs1_addr = 9,  rs2_addr = 1), self.ahb_slave_ftc, 0x14)
        ilc2 = InstItem(CoreInstItem(op=CoreOp.LW  , imm = 0x00   , rd_addr = 2, rs1_addr = 10), self.ahb_slave_ftc, 0x18)
        ifc1 = InstItem(CoreInstItem(op=CoreOp.FADD, imm = 0x00   ,
                                            rs1_addr = 2,
                                            rs2_addr = 0,
                                            rs3_addr = 0,
                                            rd_addr  = 3,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x1C)
        ifc2 = InstItem(CoreInstItem(CoreOp.FMUL,   imm = 0x00,
                                            rs1_addr = 2,
                                            rs2_addr = 3,
                                            rs3_addr = 0,
                                            rd_addr = 4,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x20)
        ifc3 = InstItem(CoreInstItem(CoreOp.FDIV,   imm = 0x00,
                                            rs1_addr = 4,
                                            rs2_addr = 3,
                                            rs3_addr = 0,
                                            rd_addr  = 5,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x24)
        ifc4 = InstItem(CoreInstItem(CoreOp.FSQRT,  imm = 0x00,
                                            rs1_addr = 2,
                                            rs2_addr = 1,
                                            rs3_addr = 4,
                                            rd_addr  = 6,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x28)
        ifc5 = InstItem(CoreInstItem(CoreOp.FNEG,   imm = 0x00,
                                            rs1_addr = 6,
                                            rs2_addr = 1,
                                            rs3_addr = 1,
                                            rd_addr  = 7,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x2C)
        ifc6 = InstItem(CoreInstItem(CoreOp.FMAX,   imm = 0x00,
                                            rs1_addr = 5,
                                            rs2_addr = 6,
                                            rs3_addr = 0,
                                            rd_addr  = 8,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x30)
        isc3 = InstItem(CoreInstItem(CoreOp.SW,  imm = 0x40,   rd_addr = 0,  rs1_addr = 10, rs2_addr = 6), self.ahb_slave_ftc, 0x34)
        ret0 = InstItem(CoreInstItem(CoreOp.RET,   imm = 0x00,    rd_addr = 0), self.ahb_slave_ftc, 0x38)

        ifpu = []
        for i in range(6):
            itmp = InstItem(CoreInstItem(CoreOp.SW,
                                imm = 0x60 + i * 16, # 4 threads with WORD Size of offset (4 * 4)
                                rd_addr = 0, # not used
                                rs1_addr = 10,
                                rs2_addr = 3 + i),
                                self.ahb_slave_ftc, 0x40 + i * 4)
            ifpu.append(itmp)
        ret0 = InstItem(CoreInstItem(CoreOp.RET,   imm = 0x00,    rd_addr = 0), self.ahb_slave_ftc, 0x58)

        # do
        cocotb.start_soon(self.cnt_busy_cycles(14))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4,       0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1,       0b1111)

        while (self.dut.busy_o.value == 1):
            await ClockCycles(self.clk, 1)


        cocotb.start_soon(self.cnt_busy_cycles(7))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x40, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1,  0b1111)


        while (self.dut.busy_o.value == 1):
            await ClockCycles(self.clk, 1)

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
