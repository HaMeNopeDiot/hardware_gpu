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
from core.ahb_slave         import AHBSize
from core.models.core_model import CoreModel
from core.instr_item        import InstItem
from core.core_enums        import RoundModeE

from fpu.fppconverter     import float_to_i754, ieee754_to_float

from utility.bin_unpack   import unpack_bin_file, read_vbuffer
from utility.addresess    import CSRAddr, POSITION_BASE_ADDR


class VKCubeTest(BaseCoreTest):
    def prepare(self):
        cocotb.log.info(f"It's comming")
        words = unpack_bin_file("../../nir_to_assembly/vertex_shader.bin")
        idx = 0

        i_arr = []
        for word in words:
            # print(f"idx: {idx} : 0x{word:08x}")
            i = CoreInstItem()
            i.set_machine_code(word)
            i.extra = RoundModeE.RNE.value
            idx += 1
            i_arr.append(i)

        # set instr to mem
        idx = 0
        for instr in i_arr:
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

        # Core model serve
        self.core_model.set_vid_to_thread(0, 0)
        self.core_model.set_vid_to_thread(1, 1)
        self.core_model.set_vid_to_thread(2, 2)
        self.core_model.set_vid_to_thread(3, 3)

        idx = 0
        for data_elem in data:
            self.core_model.write_memory(0x0000_0000 + idx * 4, int(data_elem, 16))
            idx += 1

        cocotb.log.debug(f"ADDR FROM MODEL  0x70 = {self.core_model.read_memory(0x70)}")
        cocotb.log.debug(f"ADDR FROM AHB SL 0x70 = {self.ahb_slave_lsu.read_memory(0x70, AHBSize.WORD.value)}")

        self.core_model.launch()
        for instruction in i_arr:
            self.core_model.handle_op(instruction)



    def dump(self):
        # print(f"HEX DUMP MEMORY")
        # hex_dump_mem = []
        # for i in range(0x2000_0000, 0x2000_0320, 0x4):
        #     data = self.ahb_slave_lsu.read_memory(i, AHBSize.WORD.value)
        #     if ((i+0x4) % 0x20) == 0:
        #         print(f"0x{data:08x}")
        #     else:
        #         print(f"0x{data:08x}", end=" ")
        #     hex_dump_mem.append(data)

        print(f"FLOAT DUMP MEMORY")
        float_dump_mem = []

        pos_base_addr     = POSITION_BASE_ADDR      # 0x2000_0000
        pos_base_addr_end = pos_base_addr + 0x320
        for i in range(pos_base_addr, pos_base_addr_end, 0x4):
            data = self.ahb_slave_lsu.read_memory(i, AHBSize.WORD.value)
            fdata = ieee754_to_float(data, 32)
            if ((i+0x4) % 0x20) == 0:
                print(f"{fdata}")
            else:
                print(f"{fdata}", end=" ")
            float_dump_mem.append(fdata)

        print(f"FLOAT DUMP MODEL MEMORY")
        float_dump_model = []
        for i in range(pos_base_addr, pos_base_addr_end, 0x4):
            data = self.core_model.read_memory(i)
            fdata = ieee754_to_float(data, 32)
            if ((i+0x4) % 0x20) == 0:
                print(f"{fdata}")
            else:
                print(f"{fdata}", end=" ")
            float_dump_model.append(fdata)

        # compare
        eps = 1e-1
        for i in range(len(float_dump_model)):
            model_data = float_dump_model[i]
            real_data  = float_dump_mem[i]
            prox = abs(model_data - real_data)
            is_equal = prox <= eps
            if not is_equal:
                cocotb.log.error(f"Model not equal real core. REAL: {real_data:08x} vs MODEL: {model_data:08x} (prox is {prox} > eps)")
                assert is_equal, f"Model not equal real core."
            if model_data != real_data:
                cocotb.log.warning(f"{i:3}: real data not eq model data: {float_to_i754(real_data, 32):08x} <> {float_to_i754(model_data, 32):08x}")


    async def body(self):
        self.prepare()
        # nucelar launch ready
        cocotb.start_soon(self.cnt_busy_cycles(213))
        await self.apb_master_csr.write(CSRAddr.CORE_PC.value  , 0x4, 0b1111)
        await self.apb_master_csr.write(CSRAddr.CORE_CTRL.value, 0x1, 0b1111)

        # wait
        while (self.dut.busy_o.value == 1):
           await ClockCycles(self.clk, 1)
        self.dump()
        #await ClockCycles(self.clk, 2000)
        await self.unload_all_regfiles(0x1000)