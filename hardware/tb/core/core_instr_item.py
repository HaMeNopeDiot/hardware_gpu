#------------------------------------------------------------------------------#
# Author:                Starukhin Danila M.
# Author's e-mail:       sniperusus2002@gmail.com
# -----------------------------------------------------------------------------#
# Purpose: Core Instruction Item
# Date: 2026/06
#------------------------------------------------------------------------------#

from core.core_enums import InstTE, LoadOpTE, FPUopTE, UPPopTE, StoreOpTE
import cocotb

from utility.defines import DW, AW, OP_W, OP_T_W

LIMM_W = DW - (AW * 2 + OP_W + OP_T_W)
FIMM_W = DW - (AW * 4 + OP_W + OP_T_W + 3)
UIMM_W = DW - (AW + OP_W + OP_T_W)          # 32 - 5 - 5 - 2 = 32 - 12 = 20
SIMM_W = DW - (AW * 3 + OP_W + OP_T_W)

from core.core_enums    import CoreOp

class CoreInstItem():
    def __init__(self,
                op_type: InstTE = None,
                op = None,
                rs1_addr: int = 0,
                rs2_addr: int = 0,
                rs3_addr: int = 0,
                rd_addr: int = 0,
                imm: int = 0,
                extra: int = 0):
        self.op_type    = op_type
        self.op         = op
        self.rs1_addr   = rs1_addr
        self.rs2_addr   = rs2_addr
        self.rs3_addr   = rs3_addr
        self.rd_addr    = rd_addr
        self.imm        = imm
        self.extra      = extra

    def get_opcode(self) -> int:
        return (self.op_type.value << OP_W) | self.op.value

    def get_op(self) -> CoreOp:
        match self.op_type:
            case InstTE.UPP:
                match self.op:
                    case UPPopTE.LUI:
                        return CoreOp.LUI
                    case UPPopTE.RET:
                        return CoreOp.RET
                    case _:
                        assert False, f"Unknown {self.op_type.name} operation type"
            case InstTE.LOAD:
                match self.op:
                    case LoadOpTE.LW:
                        return CoreOp.LW
                    case LoadOpTE.ADDI:
                        return CoreOp.ADDI
                    case _:
                        assert False, f"Unknown {self.op_type.name} operation type"
            case InstTE.FPU:
                match self.op:
                    case FPUopTE.ADD:
                        return CoreOp.FADD
                    case FPUopTE.MUL:
                        return CoreOp.FMUL
                    case FPUopTE.DIV:
                        return CoreOp.FDIV
                    case FPUopTE.SQRT:
                        return CoreOp.FSQRT
                    case FPUopTE.NEG:
                        return CoreOp.FNEG
                    case FPUopTE.MAX:
                        return CoreOp.FMAX
                    case _:
                        assert False, f"Unknown {self.op_type.name} operation type"
            case InstTE.STORE:
                match self.op:
                    case StoreOpTE.ADD:
                        return CoreOp.ADD
                    case StoreOpTE.MUL:
                        return CoreOp.MUL
                    case StoreOpTE.SW:
                        return CoreOp.SW
                    case _:
                        assert False, f"Unknown {self.op_type.name} operation type"
            case _:
                assert False, "Unknown isntruction type"


    def _get_stype_from_machine_code(self, value):
        # Извлекаем поля, инвертируя логику get_machine_code
        imm_mask        = (1 << SIMM_W) - 1
        addr_mask       = (1 << AW) - 1
        op_mask         = (1 << OP_W) - 1
        op_type_mask    = (1 << OP_T_W) - 1

        self.imm      = value & imm_mask
        self.rs1_addr = (value >> SIMM_W) & addr_mask
        self.rs2_addr = (value >> (SIMM_W + AW)) & addr_mask
        self.rd_addr  = (value >> (SIMM_W + 2 * AW)) & addr_mask

        # Восстанавливаем Enum из значения
        op_val = (value >> (SIMM_W + 3 * AW)) & op_mask
        self.op       = StoreOpTE(op_val)

        op_type_val = (value >> (SIMM_W + 3 * AW + OP_W)) & op_type_mask
        self.op_type  = InstTE(op_type_val)

        #self.print()

    def _get_utype_from_machine_code(self, value):
        imm_mask        = (1 << UIMM_W) - 1
        addr_mask       = (1 << AW) - 1
        op_mask         = (1 << OP_W) - 1
        op_type_mask    = (1 << OP_T_W) - 1

        self.imm     = value & imm_mask
        self.rd_addr = (value >> UIMM_W) & addr_mask

        op_val       = (value >> (UIMM_W + AW)) & op_mask
        self.op      = UPPopTE(op_val)

        op_type_val  = (value >> (UIMM_W + AW + OP_W)) & op_type_mask
        self.op_type = InstTE(op_type_val)

        #self.print()

    def _get_ltype_from_machine_code(self, value):
        imm_mask        = (1 << LIMM_W) - 1
        addr_mask       = (1 << AW) - 1
        op_mask         = (1 << OP_W) - 1
        op_type_mask    = (1 << OP_T_W) - 1

        self.imm      = value & imm_mask
        self.rs1_addr = (value >> (LIMM_W)) & addr_mask
        self.rd_addr  = (value >> (LIMM_W + AW)) & addr_mask

        op_val = (value >> (LIMM_W + 2 * AW)) & op_mask
        self.op       = LoadOpTE(op_val)

        op_type_val = (value >> (LIMM_W + 2 * AW + OP_W)) & op_type_mask
        self.op_type  = InstTE(op_type_val)

        #self.print()

    def _get_ftype_from_machine_code(self, value):
        # extra занимает 3 бита (так как argr_addr сдвинут на FIMM_W + 3)
        imm_mask     = (1 << FIMM_W) - 1
        extra_mask   = (1 << 3) - 1
        addr_mask    = (1 << AW) - 1
        op_mask      = (1 << OP_W) - 1
        op_type_mask = (1 << OP_T_W) - 1

        self.imm       = value & imm_mask
        self.extra     = (value >> FIMM_W) & extra_mask
        self.rd_addr   = (value >> (FIMM_W + 3)) & addr_mask
        self.rs3_addr  = (value >> (FIMM_W + 3 + AW)) & addr_mask
        self.rs2_addr  = (value >> (FIMM_W + 3 + 2 * AW)) & addr_mask
        self.rs1_addr  = (value >> (FIMM_W + 3 + 3 * AW)) & addr_mask

        op_val = (value >> (FIMM_W + 3 + 4 * AW)) & op_mask
        self.op        = FPUopTE(op_val)

        op_type_val = (value >> (FIMM_W + 3 + 4 * AW + OP_W)) & op_type_mask
        self.op_type   = InstTE(op_type_val)

        #self.print()

    def set_machine_code(self, value: int):
        op_type_mask    = (1 << OP_T_W) - 1
        op_type_val = (value >> 30) & op_type_mask
        self.op_type = InstTE(op_type_val)
        cocotb.log.debug(f"HEX: {value:08x}; OP_VAL: {op_type_val}")
        match self.op_type:
            case InstTE.UPP:
                self._get_utype_from_machine_code(value)
            case InstTE.STORE:
                self._get_stype_from_machine_code(value)
            case InstTE.LOAD:
                self._get_ltype_from_machine_code(value)
            case InstTE.FPU:
                self._get_ftype_from_machine_code(value)
            case _:
                pass

    def _get_stype_machine_code(self) -> int:
        res = 0
        res =  self.imm                                        \
            | (self.rs1_addr       <<  SIMM_W)                 \
            | (self.rs2_addr       << (SIMM_W + AW))           \
            | (self.rd_addr        << (SIMM_W + 2 * AW))       \
            | (self.op.value       << (SIMM_W + 3 * AW))       \
            | (self.op_type.value  << (SIMM_W + 3 * AW + OP_W))
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        cocotb.log.debug(f"CISI: {hex(res)}")
        return res

    def _get_ftype_machine_code(self) -> int:
        res = 0
        res =  self.imm                                             \
            | (self.extra          <<  FIMM_W)                      \
            | (self.rd_addr        << (FIMM_W + 3))                 \
            | (self.rs3_addr       << (FIMM_W + 3 + 1 * AW))        \
            | (self.rs2_addr       << (FIMM_W + 3 + 2 * AW))        \
            | (self.rs1_addr       << (FIMM_W + 3 + 3 * AW))        \
            | (self.op.value       << (FIMM_W + 3 + 4 * AW))        \
            | (self.op_type.value  << (FIMM_W + 3 + 4 * AW + OP_W))
        cocotb.log.debug(f"CIFI: {hex(res)}")
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        return res

    def _get_utype_machine_code(self) -> int:
        res = 0
        res =  self.imm                                            \
            | (self.rd_addr        <<  UIMM_W)                     \
            | (self.op.value       << (UIMM_W + AW))               \
            | (self.op_type.value  << (UIMM_W + AW + OP_W))
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        cocotb.log.debug(f"CIUI: {hex(res)}")
        return res

    def _get_ltype_machine_code(self) -> int:
        res = 0
        res =  self.imm                                        \
            | (self.rs1_addr       <<  LIMM_W)                 \
            | (self.rd_addr        << (LIMM_W + 1 * AW))       \
            | (self.op.value       << (LIMM_W + 2 * AW))       \
            | (self.op_type.value  << (LIMM_W + 2 * AW + OP_W))
        assert res <= (1 << DW), f"RESULT MACHINE CODE IS BROKEN: {hex(res)}"
        cocotb.log.debug(f"CILI: {hex(res)}")
        return res

    def get_machine_code(self) -> int:
        match self.op_type:
            case InstTE.UPP:
                return self._get_utype_machine_code()
            case InstTE.STORE:
                return self._get_stype_machine_code()
            case InstTE.LOAD:
                return self._get_ltype_machine_code()
            case InstTE.FPU:
                return self._get_ftype_machine_code()
            case _:
                cocotb.log.error("None type in instruction")
                assert False

    def print(self):
        match self.op_type:
            case InstTE.UPP:
                cocotb.log.info(f"{self.get_machine_code():08x} ::: I: {self.op_type.name:6} :: op: {self.op.name:8}; imm: 0x{self.imm:06x}; rd: {self.rd_addr:02x};")
            case InstTE.STORE:
                cocotb.log.info(f"{self.get_machine_code():08x} ::: I: {self.op_type.name:6} :: op: {self.op.name:8}; imm: 0x{self.imm:03x}; rd: {self.rd_addr:02x}; rs1: {self.rs1_addr:02x}; rs2: {self.rs2_addr:02x};")
            case InstTE.LOAD:
                cocotb.log.info(f"{self.get_machine_code():08x} ::: I: {self.op_type.name:6} :: op: {self.op.name:8}; imm: 0x{self.imm:03x}; rd: {self.rd_addr:02x}; rs1: {self.rs1_addr:02x};")
            case InstTE.FPU:
                cocotb.log.info(f"{self.get_machine_code():08x} ::: I: {self.op_type.name:6} :: op: {self.op.name:8}; imm: 0x{self.imm:03x}; rd: {self.rd_addr:02x}; rs1: {self.rs1_addr:02x}; rs2: {self.rs2_addr:02x}; rs3: {self.rs3_addr:02x}; extra: {self.extra:01x};")
            case _:
                cocotb.log.warning(f"Nothing to print")

class CISI(CoreInstItem):
    def __init__(self,
                 op: StoreOpTE,
                 rs1_addr: int,
                 rs2_addr: int,
                 rd_addr: int,
                 imm: int, # Исправлено: imm: int
                 op_type = InstTE.STORE,
                 ):
        super().__init__(op_type=op_type,
                         op=op,
                         rs1_addr=rs1_addr,
                         rs2_addr=rs2_addr,
                         rd_addr=rd_addr,
                         imm=imm)

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
        super().__init__(op_type=op_type,
                         op=op,
                         rs1_addr=arg1_addr,
                         rs2_addr=arg2_addr,
                         rs3_addr=arg3_addr,
                         rd_addr=argr_addr,
                         extra=extra,
                         imm=imm)

class CIUI(CoreInstItem):
    def __init__(self,
                 op: UPPopTE,
                 imm: int,
                 rd_addr: int,
                 op_type=InstTE.UPP):
        super().__init__(op_type=op_type,
                         imm=imm,
                         rd_addr=rd_addr,
                         op=op)

class CILI(CoreInstItem):
    def __init__(self,
                 op: LoadOpTE,
                 rs1_addr: int,
                 rd_addr: int,
                 imm: int, # Исправлено: imm: int
                 op_type = InstTE.LOAD,
                 ):
        super().__init__(op_type=op_type,
                         rs1_addr=rs1_addr,
                         rd_addr=rd_addr,
                         imm=imm,
                         op=op)