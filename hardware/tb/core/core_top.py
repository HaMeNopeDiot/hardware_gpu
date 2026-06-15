# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu.fppconverter import ieee754_to_float

from numbers import Real
from decimal import Decimal

from core.core_instr_item import CILI, CIFI, CISI, CIUI, CoreInstItem
from core.core_enums      import LoadOpTE, InstTE, StoreOpTE, FPUopTE, UPPopTE
from core.ahb_slave       import AHBSlaveModel
from core.core_instr_item import VID_ADDR, DW

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

async def clear_instr_i(dut, clk):
    instr_valid_i = dut.instr_valid_i
    instr_i = dut.instr_i
    await ClockCycles(clk, 1)
    instr_valid_i.value = 0
    instr_i.value       = 0

async def launch_inst(dut, clk, instr: CoreInstItem, clear=False):
    instr_valid_i = dut.instr_valid_i
    instr_i = dut.instr_i
    # set
    await ClockCycles(clk, 1)
    instr_i.value = instr.get_machine_code()
    instr_valid_i.value = 1
    if clear:
        await clear_instr_i(dut, clk)

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
                              name = "lsu",
                              memory_size=2 ** 16,
                              data_width=DW, log= cocotb.log, wait_states=2)

    ahb_slave.write_memory(0x4 * 1, 2, 0xBA0B_BAAB)
    ahb_slave.write_memory(0x4 * 2, 2, 0xB00B_1E55)
    ahb_slave.write_memory(0x4 * 3, 2, 0xDEEA_AAAD)
    ahb_slave.write_memory(0x4 * 4, 2, 0x1111_2345)

    ahb_slave.write_memory(0x4 * 5, 2, 0xABAB_BABA)
    ahb_slave.write_memory(0x4 * 6, 2, 0xE6AA_1110)
    ahb_slave.write_memory(0x4 * 7, 2, 0xBA5E_2A2A)
    ahb_slave.write_memory(0x4 * 8, 2, 0x8888_8888)

    i1 = CIUI(op=UPPopTE.LUI,   imm = 0xABCDE, rd_addr = 1)
    i2 = CILI(op=LoadOpTE.ADDI, imm = 0xF12,   rd_addr = 1, rs1_addr = 1)
    i3 = CISI(op=StoreOpTE.ADD, imm = 0x99,    rd_addr = 2, rs1_addr = 1, rs2_addr=  VID_ADDR)

    i4 = CILI(op=LoadOpTE.ADDI, imm = 0x4,    rd_addr = 3, rs1_addr = 4)
    i5 = CISI(op=StoreOpTE.MUL, imm = 0x4,    rd_addr = 4, rs1_addr = 3, rs2_addr=  VID_ADDR)
    i6 = CILI(op=LoadOpTE.LW,   imm = 0x4,    rd_addr = 5, rs1_addr = 4)
    i7 = CILI(op=LoadOpTE.LW,   imm = 0x14,   rd_addr = 6, rs1_addr = 4)

    await launch_inst(dut, clk, i1)
    await launch_inst(dut, clk, i2)
    await launch_inst(dut, clk, i3)
    await launch_inst(dut, clk, i4)
    await launch_inst(dut, clk, i5)
    await launch_inst(dut, clk, i6)
    await launch_inst(dut, clk, i7)

    await clear_instr_i(dut, clk)
    await ClockCycles(clk, 80)
    ahb_slave.stop()


