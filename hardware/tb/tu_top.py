# test_my_design.py (simple)

import cocotb

from fpu.fpnew_top import fpu_test
from tu.tu_top  import tu_test


@cocotb.test()
async def my_first_test(dut):
    # await fpu_test(dut)
    await tu_test(dut)