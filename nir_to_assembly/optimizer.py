from instruction import Instruction


class Optimizer:
    def __init__(self) -> None:
        pass

    def optimize(self, source_code: list[Instruction]) -> list[Instruction]:
        """
        - removes duplicate constants load
        - removes loading and references to constant 0 to a reference to a register zero (x0)
        - removes duplicate instructions
        - optimizes operations with zero(x0)
        - removes dangling instructions
        """
        target_code = self.optimize_loaded_constants(source_code)
        target_code = self.remove_constant_zero(target_code)
        target_code = self.remove_duplicate_instructions(target_code)
        target_code = self.optimize_zero_operations(target_code)
        target_code = self.remove_dangling_instructions(target_code)
        return target_code

    def optimize_loaded_constants(
        self, source_code: list[Instruction]
    ) -> list[Instruction]:
        """
        Removes duplicate constants loading
        """
        target_code = []
        loaded_constants: dict[str, str] = dict()
        substitute_result_indeces: dict[str, str] = dict()
        for instr in source_code:
            if instr.opcode == "li":
                if instr.args[0] in loaded_constants:
                    equivalent_instr_result = loaded_constants[instr.args[0]]
                    substitute_result_indeces[instr.result] = equivalent_instr_result
                else:
                    target_code.append(instr)
                    loaded_constants[instr.args[0]] = instr.result
            else:
                target_code.append(instr)
                for i in range(len(instr.args)):
                    if instr.args[i] in substitute_result_indeces:
                        instr.args[i] = substitute_result_indeces[instr.args[i]]

        return target_code

    def remove_constant_zero(self, source_code: list[Instruction]) -> list[Instruction]:
        """
        Removes loading and references to constant 0 to a reference to a register zero (x0)
        """
        target_code = []
        constant_zero = ""
        for instr in source_code:
            if instr.opcode == "li":
                if instr.args[0] == "0x00000000":
                    constant_zero = instr.result
                else:
                    target_code.append(instr)
            else:
                for i in range(len(instr.args)):
                    if instr.args[i] == constant_zero:
                        instr.args[i] = "zero"
                target_code.append(instr)

        return target_code

    def remove_duplicate_instructions(
        self, source_code: list[Instruction]
    ) -> list[Instruction]:
        """
        Removes duplicate instructions
        """
        target_code = []
        originals: dict[str, Instruction] = dict()
        substitute: dict[str, str] = dict()

        for instr in source_code:
            src_string = f"{instr.opcode} " + ", ".join(instr.args)
            if src_string in originals:
                orig = originals[src_string]
                substitute[instr.result] = orig.result
            else:
                originals[src_string] = instr
                for i in range(len(instr.args)):
                    if instr.args[i] in substitute:
                        instr.args[i] = substitute[instr.args[i]]

                target_code.append(instr)

        return target_code

    def remove_dangling_instructions(
        self, source_code: list[Instruction]
    ) -> list[Instruction]:
        """
        Removes dangling instruction with opcodes that are not used or without useful side effects
        """
        # this adds all arguments, even unrelated, but whatever, good enough
        used_codes = set()
        for instr in source_code:
            for arg in instr.args:
                used_codes.add(arg)

        target_code = []
        for instr in source_code:
            if instr.result in used_codes:
                target_code.append(instr)
            elif instr.opcode == "sw":
                target_code.append(instr)
            elif instr.opcode == "ret":
                target_code.append(instr)

        return target_code

    def optimize_zero_operations(
        self, source_code: list[Instruction]
    ) -> list[Instruction]:
        """
        Optimizes operations with zero(x0)
        """
        target_code = []
        substitute: dict[str, str] = dict()

        for instr in source_code:
            contains_zero = False
            for arg in instr.args:
                if arg == "zero":
                    contains_zero = True

            if contains_zero and (instr.opcode == "add" or instr.opcode == "fadd"):
                other_arg = [arg for arg in instr.args if arg != "zero"][0]
                substitute[instr.result] = other_arg
            elif contains_zero and (instr.opcode == "mul" or instr.opcode == "fmul"):
                substitute[instr.result] = "zero"
            else:
                for i in range(len(instr.args)):
                    if instr.args[i] in substitute:
                        instr.args[i] = substitute[instr.args[i]]

                target_code.append(instr)

        return target_code
