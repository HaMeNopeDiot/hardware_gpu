# test_my_design.py (simple)

import cocotb
from cocotb.triggers import Timer, ClockCycles, FallingEdge

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
from utility.addresess    import CSRAddr

from utility.intsr_bin_reader   import hex2word

time_cycle = 20 * 1e-9 #ns
hz = (1 / time_cycle) # 50Mhz while time_cycle = 20ns

CORES_CNT   = 1
THREADS_CNT = 4

def read_vbuffer(filename):
    values = []
    try:
        with open(filename, 'r', encoding='utf-8') as f:
            for line in f:
                line = line.strip()

                # Пропускаем пустые строки и комментарии
                if not line or line.startswith('//'):
                    continue

                # Разбиваем строку на части по пробелам
                parts = line.split()

                for part in parts:
                    # На всякий случай проверяем, не является ли часть комментарием
                    if part.startswith('//'):
                        break

                    if part is not None:
                        values.append(part)
    except FileNotFoundError:
        print(f"Файл {filename} не найден.")
        return []

    return values

async def cnt_busy_cycles(dut, clk, cnt_instr: int):
    wait_busy = 0
    while (dut.busy_o.value == 0):
        await ClockCycles(clk, 1)
        wait_busy += 1
        assert wait_busy < 10000, "TIME OUT"

    wait_untill_busy = 0
    while (dut.busy_o.value == 1):
        await ClockCycles(clk, 1)
        wait_untill_busy += 1
        assert wait_untill_busy < 10000, "TIME OUT"

    assert wait_untill_busy > 2, "no"
    wait_untill_busy -= 2
    # res
    cpi = float(wait_untill_busy / cnt_instr)
    tflops = (hz * CORES_CNT * (THREADS_CNT * (1 / cpi))) * 1e-12
    cocotb.log.warning(f"WAIT BUSY CYCLES: {wait_untill_busy}")
    cocotb.log.warning(f"Hz / CI: {cpi}")
    cocotb.log.warning(f"MIPS: {hz / (cpi * 1e+6)}")
    cocotb.log.warning(f"TFLOPS: {tflops}")

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

async def fpu_core_test(dut,
                        clk,
                        ahb_slave,
                        ahb_slave_ftc,
                        apb_master_csr,
                        fpu_op: FPUopTE):
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
    ret0 = InstItem(CIUI(op=UPPopTE.RET,   imm = 0x00,    rd_addr = 0),                 ahb_slave_ftc, 0x1C)


    # execute instructions
    cocotb.start_soon(cnt_busy_cycles(dut, clk, 7))
    await apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
    await apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)


    while (dut.busy_o.value == 1):
        await ClockCycles(clk, 1)
    # get values
    res = []
    cocotb.log.info(f"READ MEM")
    for i in range(4):
        r_addr = 0x20 + 0x4 * i
        r_tmp = ahb_slave.read_memory(r_addr, ahb_size)
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

async def do_all_i(dut, clk, ahb_slave_lsu, ahb_slave_ftc, apb_master_csr): # 20.3
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
    isc2 = InstItem(CISI(op=StoreOpTE.MUL, imm = 0x0D,    rd_addr = 9,  rs1_addr = 30, rs2_addr = VID_ADDR), ahb_slave_ftc, 0x10)
    isc1 = InstItem(CISI(op=StoreOpTE.ADD, imm = 0x0D,    rd_addr = 10, rs1_addr = 9,  rs2_addr = 1), ahb_slave_ftc, 0x14)
    ilc2 = InstItem(CILI(op=LoadOpTE.LW,   imm = 0x00,    rd_addr = 2, rs1_addr = 10), ahb_slave_ftc, 0x18)
    ifc1 = InstItem(CIFI(op=FPUopTE.ADD,   imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 0,
                                           arg3_addr = 0,
                                           argr_addr = 3,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x1C)
    ifc2 = InstItem(CIFI(op=FPUopTE.MUL,   imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 3,
                                           arg3_addr = 0,
                                           argr_addr = 4,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x20)
    ifc3 = InstItem(CIFI(op=FPUopTE.DIV,   imm = 0x00,
                                           arg1_addr = 4,
                                           arg2_addr = 3,
                                           arg3_addr = 0,
                                           argr_addr = 5,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x24)
    ifc4 = InstItem(CIFI(op=FPUopTE.SQRT,  imm = 0x00,
                                           arg1_addr = 2,
                                           arg2_addr = 1,
                                           arg3_addr = 4,
                                           argr_addr = 6,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x28)
    ifc5 = InstItem(CIFI(op=FPUopTE.NEG,   imm = 0x00,
                                           arg1_addr = 6,
                                           arg2_addr = 1,
                                           arg3_addr = 1,
                                           argr_addr = 7,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x2C)
    ifc6 = InstItem(CIFI(op=FPUopTE.MAX,   imm = 0x00,
                                           arg1_addr = 5,
                                           arg2_addr = 6,
                                           arg3_addr = 0,
                                           argr_addr = 8,
                                           extra=RoundModeE.RTZ.value), ahb_slave_ftc, 0x30)
    isc3 = InstItem(CISI(op=StoreOpTE.SW,  imm = 0x40,   rd_addr = 0,  rs1_addr = 10, rs2_addr = 6), ahb_slave_ftc, 0x34)
    ret0 = InstItem(CIUI(op=UPPopTE.RET,   imm = 0x00,    rd_addr = 0),                 ahb_slave_ftc, 0x38)

    ifpu = []
    for i in range(6):
        itmp = InstItem(CISI(op=StoreOpTE.SW,
                             imm = 0x60 + i * 16, # 4 threads with WORD Size of offset (4 * 4)
                             rd_addr = 0, # not used
                             rs1_addr = 10,
                             rs2_addr = 3 + i),
                             ahb_slave_ftc, 0x40 + i * 4)
        ifpu.append(itmp)
    ret0 = InstItem(CIUI(op=UPPopTE.RET,   imm = 0x00,    rd_addr = 0), ahb_slave_ftc, 0x58)

    # do
    cocotb.start_soon(cnt_busy_cycles(dut, clk, 14))
    await apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
    await apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)

    while (dut.busy_o.value == 1):
        await ClockCycles(clk, 1)


    cocotb.start_soon(cnt_busy_cycles(dut, clk, 7))
    await apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x40, 0b1111)
    await apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1,  0b1111)


    while (dut.busy_o.value == 1):
        await ClockCycles(clk, 1)

    r_fpu_res = []
    for i in range(6):
        r_fpu = []
        for j in range(4):
            r_addr = 0x1080 + ((i * 4) + j) * (1 << 2)
            r_tmp = ahb_slave_lsu.read_memory(r_addr, AHBSize.WORD.value)
            cocotb.log.info(f"- A: {hex(r_addr)}; D: {r_tmp}")
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

class BaseCoreTest:
    def __init__(self, dut, name: str = "test"):
        self.name = name
        self.dut = dut
        self.clk = dut.clk
        self.rst_n = dut.rst_n
        self.ahb_slave_lsu = None
        self.ahb_slave_ftc = None
        self.apb_master_csr = None


    async def prebody(self):
        clk = self.clk
        rst_n = self.rst_n
        dut = self.dut
        cocotb.start_soon(clock_generator(clk, 10, unit="ns"))
        # make reset
        await make_reset(clk, rst_n)

        self.ahb_slave_lsu = AHBSlaveModel(dut,
                                name = "lsu",
                                memory_size=2 ** 32,
                                data_width=DW, log= cocotb.log, wait_states=0)

        self.ahb_slave_ftc = AHBSlaveModel(dut,
                            name = "ftc",
                            memory_size=2 ** 32,
                            data_width=DW, log= cocotb.log, wait_states=0)

        self.apb_master_csr = APB4Master(dut,
                                    prefix = "csr",
                                    clock = dut.clk,
                                    reset = dut.rst_n)

        await self.apb_master_csr.write(CSRAddr.CORE_VID.value       , 0x0, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x4 , 0x1, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0x8 , 0x2, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_VID.value + 0xC , 0x3, 0b1111)

    async def body(self):
        pass # virtual

    async def postbody(self):
        await ClockCycles(self.clk, 10)
        self.ahb_slave_lsu.stop()
        self.ahb_slave_ftc.stop()

    async def run(self):
        await self.prebody()
        await self.body()
        await self.postbody()

class ISACheckTest(BaseCoreTest):
    async def body(self):
        await do_all_i(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr)

class FPUCheckADDTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.ADD)

class FPUCheckMULTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.MUL)

class FPUCheckDIVTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.DIV)

class FPUCheckSQRTTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.SQRT)

class FPUCheckNEGTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.NEG)

class FPUCheckMAXTest(BaseCoreTest):
    async def body(self):
        await fpu_core_test(self.dut, self.clk, self.ahb_slave_lsu, self.ahb_slave_ftc, self.apb_master_csr, FPUopTE.MAX)


import struct
class VKCubeTest(BaseCoreTest):
    async def body(self):
        cocotb.log.info(f"It's comming")
        with open("../../nir_to_assembly/vertex_shader.bin", "rb") as f:
            raw_data = f.read()

        # Отрезаем лишние байты, если длина не кратна 4
        count = len(raw_data) // 4
        raw_data = raw_data[:count * 4]

        # '<I' = little-endian, unsigned int
        words = struct.unpack('<' + 'I' * count, raw_data)
        idx = 0

        i_arr = []
        for word in words:
            print(f"idx: {idx} : 0x{word:08x}")
            i = CoreInstItem()
            i.set_machine_code(word)
            idx += 1
            i_arr.append(i)

        # set instr to mem
        idx = 0
        for instr in i_arr:
            InstItem(instr, self.ahb_slave_ftc, 4 + idx * 4)
            idx += 1

        for i in range(len(i_arr)):
            print(f"{i:3} : ", end = "")
            i_arr[i].print()

        # write mem
        data = read_vbuffer("../../vkcube/vertex_buffer.mem")
        idx = 0
        # print(f"Всего элементов: {len(data)}")
        # print("Первые 10 значений:", data[:10])
        # print("Последние 5 значений:", data[-5:])
        for data_elem in data:
            self.ahb_slave_lsu.write_memory(0x1000_0000 + idx * 4, AHBSize.WORD.value, int(data_elem, 32))
            idx += 1
        # nucelar launch ready
        cocotb.start_soon(cnt_busy_cycles(self.dut, self.clk, 7))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)


        # wait
        while (self.dut.busy_o.value == 1):
           await ClockCycles(self.clk, 1)

        data_res = []

        for i in range(0x2000_0000, 0x2000_0320, 0x4):
            data = self.ahb_slave_lsu.read_memory(i, AHBSize.WORD.value)
            print(f"0x{data:08x}")