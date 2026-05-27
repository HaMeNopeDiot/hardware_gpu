from instruction import Instruction


class Optimizer:
    def __init__(self) -> None:
        pass

    def optimize(self, source_code: list[Instruction]) -> list[Instruction]:
        """
        - removes duplicate constants load
        - removes duplicate instructions
        - removes dangling instructions
        """
        return self.optimize_loaded_constants(source_code)

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
