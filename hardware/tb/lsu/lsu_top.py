# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu.fppconverter import ieee754_to_float

from numbers import Real
from decimal import Decimal

from core.ahb_slave       import AHBSlaveModel

from core.core_instr_item import VID_ADDR, DW

from lsu.lsu_enum   import LSUOpE


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


async def core_test(dut):
    """Try accessing the design."""
    clk = dut.clk
    rst_n = dut.rst_n
    # clk launch
    cocotb.start_soon(clock_generator(clk, 10, unit="ns"))
    # make reset
    await make_reset(clk, rst_n)

    await ClockCycles(clk, 30)

    ahb_slave = AHBSlaveModel(dut,
                              name = "",
                              memory_size=2 ** 16,
                              data_width=DW, log= cocotb.log, wait_states=2)

    ahb_slave.write_memory(0x124, 2, 0xBA0B_BAAB)

    dut.lsu_op.value            = LSUOpE.LOAD.value
    dut.lsu_op_valid.value      = 1
    dut.threads_req_done.value  = 0
    dut.lsu_valid_i.value       = 1

    dut.rs1_valid.value         = 1
    dut.rs2_valid.value         = 1
    dut.rs1.value               = 0x10
    dut.rs2.value               = 0x20

    await ClockCycles(clk, 30)
    ahb_slave.stop()




