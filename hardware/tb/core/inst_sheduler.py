#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Instruction Item For Fetcher
# Date: 2026/07
#------------------------------------------------------------------------------#

import cocotb

from core.core_instr_item   import CII
from core.core_enums        import CoreOp
from core.ahb_slave         import AHBSlaveModel, AHBSize

class InstSheduler():
    def __init__(self,
                 name: str = "sheduler",
                 log = cocotb.log,
                 if_slave_model: AHBSlaveModel = None):
        self.name = name
        self.log  = log
        self.if_slave_model = if_slave_model
        # ------------- #
        self._inst_q: list[CII] = []
        self.cur_start_pc: int = 0
        self.cur_pc: int = 0
        self.last_prog_len: int = 0

    def load_cii_i(self, instr: CII, auto_load_prog: bool = True):
        self._inst_q.append(instr)
        if auto_load_prog and instr.op == CoreOp.RET:
            self.load_prog_in_mem()

    def load_i(self,
                op            : CoreOp = None,
                rs1_addr      : int = 0,
                rs2_addr      : int = 0,
                rs3_addr      : int = 0,
                rd_addr       : int = 0,
                imm           : int = 0,
                extra         : int = 0,
                auto_load_prog: bool = True):
        self.load_cii_i(CII(op = op,
                               rs1_addr = rs1_addr,
                               rs2_addr = rs2_addr,
                               rs3_addr = rs3_addr,
                               rd_addr = rd_addr,
                               imm = imm,
                               extra= extra), auto_load_prog)

    def load_prog_in_mem(self) -> int:
        ret_instr_cptr: bool = False
        prog_len = 0
        self.cur_start_pc = self.cur_pc
        while(not ret_instr_cptr and prog_len < len(self._inst_q)):
            instr = self.get_inst_by_idx(prog_len)
            instr.print()
            mc_instr = instr.get_machine_code()
            self.if_slave_model.write_word(self.cur_pc, mc_instr)
            self.cur_pc += (1 << AHBSize.WORD)
            if instr.op == CoreOp.RET:
                ret_instr_cptr = True
            prog_len += 1
        if (not ret_instr_cptr):
            self.log.warning(f"Did't load RET instruction in memory after load program")

        self.log.debug(f"Len q: {len(self._inst_q)}. prog_len: {prog_len}")
        for _ in range(prog_len):
            self._inst_q.pop(0)
        self.last_prog_len = prog_len
        #self.print_q_op()

    def get_inst_by_idx(self, idx: int) -> CII:
        assert idx < len(self._inst_q), f"idx out of range: {idx} with len {len(self._inst_q)}"
        return self._inst_q[idx]

    def get_inst_machine_code_by_idx(self, idx: int) -> int:
        return self.get_inst_by_idx().get_machine_code()

    def get_prog_len(self):
        return self.last_prog_len

    def print_q_op(self):
        cocotb.log.info(f"Queue {self.name}:")
        for qe in self._inst_q:
            cocotb.log.info(f"- {qe.op.name}")

    def get_start_pc(self):
        # print(f"ninnerne {self.cur_start_pc}")
        return self.cur_start_pc