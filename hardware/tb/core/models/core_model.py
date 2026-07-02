#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Core model
# Date: 2026/06
#------------------------------------------------------------------------------#

import math
import cocotb
from collections import defaultdict

from utility.defines    import DW, VID_ADDR, ZERO_ADDR, THREADS_CNT, BYTES_CNT

from core.models.thread_model   import ThreadModel
from core.core_enums            import CoreOp
from core.core_instr_item       import CII

from fpu.fppconverter import hex_ieee754_to_float, float_to_i754


class CoreModel():
    def __init__(self,
                 name = "",
                 log = cocotb.log,
                 thread_cnt:int = THREADS_CNT,
                 dw:int = DW,
                 regfile_sz:int = 32,
                 mem_sz: int = 1 << 32,
                 vid_addr: int = VID_ADDR,
                 zero_addr: int = ZERO_ADDR):
        # safe parameters
        self.log = log
        self.name = name
        self._thread_cnt = thread_cnt
        self._regfile_sz = regfile_sz
        self._vid_addr = vid_addr
        self._zero_addr = zero_addr
        self._dw = dw
        self._mem_sz = mem_sz
        # initial
        self._aw = math.ceil(math.log2(self._regfile_sz))
        self._threads: list[ThreadModel] = []
        for i in range(self._thread_cnt):
            tmp_tu = ThreadModel(log=self.log,
                                 name=self.name + f"-t{i}",
                                 dw=self._dw,
                                 regfile_sz=self._regfile_sz,
                                 vid_addr=self._vid_addr,
                                 zero_addr=self._zero_addr)
            self._threads.append(tmp_tu)
        self._en = 0
        self._memory = defaultdict(lambda: 0x00)

    def write_memory(self, addr: int, data: int):
        """
        Write to internal memory.

        Args:
            addr: Byte address
            data: Data to write
        """
        num_bytes = BYTES_CNT
        aligned_addr = addr & ~(num_bytes - 1)

        for i in range(num_bytes):
            self._memory[aligned_addr + i] = (data >> (8 * i)) & 0xFF

    def read_memory(self, addr: int):
        """
        Read from internal memory.

        Args:
            addr: Byte address

        Returns:
            Data value read from memory
        """
        num_bytes = BYTES_CNT
        aligned_addr = addr & ~(num_bytes - 1)  # Natural alignment

        value = 0
        for i in range(num_bytes):
            value |= self._memory[aligned_addr + i] << (8 * i)

        return value


    def handle_op(self, instr: CII):
        op = instr.op
        imm = instr.imm
        for thread in self._threads:
            if op == CoreOp.SW:
                rs1 = thread.read_regfile(instr.rs1_addr)
                rs2 = thread.read_regfile(instr.rs2_addr)
                self.write_memory(rs1 + imm, rs2)
            elif op == CoreOp.LW:
                rs1 = thread.read_regfile(instr.rs1_addr)
                data = self.read_memory(rs1 + imm)
                self.log.debug(f"Try to read from addr: {hex(rs1 + imm)} and get: {data}")
                thread.handle_op(instr, data)
            else:
                thread.handle_op(instr)


    def launch(self):
        self.log.info(f"{self.name} core launched")
        self._en = 1
        for thread in self._threads:
            thread.launch()

    def set_vid_to_thread(self, vid: int, thread_idx: int):
        self._threads[thread_idx].set_vid(vid)

    def print(self, max_regs_in_col: int = 8):
        for thread in self._threads:
            thread.print(max_regs_in_col)
