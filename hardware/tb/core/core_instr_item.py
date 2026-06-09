#-----------------------------------------------------------------------------//
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# ----------------------------------------------------------------------------//
# Purpose: Core Instruction Item
# Date: 2026/06
#-----------------------------------------------------------------------------//

from core.core_enums import InstTE, LSUOpTE, FPUopTE, UPPopTE

import cocotb
DW = 32
AW = 5
OP_W = 5
OP_T_W = 2

LIMM_W = DW - (AW * 3 + OP_W + OP_T_W)
FIMM_W = DW - (AW * 4 + OP_W + OP_T_W + 3)
UIMM_W = DW - (AW + OP_W + OP_T_W)

class CoreInstItem():
    def __init__(self, op_type = InstTE.NONE):
        self.op_type    = op_type

    def get_machine_code(self) -> int:
        cocotb.log.info(f"Meh")
        return 0

class CILI(CoreInstItem):
    def __init__(self,
                 op: LSUOpTE,
                 rs1_addr: int,
                 rs2_addr: int,
                 rd_addr: int,
                 imm = int,
                 op_type = InstTE.LSU,
                 ):
        super().__init__(op_type)
        self.rs1_addr = rs1_addr
        self.rs2_addr = rs2_addr
        self.rd_addr  = rd_addr
        self.imm      = imm
        self.op_type  = op_type
        self.op       = op

    def get_machine_code(self) -> int:
        res = 0
        res =  self.imm                                        \
            | (self.rd_addr        <<  LIMM_W)                 \
            | (self.rs2_addr       << (LIMM_W + AW))           \
            | (self.rs1_addr       << (LIMM_W + 2 * AW))       \
            | (self.op.value       << (LIMM_W + 3 * AW))       \
            | (self.op_type.value  << (LIMM_W + 3 * AW + OP_W))
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        cocotb.log.info(f"Mewh")
        return res

class CIFI(CoreInstItem):
    def __init__(self,
                 op: FPUopTE,
                 arg1_addr: int,
                 arg2_addr: int,
                 arg3_addr: int,
                 argr_addr: int,
                 extra: int,
                 imm: int,
                 op_type=InstTE.FPU):
        super().__init__(op_type)
        self.op        = op
        self.arg1_addr = arg1_addr
        self.arg2_addr = arg2_addr
        self.arg3_addr = arg3_addr
        self.argr_addr = argr_addr
        self.extra     = extra
        self.imm       = imm

    def get_machine_code(self) -> int:
        res = 0
        res =  self.imm                                            \
            | (self.extra          <<  FIMM_W)                     \
            | (self.arg1_addr      << (FIMM_W + 3))                \
            | (self.arg2_addr      << (FIMM_W + 3 + 1 * AW))       \
            | (self.arg3_addr      << (FIMM_W + 3 + 2 * AW))       \
            | (self.argr_addr      << (FIMM_W + 3 + 3 * AW))       \
            | (self.op.value       << (FIMM_W + 3 + 4 * AW))       \
            | (self.op_type.value  << (FIMM_W + 3 + 4 * AW + OP_W))
        cocotb.log.info(f"Meow")
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        return res


class CIUI(CoreInstItem):
    def __init__(self,
                 imm: int,
                 rd_addr: int,
                 op_type=InstTE.UPP):
        super().__init__(op_type)
        self.imm     = imm
        self.rd_addr = rd_addr
        self.op      = UPPopTE.DUM

    def get_machine_code(self) -> int:
        res = 0
        res =  self.imm                                            \
            | (self.rd_addr        <<  UIMM_W)                     \
            | (self.op.value       << (UIMM_W + AW))               \
            | (self.op_type.value  << (UIMM_W + AW + OP_W))
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        cocotb.log.info(f"CIUI: {hex(res)}")
        return res