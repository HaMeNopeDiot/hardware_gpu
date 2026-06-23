from sys import byteorder

from instruction import Instruction


class Assembler:
    DEFINITIONS = {
        # ubo_base should be the beginning of the vertex_buffer.mem file
        "ubo_base": 0x0000_0000,
        #
        # It is within the vertex_buffer.mem file (don't change last 4 numbers, i mean these -> _00B0)
        "in_position_base": 0x0000_00B0,
        "in_position_stride": 0x000_0010,
        #
        # It is within the vertex_buffer.mem file (don't change last 4 numbers, i mean these -> _0230)
        "in_color_base": 0x0000_0230,
        "in_color_stride": 0x0000_0010,
        #
        # It is within the vertex_buffer.mem file (don't change last 4 numbers, i mean these -> _03B0)
        "in_normal_base": 0x0000_03B0,
        "in_normal_stride": 0x0000_0010,
        #
        # I will not have any time to properly integrate your core into the llvmpipe, so set numbers below to whatever you want
        #
        ".gl_Position_base": 0x2000_0000,
        ".gl_Position_stride": 0x0000_00C0,
        #
        "vVaryingColor_base": 0x2000_0010,
        "vVaryingColor_stride": 0x000_00C0,
        #
        "stack_base": 0x3000_0000,
        "stack_size": 0x0000_0100,
    }

    REGISTER_NAMES = {
        "x0": 0,
        "zero": 0,
        "x1": 31,
        "v_id": 31,
        "x2": 2,
        "sp": 2,
        "x3": 3,
        "x4": 4,
        "x5": 5,
        "x6": 6,
        "x7": 7,
        "x8": 8,
        "x9": 9,
        "x10": 10,
        "x11": 11,
        "x12": 12,
        "x13": 13,
        "x14": 14,
        "x15": 15,
        "x16": 16,
        "x17": 17,
        "x18": 18,
        "x19": 19,
        "x20": 20,
        "x21": 21,
        "x22": 22,
        "x23": 23,
        "x24": 24,
        "x25": 25,
        "x26": 26,
        "x27": 27,
        "x28": 28,
        "x29": 29,
        "x30": 30,
        "x31": 1,
    }

    INSTRUCTION_OPCODES = {
        "lw":       0b010_0000, # L
        "sw":       0b110_0000, # S
        "lui":      0b000_0000, # U
        "addi":     0b010_0001, # L
        "fadd":     0b100_0010, # F
        "fmul":     0b100_0011, # F
        "fdiv":     0b100_0100, # F
        "fsqrt":    0b100_0101, # F
        "fneg":     0b100_0110, # F
        "fmax":     0b100_0111, # F
        "add":      0b110_0001, # S
        "mul":      0b110_0010, # S
        "ret":      0b000_0001, # U
    }

    def __init__(self) -> None:
        self.binary = b""

    def assemble(self, source_code: list[Instruction]) -> bytes:
        """
        Per instruction in the source code calls the method with the same name as its opcode
        """
        for instr in source_code:
            method = getattr(self, instr.opcode, None)
            if callable(method):
                method(instr)
            else:
                print(f"Instruction code not recognised: {instr}")
                exit(1)

        return self.binary

    # instruction macros
    def li(self, instr: Instruction):
        rd = self.REGISTER_NAMES[instr.result]
        imm = instr.args[0]
        if imm[:2] == "0x":
            imm = int(imm, base=16)
        else:
            imm = self.DEFINITIONS[imm]

        rs1 = self.REGISTER_NAMES["zero"]
        is_set = False
        if imm.bit_length() > 12:
            # lui
            self.__U_type_instruction(
                opcode=self.INSTRUCTION_OPCODES["lui"],
                rd=rd,
                imm=(imm >> 12),
            )
            rs1 = rd
            is_set = True

        if (imm & 0xFFF) != 0 or not is_set:
            # addi
            self.__L_type_instruction(
                opcode=self.INSTRUCTION_OPCODES["addi"],
                rd=rd,
                rs1=rs1,
                imm=imm & 0xFFF,
            )

    # instruction
    def lw(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        imm = int(instr.args[1], base=10)

        self.__L_type_instruction(
            opcode=opcode,
            rs1=rs1,
            rd=rd,
            imm=imm,
        )

    def sw(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rs1 = self.REGISTER_NAMES[instr.args[1]]
        rs2 = self.REGISTER_NAMES[instr.args[0]]
        imm = int(instr.args[2], base=10)

        self.__S_type_instruction(
            opcode=opcode,
            rs1=rs1,
            rs2=rs2,
            imm=imm,
        )

    def lui(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        imm = int(instr.args[0], base=16)

        self.__U_type_instruction(
            opcode=opcode,
            imm=imm,
        )

    def fadd(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1, rs2=rs2)

    def fmul(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1, rs2=rs2)

    def fdiv(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1, rs2=rs2)

    def fsqrt(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1)

    def fneg(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1)

    def fmax(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__F_type_instruction(opcode=opcode, rd=rd, rs1=rs1, rs2=rs2)

    def addi(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        imm = int(instr.args[1], base=16)

        self.__L_type_instruction(
            opcode=opcode,
            rd=rd,
            rs1=rs1,
            imm=imm,
        )

    def add(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__S_type_instruction(
            opcode=opcode,
            rs1=rs1,
            rs2=rs2,
            rd=rd,
        )

    def mul(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        rd = self.REGISTER_NAMES[instr.result]
        rs1 = self.REGISTER_NAMES[instr.args[0]]
        rs2 = self.REGISTER_NAMES[instr.args[1]]

        self.__S_type_instruction(
            opcode=opcode,
            rs1=rs1,
            rs2=rs2,
            rd=rd,
        )

    def ret(self, instr: Instruction):
        opcode = self.INSTRUCTION_OPCODES[instr.opcode]
        self.__U_type_instruction(
            opcode=opcode,
        )

    # instruction types
    #
    def __L_type_instruction(
        self, imm: int = 0, rs1: int = 0, rd: int = 0, opcode: int = 0
    ):
        assert (
            imm.bit_length() <= 15
            and rd.bit_length() <= 5
            and rs1.bit_length() <= 5
            and opcode.bit_length() <= 7
        ), "One of the elements requires more bits, than the instruction type allows"
        code = (opcode << 25) | (rd << 20) | (rs1 << 15) | (imm << 0)
        self.binary += code.to_bytes(4, byteorder="little", signed=False)

    def __F_type_instruction(
        self,
        imm: int = 0,
        extra: int = 0,
        rd: int = 0,
        rs3: int = 0,
        rs2: int = 0,
        rs1: int = 0,
        opcode: int = 0,
    ):
        assert (
            imm.bit_length() <= 10
            and extra.bit_length() <= 3
            and rd.bit_length() <= 5
            and rs3.bit_length() <= 5
            and rs2.bit_length() <= 5
            and rs1.bit_length() <= 5
            and opcode.bit_length() <= 7
        ), "One of the elements requires more bits, than the instruction type allows"
        code = (
            (opcode << 25)
            | (rs1 << 20)
            | (rs2 << 15)
            | (rs3 << 10)
            | (rd << 5)
            | (extra << 2)
            | (imm << 0)
        )
        self.binary += code.to_bytes(4, byteorder="little", signed=False)

    def __S_type_instruction(
        self, imm: int = 0, rd: int = 0, rs2: int = 0, rs1: int = 0, opcode: int = 0
    ):
        assert (
            imm.bit_length() <= 10
            and rd.bit_length() <= 5
            and rs2.bit_length() <= 5
            and rs1.bit_length() <= 5
            and opcode.bit_length() <= 7
        ), "One of the elements requires more bits, than the instruction type allows"
        code = (opcode << 25) | (rd << 20) | (rs2 << 15) | (rs1 << 10) | (imm << 0)
        self.binary += code.to_bytes(4, byteorder="little", signed=False)

    def __U_type_instruction(self, imm: int = 0, rd: int = 0, opcode: int = 0):
        assert (
            imm.bit_length() <= 20 and rd.bit_length() <= 5 and opcode.bit_length() <= 7
        ), "One of the elements requires more bits, than the instruction type allows"
        code = (opcode << 25) | (rd << 20) | (imm << 0)
        self.binary += code.to_bytes(4, byteorder="little", signed=False)