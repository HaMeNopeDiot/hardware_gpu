# test_my_design.py (simple)

import cocotb

from fpu.fpnew_top import fpu_test
from tu.tu_top  import tu_test

from core.core_top import   ISACheckTest, \
                            FPUCheckADDTest, \
                            FPUCheckMULTest, \
                            FPUCheckDIVTest, \
                            FPUCheckSQRTTest, \
                            FPUCheckNEGTest, \
                            FPUCheckMAXTest, \
                            VKCubeTest

#@cocotb.test()
async def isa_test(dut):
    await ISACheckTest(dut, "isa_test").run()


#@cocotb.test()
async def fpu_add_test(dut):
    await FPUCheckADDTest(dut, "fpu_add_test").run()

#@cocotb.test()
async def fpu_mul_test(dut):
    await FPUCheckMULTest(dut, "fpu_mul_test").run()

#@cocotb.test()
async def fpu_div_test(dut):
    await FPUCheckDIVTest(dut, "fpu_div_test").run()

#@cocotb.test()
async def fpu_sqrt_test(dut):
    await FPUCheckSQRTTest(dut, "fpu_sqrt_test").run()

#@cocotb.test()
async def fpu_neg_test(dut):
    await FPUCheckNEGTest(dut, "fpu_neg_test").run()

#@cocotb.test()
async def fpu_max_test(dut):
    await FPUCheckMAXTest(dut, "fpu_max_test").run()

@cocotb.test()
async def vkcube(dut):
    await VKCubeTest(dut, "vkcube_test").run()