class Instruction:
    def __init__(self, opcode: str, result: str, result_size: int, args: list) -> None:
        self.opcode = opcode
        self.result = result
        self.result_size = result_size
        self.args = args

    def __str__(self) -> str:
        if self.opcode == "lw":
            return f"{self.result:<4} = {self.opcode} {self.args[1]}({self.args[0]})"
        elif self.opcode == "sw":
            return f"{self.result:<4} = {self.opcode} {self.args[0]}, {self.args[2]}({self.args[1]})"
        elif self.opcode == "ret":
            return f"       {self.opcode}"
        else:
            return f"{self.result:<4} = {self.opcode} " + ", ".join(self.args)

    def __repr__(self) -> str:
        return self.__str__()
