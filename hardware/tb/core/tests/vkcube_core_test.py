#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: VKCUBE core test
# Date: 2026/06
#------------------------------------------------------------------------------#

import struct

import cocotb
from cocotb.triggers      import ClockCycles

from core.tests.base_itest  import BaseCoreTest
from core.core_instr_item   import CoreInstItem
from core.ahb_slave       import AHBSize
from core.instr_item      import InstItem

from fpu.fppconverter     import ieee754_to_float

from utility.addresess    import CSRAddr


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

class VKCubeTest(BaseCoreTest):
    def prepare(self):
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
            # print(f"idx: {idx} : 0x{word:08x}")
            i = CoreInstItem()
            i.set_machine_code(word)
            idx += 1
            i_arr.append(i)

        # set instr to mem
        idx = 0
        for instr in i_arr:
            assert instr.get_machine_code() == words[idx], f"instruction decode don't match"
            InstItem(instr, self.ahb_slave_ftc, 4 + idx * 4)
            idx += 1

        cocotb.log.info(f"INSTRUCTION QUEUE")
        for i in range(len(i_arr)):
            print(f"{i:3} : ", end = "")
            i_arr[i].print()

        # write mem
        data = read_vbuffer("../../vkcube/vertex_buffer.mem")
        idx = 0
        # print(f"Всего элементов: {len(data)}")

        cocotb.log.info(f"VERTEX BUFFER DUMP MEMORY")
        for data_e in data:
            if idx % 4 == 0:
                print(f"{(idx * 4):04x}: {data_e}", end = " ")
            elif idx % 4 == 3:
                print(f"{data_e}")
            else:
                print(f"{data_e}", end=" ")
            idx += 1
        print(f"\n", end="")

        idx = 0
        # print("Последние 5 значений:", data[-5:])
        for data_elem in data:
            self.ahb_slave_lsu.write_memory(0x0000_0000 + idx * 4, AHBSize.WORD.value, int(data_elem, 16))
            idx += 1
        # print(f"meme {hex(self.ahb_slave_lsu.read_memory(0x0000_00CC, AHBSize.WORD.value))}")

    def dump(self):
        data_res = []
        print(f"HEX DUMP MEMORY")

        for i in range(0x2000_0000, 0x2000_0320, 0x4):
            data = self.ahb_slave_lsu.read_memory(i, AHBSize.WORD.value)
            if ((i+0x4) % 0x20) == 0:
                print(f"0x{data:08x}")
            else:
                print(f"0x{data:08x}", end=" ")

        print(f"FLOAT DUMP MEMORY")

        for i in range(0x2000_0000, 0x2000_0320, 0x4):
            data = self.ahb_slave_lsu.read_memory(i, AHBSize.WORD.value)
            if data == 0:
                fdata = 0
            else:
                fdata = ieee754_to_float(hex(data), 32)
            if ((i+0x4) % 0x20) == 0:
                print(f"{fdata}")
            else:
                print(f"{fdata}", end=" ")

    async def body(self):
        self.prepare()
        # nucelar launch ready
        cocotb.start_soon(self.cnt_busy_cycles(7))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)

        # wait
        while (self.dut.busy_o.value == 1):
           await ClockCycles(self.clk, 1)
        self.dump()