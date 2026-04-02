# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu_bfm import FPUBfm, OpEnum
from fppconverter import float_to_ieee754, ieee754_to_float, float_to_i754

from numbers import Real
from decimal import Decimal

async def clock_generator(clk, time: Real | Decimal, unit: str = "step"):
    while True:
        clk.value = 0
        await Timer(time, unit)
        clk.value = 1
        await Timer(time, unit)

@cocotb.test()
async def my_first_test(dut):
    """Try accessing the design."""
    clk = dut.clk_i
    rst_n = dut.rst_ni
    cocotb.start_soon(clock_generator(clk, 10, unit="ns"))

    rst_n.value = 1
    await ClockCycles(clk, 1)
    rst_n.value = 0
    await ClockCycles(clk, 1)
    rst_n.value = 1


    fpu_bfm = FPUBfm(dut)
    fpu_bfm.drive_idle()

    operands = [float_to_i754(3, 64),
                float_to_i754(7, 64),
                float_to_i754(-3, 64)]

    # await fpu_bfm.drive_operands(operands)
    result: dict = await fpu_bfm.transaction(operands = operands,
                                             op_code = OpEnum.DIV.value,
                                            src_fmt = 1,
                                            int_fmt = 1,
                                            dst_fmt = 0x1)
    cocotb.log.info(result)
    res = hex(result["result"])
    if result["result"] != 0:
        if len(res) - 2 < 16:
            res = "0x" + (16 + 2 - len(res)) * "0" + res[2:]
        cocotb.log.info(f"TRY TO SEND HEX: {res}")
        cocotb.log.info(f"RESULT: {(ieee754_to_float(res[2:], 64))}")

    await Timer(1000, unit="ns")
