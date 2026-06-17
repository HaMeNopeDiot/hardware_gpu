# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles

from fpu.fppconverter import ieee754_to_float, float_to_i754

import numpy as np

from numbers import Real
from decimal import Decimal

from core.core_instr_item import CILI, CIFI, CISI, CIUI, CoreInstItem
from core.core_enums      import LoadOpTE, InstTE, StoreOpTE, FPUopTE, UPPopTE, RoundModeE
from core.ahb_slave       import AHBSlaveModel, AHBSize
from core.core_instr_item import VID_ADDR, DW

from core.instr_item      import InstItem

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

async def launch_inst(dut, clk, instr: CoreInstItem, clear=False, id_inst: int = -1, timeout: int = 1000):
    instr_valid_i = dut.instr_valid_i
    instr_i = dut.instr_i
    # set
    await ClockCycles(clk, 1)
    if id_inst == -1:
        cocotb.log.info(f"Start txn...")
    else:
        cocotb.log.info(f"{id_inst}: Start txn...")

    instr_i.value = instr.get_machine_code()
    instr_valid_i.value = 1

    tt = 0
    await Timer(time=1, unit="ns")
    while(dut.decoder_ready_o.value == 0):
        await ClockCycles(clk, 1)
        tt += 1
        if tt >= timeout:
            cocotb.log.error(f"TIME OUT!")
            assert False, f"TIME OUT"
    if clear:
        await clear_instr_i(dut, clk)

async def core_common_test(dut, clk, ahb_slave):
    ahb_slave.write_memory(0x4 * 1 , AHBSize.WORD.value, 0xBA0B_BAAB)
    ahb_slave.write_memory(0x4 * 2 , AHBSize.WORD.value, 0xB00B_1E55)
    ahb_slave.write_memory(0x4 * 3 , AHBSize.WORD.value, 0xDEEA_AAAD)
    ahb_slave.write_memory(0x4 * 4 , AHBSize.WORD.value, 0x1111_2345)

    ahb_slave.write_memory(0x4 * 5 , 2, 0xABAB_BABA)
    ahb_slave.write_memory(0x4 * 6 , 2, 0xE6AA_1110)
    ahb_slave.write_memory(0x4 * 7 , 2, 0xBA5E_2A2A)
    ahb_slave.write_memory(0x4 * 8 , 2, 0x8888_8888)

    ahb_slave.write_memory(0x4 * 9 , 2, 0x5E5E_B0B0)
    ahb_slave.write_memory(0x4 * 10, 2, 0xBEEA_5577)
    ahb_slave.write_memory(0x4 * 11, 2, 0xBEC0_E669)
    ahb_slave.write_memory(0x4 * 12, 2, 0x6767_6767)

    i1 = CIUI(op=UPPopTE.LUI,   imm = 0xABCDE, rd_addr = 1)
    i2 = CILI(op=LoadOpTE.ADDI, imm = 0xF12,   rd_addr = 1, rs1_addr = 1)
    i3 = CISI(op=StoreOpTE.ADD, imm = 0x99,    rd_addr = 2, rs1_addr = 1, rs2_addr=  VID_ADDR)

    i4 = CILI(op=LoadOpTE.ADDI, imm = 0x4,    rd_addr = 3, rs1_addr = 4)
    i5 = CISI(op=StoreOpTE.MUL, imm = 0x4,    rd_addr = 4, rs1_addr = 3, rs2_addr=  VID_ADDR)
    i6 = CILI(op=LoadOpTE.LW,   imm = 0x4,    rd_addr = 5, rs1_addr = 4)
    i7 = CILI(op=LoadOpTE.LW,   imm = 0x14,   rd_addr = 6, rs1_addr = 4)
    i8 = CILI(op=LoadOpTE.LW,   imm = 0x24,   rd_addr = 7, rs1_addr = 4)
    i9 = CISI(op=StoreOpTE.SW,  imm = 0x10,   rd_addr = 1, rs1_addr = 4, rs2_addr = 5)

    await launch_inst(dut, clk, i1, id_inst = 1)
    await launch_inst(dut, clk, i2, id_inst = 2)
    await launch_inst(dut, clk, i3, id_inst = 3)
    await launch_inst(dut, clk, i4, id_inst = 4)
    await launch_inst(dut, clk, i5, id_inst = 5)
    await launch_inst(dut, clk, i6, id_inst = 6)
    await launch_inst(dut, clk, i7, id_inst = 7)
    await launch_inst(dut, clk, i8, id_inst = 8)
    await launch_inst(dut, clk, i9, id_inst = 9)
    await clear_instr_i(dut, clk)

    await ClockCycles(clk, 100)
    assert 0xBA0B_BAAB == ahb_slave.read_memory(0x10 + 0x4 * 0, AHBSize.WORD.value), f"Fail"
    assert 0xB00B_1E55 == ahb_slave.read_memory(0x10 + 0x4 * 1, AHBSize.WORD.value), f"Fail"
    assert 0xDEEA_AAAD == ahb_slave.read_memory(0x10 + 0x4 * 2, AHBSize.WORD.value), f"Fail"
    assert 0x1111_2345 == ahb_slave.read_memory(0x10 + 0x4 * 3, AHBSize.WORD.value), f"Fail"


async def fpu_core_test(dut, clk, ahb_slave, ahb_slave_ftc, fpu_op: FPUopTE):
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
    cocotb.log.info(f"a: {a}; b: {b}")

    # load constants in memory
    ahb_size   = AHBSize.WORD.value
    elem_ofs    = 1 << ahb_size
    for i in range(4):
        a_tmp = float_to_i754(a[i], 32)
        b_tmp = float_to_i754(b[i], 32)
        ahb_slave.write_memory((i * elem_ofs)         , ahb_size, a_tmp)
        ahb_slave.write_memory((i * elem_ofs) + (0x10), ahb_size, b_tmp)


    # form instructions: get constants/ calculate / give result
    ipc1 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0x04,   rd_addr = 1, rs1_addr = 0), ahb_slave_ftc, 0x04)
    ipc2 = InstItem(CISI(op=StoreOpTE.MUL, imm = 0x0D,   rd_addr = 2, rs1_addr = 1, rs2_addr=  VID_ADDR), ahb_slave_ftc, 0x08)
    ipc3 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x00,   rd_addr = 3, rs1_addr = 2), ahb_slave_ftc, 0x0C)
    ipc4 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x10,   rd_addr = 4, rs1_addr = 2), ahb_slave_ftc, 0x10)
    ipc5 = InstItem(CIFI(op=fpu_op,        imm = 0x00,
                                           arg1_addr = 3,
                                           arg2_addr = 4,
                                           arg3_addr = 1,
                                           argr_addr = 5,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x14)
    ipc6 = InstItem(CISI(op=StoreOpTE.SW,  imm = 0x20,   rd_addr = 1, rs1_addr = 2, rs2_addr = 5), ahb_slave_ftc, 0x18)


    # execute instructions
    await ipc1.load_instr(clk, dut)
    await ipc2.load_instr(clk, dut)
    await ipc3.load_instr(clk, dut)
    await ipc4.load_instr(clk, dut)
    await ipc5.load_instr(clk, dut)
    await ipc6.load_instr(clk, dut)

    await ClockCycles(clk, 1)
    dut.pc_i.value = 0x0000
    dut.en_i.value = 0

    await ClockCycles(clk, 100)
    # get values
    res = []
    cocotb.log.info(f"READ MEM")
    for i in range(4):
        r_tmp = ahb_slave.read_memory(0x20 + 0x4 * i, ahb_size)
        print(r_tmp)
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
        cocotb.log.info(f"{i}: {eps_real}")
        assert eps_real < eps, f"Uncorrect answer"

async def core_test(dut):
    """Try accessing the design."""
    clk = dut.clk
    rst_n = dut.rst_n
    # clk launch
    cocotb.start_soon(clock_generator(clk, 10, unit="ns"))
    # make reset
    await make_reset(clk, rst_n)


    ahb_slave_lsu = AHBSlaveModel(dut,
                              name = "lsu",
                              memory_size=2 ** 16,
                              data_width=DW, log= cocotb.log, wait_states=2)

    ahb_slave_ftc = AHBSlaveModel(dut,
                          name = "ftc",
                          memory_size=2 ** 16,
                          data_width=DW, log= cocotb.log, wait_states=2)


    # ipc1 = InstItem(CIUI(op=UPPopTE.LUI,   imm = 0xABCDE, rd_addr = 1),                 ahb_slave_ftc, 0x04)
    # ipc2 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0xF12,   rd_addr = 1, rs1_addr = 1),   ahb_slave_ftc, 0x08)
    # await ClockCycles(clk, 30)

    # await ipc1.load_instr(clk, dut)
    # await ipc2.load_instr(clk, dut)


    # dut.pc_i.value = 0x0000
    # dut.en_i.value = 0

    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.ADD)
    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.MUL)
    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.DIV)
    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.SQRT)
    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.NEG)
    await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.MAX)

    await ClockCycles(clk, 30)
    ahb_slave_ftc.stop()
    ahb_slave_lsu.stop()


