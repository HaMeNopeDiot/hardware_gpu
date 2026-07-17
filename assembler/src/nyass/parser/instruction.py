from dataclasses import dataclass

@dataclass(frozen=True)
class Instruction:
    opcode: str
    result: str
    args: list
