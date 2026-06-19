# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu.fppconverter import ieee754_to_float

from numbers import Real
from decimal import Decimal

from tu.tu_bfm import ThreadUnitBfm
from tu.tu_item import TUCmdItem, Lsu2TUCmdItem

from utility.enums import DirectionE, OperationE

def print_result(result):
    cocotb.log.info(result)
    res = hex(result["result"])
    if result["result"] != 0:
        if len(res) - 2 < 16:
            res = "0x" + (16 + 2 - len(res)) * "0" + res[2:]
        cocotb.log.info(f"TRY TO SEND HEX: {res}")
        cocotb.log.info(f"RESULT: {(ieee754_to_float(res[2:], 64))}")


async def clock_generator(clk, time: Real | Decimal, unit: str = "step"):
    while True:
        clk.value = 0
        await Timer(time, unit)
        clk.value = 1
        await Timer(time, unit)

async def make_reset(clk, rst_n):
    rst_n.value = 1
    await ClockCycles(clk, 1)
    rst_n.value = 0
    await ClockCycles(clk, 1)
    rst_n.value = 1

async def tu_test(dut):
    """Try accessing the design."""
    clk = dut.clk
    rst_n = dut.rst_n
    # clk launch
    cocotb.start_soon(clock_generator(clk, 10, unit="ns"))
    # make reset
    await make_reset(clk, rst_n)

    tu_bfm = ThreadUnitBfm(dut, "clk", "rst_n")

    tu_bfm.drive_idle()
    await ClockCycles(clk, 10)

    lsu_i1 = Lsu2TUCmdItem(DirectionE.WRITE, 1, 3)
    lsu_i2 = Lsu2TUCmdItem(DirectionE.WRITE, 2, 2)
    lsu_i3 = Lsu2TUCmdItem(DirectionE.WRITE, 3, 16)

    await tu_bfm.drive_lsu_cmd(lsu_i1)
    await tu_bfm.drive_lsu_cmd(lsu_i2)
    await tu_bfm.drive_lsu_cmd(lsu_i3)

    await ClockCycles(clk, 1)

    # First txn
    await tu_bfm.drive_dec_cmd(TUCmdItem([1, 2, 3], 4, OperationE.SQRT, tag=1))

    await ClockCycles(clk, 20)

    await tu_bfm.drive_lsu_cmd(Lsu2TUCmdItem(DirectionE.READ, 4))
    data = ieee754_to_float(hex(tu_bfm.data_o.value), 64)
    await ClockCycles(clk, 10)
    cocotb.log.info(f"data: {data}")

    # Second txn
    await tu_bfm.drive_dec_cmd(TUCmdItem([4, 2, 3], 5, OperationE.ADD, tag=2))

    await tu_bfm.drive_lsu_cmd(Lsu2TUCmdItem(DirectionE.READ, 5))
    data = ieee754_to_float(hex(tu_bfm.data_o.value), 64)
    await ClockCycles(clk, 10)
    cocotb.log.info(f"data: {data}")

    # Third txn
    await tu_bfm.drive_lsu_cmd(Lsu2TUCmdItem(DirectionE.WRITE, 1, 7))
    await tu_bfm.drive_dec_cmd(TUCmdItem([1, 2, 3], 4, OperationE.DIV, tag=3))

    while tu_bfm.busy_o.value == 1:
        await ClockCycles(clk, 1)

    await ClockCycles(clk, 10)
    await tu_bfm.drive_lsu_cmd(Lsu2TUCmdItem(DirectionE.READ, 4))
    data = ieee754_to_float(hex(tu_bfm.data_o.value), 64)


    await ClockCycles(clk, 30)
    cocotb.log.info(f"data: {data}")


