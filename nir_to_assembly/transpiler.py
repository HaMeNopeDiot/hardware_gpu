from instruction import Instruction

"""
lw rd, imm(rs1) : rd = M[rs1+imm]
sw rs2, imm(rs1): M[rs1+imm] = rs2
lui rd,imm      : rd = imm << 20
addi rd,rs1,imm : rd = rs1 + imm
add rd,rs1,imm  : rd = rs1 + imm
mul rd,rs1,rs2  : rd = rs1 * rs2
li rd, imm      : rd = imm
fdiv rd,rs1,rs2 : rd = rs1 / rd2
fneg rd,rs1     : rd = -rs1
fsqrt rd,rs1    : rd = sqrt(rs1)
fmax rd, rs1    : rd =   max(rs1, rs2)
fadd rd,rs1,rs2 : rd = rs1 + rs2
fmul rd,rs1,rs2 : rd = rs1 * rs2
ret
"""


class Transpiler:
    SUBSCRIPTS = "xyzw"
    WORD_SIZE_IN_BYTES = 4

    def __init__(self) -> None:
        self.target_code = []
        self.result_index = 0
        self.dependencies_map = {}

    def _add_instruction(self, opcode: str, args: list):
        self.target_code.append(
            Instruction(
                opcode=opcode, result=self.result_index, result_size=1, args=args
            )
        )
        self.result_index += 1

    def _expand_subscript(self, arg_num: int, arg_subscript: str | None) -> str:
        if arg_subscript is None:
            return f"%{arg_num}"
        else:
            return f"%{arg_num}.{arg_subscript}"

    def _previous_is_result_in_source_code(
        self, result_num: int, result_subscript: str | None
    ):
        self.dependencies_map[self._expand_subscript(result_num, result_subscript)] = (
            f"t{self.result_index - 1}"
        )

    def transpile(self, source_code: list[Instruction]) -> list[Instruction]:
        for instr in source_code:
            method = getattr(self, instr.opcode, None)
            if callable(method):
                method(instr)

        self._add_instruction("ret", [])

        return self.target_code

    def deref_var(self, instr: Instruction) -> None:
        self._add_instruction("li", [f"{instr.args[0]}_base"])
        self._add_instruction("li", [f"{instr.args[0]}_stride"])
        self._add_instruction("mul", ["v_id", f"t{self.result_index - 1}"])
        self._add_instruction(
            "add", [f"t{self.result_index - 3}", f"t{self.result_index - 1}"]
        )
        self._previous_is_result_in_source_code(instr.result, None)

    def load_deref(self, instr: Instruction) -> None:
        if instr.result_size == 1:
            dependency = self.dependencies_map[
                self._expand_subscript(instr.args[0][0], instr.args[0][1])
            ]
            self._add_instruction("lw", [dependency, "0"])
            self._previous_is_result_in_source_code(instr.result, None)
        else:
            for i in range(instr.result_size):
                dependency = self.dependencies_map[
                    self._expand_subscript(instr.args[0][0], instr.args[0][1])
                ]
                self._add_instruction(
                    "lw", [dependency, str(self.WORD_SIZE_IN_BYTES * i)]
                )
                self._previous_is_result_in_source_code(
                    instr.result, self.SUBSCRIPTS[i]
                )

    def load_const(self, instr: Instruction) -> None:
        if instr.result_size == 1:
            self._add_instruction("li", [instr.args[0]])
            self._previous_is_result_in_source_code(instr.result, None)
        else:
            for i in range(instr.result_size):
                self._add_instruction("li", [instr.args[i]])
                self._previous_is_result_in_source_code(
                    instr.result, self.SUBSCRIPTS[i]
                )

    def load_const_buf_base_addr_lvp(self, instr: Instruction) -> None:
        self._add_instruction("li", ["ubo_base"])
        self._previous_is_result_in_source_code(instr.result, None)

    def load_ubo(self, instr: Instruction) -> None:
        depend_base = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        depend_offset = self.dependencies_map[
            self._expand_subscript(instr.args[1][0], instr.args[1][1])
        ]
        self._add_instruction("add", [depend_base, depend_offset])
        if instr.result_size == 1:
            self._add_instruction("lw", [f"t{self.result_index - 1}", "0"])
            self._previous_is_result_in_source_code(instr.result, None)
        else:
            for i in range(instr.result_size):
                self._add_instruction(
                    "lw",
                    [f"t{self.result_index - 1}", str(self.WORD_SIZE_IN_BYTES * i)],
                )
                self._previous_is_result_in_source_code(
                    instr.result, self.SUBSCRIPTS[i]
                )

    def fmul(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        depend_op2 = self.dependencies_map[
            self._expand_subscript(instr.args[1][0], instr.args[1][1])
        ]
        self._add_instruction("fmul", [depend_op1, depend_op2])
        self._previous_is_result_in_source_code(instr.result, None)

    def fmax(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        depend_op2 = self.dependencies_map[
            self._expand_subscript(instr.args[1][0], instr.args[1][1])
        ]
        self._add_instruction("fmax", [depend_op1, depend_op2])
        self._previous_is_result_in_source_code(instr.result, None)

    def fadd(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        depend_op2 = self.dependencies_map[
            self._expand_subscript(instr.args[1][0], instr.args[1][1])
        ]
        self._add_instruction("fadd", [depend_op1, depend_op2])
        self._previous_is_result_in_source_code(instr.result, None)

    def fdiv(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        depend_op2 = self.dependencies_map[
            self._expand_subscript(instr.args[1][0], instr.args[1][1])
        ]
        self._add_instruction("fdiv", [depend_op1, depend_op2])
        self._previous_is_result_in_source_code(instr.result, None)

    def fneg(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        self._add_instruction("fneg", [depend_op1])
        self._previous_is_result_in_source_code(instr.result, None)

    def fsqrt(self, instr: Instruction) -> None:
        depend_op1 = self.dependencies_map[
            self._expand_subscript(instr.args[0][0], instr.args[0][1])
        ]
        self._add_instruction("fsqrt", [depend_op1])
        self._previous_is_result_in_source_code(instr.result, None)

    def store_deref(self, instr: Instruction) -> None:
        depends_on = [
            self.dependencies_map[self._expand_subscript(arg[0], arg[1])]
            for arg in instr.args[:-1]
        ]
        for i in range(instr.result_size):
            self._add_instruction(
                "sw",
                [
                    depends_on[i],
                    depends_on[instr.result_size],
                    str(self.WORD_SIZE_IN_BYTES * i),
                ],
            )
