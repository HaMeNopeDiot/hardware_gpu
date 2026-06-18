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
from core.apb_master      import APB4Master
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

async def fpu_core_test(dut, clk, ahb_slave, ahb_slave_ftc, fpu_op: FPUopTE):
    cocotb.log.info(f"START TESTING CORE FPU")

    # Initialize the generator
    rng = np.random.default_rng()

    # Generate a single float32 between 0 and 100
    # rng.random() yields [0.0, 1.0), which is scaled by multiplying by 100
    a = []
    b = []
    for i in range (4):
        random_float = rng.random(dtype=np.float32) * 100
        a.append(random_float)

    for i in range (4):
        random_float = rng.random(dtype=np.float32) * 100
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
        r_addr = 0x20 + 0x4 * i
        r_tmp = ahb_slave.read_memory(r_addr, ahb_size)
        cocotb.log.info(f"A: {hex(r_addr)}; D: {r_tmp}")
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

async def do_all_i(dut, clk, ahb_slave_lsu, ahb_slave_ftc): # 20.3
    # fill mem
    rng = np.random.default_rng()
    a = []
    for i in range (4):
        random_float = rng.random(dtype=np.float32) * 2
        a.append(random_float)

    for i in range (4):
        ahb_slave_lsu.write_memory(0x1020 + i * (1 << 2), 2, float_to_i754(a[i], 32))


    # form inst
    ilc0 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0x004,   rd_addr = 30, rs1_addr = 30), ahb_slave_ftc, 0x04)
    iuc1 = InstItem(CIUI(op=UPPopTE.LUI,   imm = 0x00001, rd_addr = 1), ahb_slave_ftc, 0x08)
    ilc1 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0x020,   rd_addr = 1, rs1_addr = 1), ahb_slave_ftc, 0x0C)
    isc2 = InstItem(CISI(op=StoreOpTE.MUL, imm = 0x0D,    rd_addr = 9,  rs1_addr = 30, rs2_addr = VID_ADDR), ahb_slave_ftc, 0x2C)
    isc1 = InstItem(CISI(op=StoreOpTE.ADD, imm = 0x0D,    rd_addr = 10, rs1_addr = 9,  rs2_addr = 1), ahb_slave_ftc, 0x30)
    ilc2 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x00,    rd_addr = 2, rs1_addr = 10), ahb_slave_ftc, 0x10)
    ifc1 = InstItem(CIFI(op=FPUopTE.ADD,   imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 0,
                                           arg3_addr = 0,
                                           argr_addr = 3,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x14)
    ifc2 = InstItem(CIFI(op=FPUopTE.MUL,   imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 3,
                                           arg3_addr = 0,
                                           argr_addr = 4,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x18)
    ifc3 = InstItem(CIFI(op=FPUopTE.DIV,   imm = 0x00,
                                           arg1_addr = 4,
                                           arg2_addr = 3,
                                           arg3_addr = 0,
                                           argr_addr = 5,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x1C)
    ifc4 = InstItem(CIFI(op=FPUopTE.SQRT,  imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 1,
                                           arg3_addr = 4,
                                           argr_addr = 6,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x20)
    ifc5 = InstItem(CIFI(op=FPUopTE.NEG,   imm = 0x00,
                                           arg1_addr = 6,
                                           arg2_addr = 1,
                                           arg3_addr = 1,
                                           argr_addr = 7,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x24)
    ifc6 = InstItem(CIFI(op=FPUopTE.MAX,   imm = 0x00,
                                           arg1_addr = 5,
                                           arg2_addr = 6,
                                           arg3_addr = 0,
                                           argr_addr = 8,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x28)
    isc3 = InstItem(CISI(op=StoreOpTE.SW,  imm = 0x40,   rd_addr = 0,  rs1_addr = 10, rs2_addr = 6), ahb_slave_ftc, 0x34)

    ifpu = []
    for i in range(6):
        itmp = InstItem(CISI(op=StoreOpTE.SW,
                             imm = 0x60 + i * 16, # 4 threads with WORD Size of offset (4 * 4)
                             rd_addr = 0, # not used
                             rs1_addr = 10,
                             rs2_addr = 3 + i),
                             ahb_slave_ftc, 0x40 + i * 4)
        ifpu.append(itmp)
    # do
    await ilc0.load_instr(clk, dut)
    await iuc1.load_instr(clk, dut)
    await ilc1.load_instr(clk, dut)
    await isc2.load_instr(clk, dut)
    await isc1.load_instr(clk, dut)
    await ilc2.load_instr(clk, dut)
    await ClockCycles(clk, 1)
    dut.pc_i.value = 0x0
    dut.en_i.value = 0
    await ClockCycles(clk, 100)
    await ifc1.load_instr(clk, dut)
    await ifc2.load_instr(clk, dut)
    await ifc3.load_instr(clk, dut)
    await ifc4.load_instr(clk, dut)
    await ifc5.load_instr(clk, dut)
    await ifc6.load_instr(clk, dut)
    await ClockCycles(clk, 1)
    dut.pc_i.value = 0x0
    dut.en_i.value = 0

    await ClockCycles(clk, 100)

    await isc3.load_instr(clk, dut)

    await ClockCycles(clk, 1)
    dut.pc_i.value = 0x0
    dut.en_i.value = 0

    await ClockCycles(clk, 100)
    for iitem in ifpu:
        await iitem.load_instr(clk, dut)

    await ClockCycles(clk, 1)
    dut.pc_i.value = 0x0
    dut.en_i.value = 0
    await ClockCycles(clk, 200)

    r_fpu_res = []
    for i in range(6):
        r_fpu = []
        for j in range(4):
            r_addr = 0x1080 + ((i * 4) + j) * (1 << 2)
            r_tmp = ahb_slave_lsu.read_memory(r_addr, AHBSize.WORD.value)
            cocotb.log.info(f"A: {hex(r_addr)}; D: {r_tmp}")
            r_val = ieee754_to_float(hex(r_tmp), 32)
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
                              data_width=DW, log= cocotb.log, wait_states=0)

    ahb_slave_ftc = AHBSlaveModel(dut,
                          name = "ftc",
                          memory_size=2 ** 16,
                          data_width=DW, log= cocotb.log, wait_states=0)

    apb_master_csr = APB4Master(dut,
                                prefix = "csr",
                                clock = dut.clk,
                                reset = dut.rst_n)

    ipc1 = InstItem(CIUI(op=UPPopTE.LUI,   imm = 0xABCDE, rd_addr = 1),                 ahb_slave_ftc, 0x04)
    ipc2 = InstItem(CILI(op=LoadOpTE.ADDI, imm = 0xF12,   rd_addr = 1, rs1_addr = 1),   ahb_slave_ftc, 0x08)
    ipc3 = InstItem(CIUI(op=UPPopTE.RET,   imm = 0x00,    rd_addr = 0),                 ahb_slave_ftc, 0x12)
    await ClockCycles(clk, 30)

    await apb_master_csr.write(0x2 * 4, 0x4, 0b1111)
    await apb_master_csr.write(0x4 * 4, 0x0, 0b1111)
    await apb_master_csr.write(0x5 * 4, 0x1, 0b1111)
    await apb_master_csr.write(0x6 * 4, 0x2, 0b1111)
    await apb_master_csr.write(0x7 * 4, 0x3, 0b1111)
    await apb_master_csr.write(0x0 * 4, 0x1, 0b1111)

    # dut.pc_i.value = 0x0000
    # dut.en_i.value = 0

    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.ADD)
    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.MUL)
    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.DIV)
    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.SQRT)
    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.NEG)
    # await fpu_core_test(dut, clk, ahb_slave_lsu, ahb_slave_ftc, FPUopTE.MAX)
    # await do_all_i(dut, clk, ahb_slave_lsu, ahb_slave_ftc)

    await ClockCycles(clk, 100)
    ahb_slave_ftc.stop()
    ahb_slave_lsu.stop()

