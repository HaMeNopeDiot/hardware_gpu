#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: FPU core test
# Date: 2026/06
#------------------------------------------------------------------------------#

from core.tests.base_itest  import BaseCoreTest
import cocotb
from cocotb.triggers      import ClockCycles
import numpy as np

from core.core_enums      import LoadOpTE, StoreOpTE, FPUopTE, UPPopTE, RoundModeE
from core.core_instr_item import CILI, CIFI, CISI, CIUI
from core.instr_item      import InstItem
from core.ahb_slave       import AHBSize
from fpu.fppconverter import ieee754_to_float, float_to_i754
from utility.addresess    import CSRAddr
from utility.defines      import VID_ADDR

class FPUCoreTest(BaseCoreTest):
    async def body(self):
        pass

    async def fpu_core_test(self, fpu_op: FPUopTE):
        cocotb.log.info(f"START TESTING CORE FPU")

        # Initialize the generator
        rng = np.random.default_rng()

        # Generate a single float32 between 0 and 100
        # rng.random() yields [0.0, 1.0), which is scaled by multiplying by 100
        a = []
        b = []
        for i in range (4):
            random_float = rng.random(dtype=np.float32) * 10
            a.append(random_float)

        for i in range (4):
            random_float = rng.random(dtype=np.float32) * 10
            b.append(random_float)

        # float
        # a = [2.3, 2.5, 2.7, 2.9]
        # b = [3.6, 3.5, 3.3, 3.2]
        cocotb.log.debug(f"Arguments: arg1: {a}; arg2: {b}")

        # load constants in memory
        ahb_size   = AHBSize.WORD.value
        elem_ofs    = 1 << ahb_size
        for i in range(4):
            a_tmp = float_to_i754(a[i], 32)
            b_tmp = float_to_i754(b[i], 32)
            self.ahb_slave_lsu.write_memory((i * elem_ofs)         , ahb_size, a_tmp)
            self.ahb_slave_lsu.write_memory((i * elem_ofs) + (0x10), ahb_size, b_tmp)


        # form instructions: get constants/ calculate / give result
        ipc1 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0x04,   rd_addr = 1, rs1_addr = 0), self.ahb_slave_ftc, 0x04)
        ipc2 = InstItem(CISI(op=StoreOpTE.MUL, imm = 0x0D,   rd_addr = 2, rs1_addr = 1, rs2_addr=  VID_ADDR), self.ahb_slave_ftc, 0x08)
        ipc3 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x00,   rd_addr = 3, rs1_addr = 2), self.ahb_slave_ftc, 0x0C)
        ipc4 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x10,   rd_addr = 4, rs1_addr = 2), self.ahb_slave_ftc, 0x10)
        ipc5 = InstItem(CIFI(op=fpu_op,        imm = 0x00,
                                            arg1_addr = 3,
                                            arg2_addr = 4,
                                            arg3_addr = 1,
                                            argr_addr = 5,
                                            extra=RoundModeE.RTZ.value), self.ahb_slave_ftc, 0x14)
        ipc6 = InstItem(CISI(op=StoreOpTE.SW,  imm = 0x20,   rd_addr = 1, rs1_addr = 2, rs2_addr = 5), self.ahb_slave_ftc, 0x18)
        ret0 = InstItem(CIUI(op=UPPopTE.RET,   imm = 0x00,    rd_addr = 0),                 self.ahb_slave_ftc, 0x1C)


        # execute instructions
        cocotb.start_soon(self.cnt_busy_cycles(7))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)


        while (self.dut.busy_o.value == 1):
            await ClockCycles(self.clk, 1)
        # get values
        res = []
        cocotb.log.info(f"READ MEM")
        for i in range(4):
            r_addr = 0x20 + 0x4 * i
            r_tmp = self.ahb_slave_lsu.read_memory(r_addr, ahb_size)
            cocotb.log.info(f"- A: {hex(r_addr)}; D: {r_tmp}")
            # print(r_tmp)
            r_val = ieee754_to_float(hex(r_tmp), 32)
            res.append(r_val)

        cocotb.log.info(f"RESULT FPU: {res}")

        eps     = 1e-5

        for i in range(4):
            res_exp = a[i] + b[i]
            match fpu_op:
                case FPUopTE.ADD:
                    res_exp = a[i] + b[i]
                case FPUopTE.MUL:
                    res_exp = a[i] * b[i]
                case FPUopTE.DIV:
                    res_exp = a[i] / b[i]
                case FPUopTE.SQRT:
                    res_exp = np.sqrt(a[i])
                case FPUopTE.NEG:
                    res_exp = - a[i]
                case FPUopTE.MAX:
                    res_exp = max(a[i], b[i])
            eps_real = abs(res[i] - (res_exp))
            cocotb.log.debug(f"ESP for {i} THREAD: {eps_real}")
            assert eps_real < eps, f"Uncorrect answer: {a[i]} op {b[i]} = {res[i]} <> {res_exp}"

class FPUCheckADDTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.ADD)

class FPUCheckMULTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.MUL)

class FPUCheckDIVTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.DIV)

class FPUCheckSQRTTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.SQRT)

class FPUCheckNEGTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.NEG)

class FPUCheckMAXTest(FPUCoreTest):
    async def body(self):
        await self.fpu_core_test(FPUopTE.MAX)
