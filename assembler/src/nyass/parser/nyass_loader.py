from nyass.parser import Instruction
from lark import Transformer, Token

class NyassLoader(Transformer):
    def __init__(self, symbols: dict = {}) -> None:
        self.symbols = symbols

    def start(self, tree):
        return [x for x in tree if x is not None]

    def operator(self, tree):
        return tree[0]

    def define(self, tree):
        identifier = tree[0]
        value = tree[1]
        assert identifier.value not in self.symbols, f"L{identifier.line}#{identifier.column}: Identifier was already declared: {identifier.value}"
        self.symbols[identifier.value] = value

    def instr(self, tree):
        return tree[0]

    def noop(self, tree):
        return Instruction(
            opcode="addi",
            result="zero",
            args=["zero", 0]
        )

    def ret(self, tree):
        return Instruction(
            opcode="ret",
            result="zero",
            args=[]
        )

    def li(self, tree):
        return Instruction(
            opcode="li",
            result=tree[0],
            args=tree[1:]
        )

    def mul(self, tree):
        return Instruction(
            opcode="mul",
            result=tree[0],
            args=tree[1:]
        )

    def add(self, tree):
        return Instruction(
            opcode="add",
            result=tree[0],
            args=tree[1:]
        )

    def lw(self, tree):
        return Instruction(
            opcode="lw",
            result=tree[0],
            args=tree[1:]
        )

    def sw(self, tree):
        return Instruction(
            opcode="sw",
            result="zero",
            args=tree
        )

    def lui(self, tree):
        return Instruction(
            opcode="lui",
            result=tree[0],
            args=tree[1:]
        )

    def addi(self, tree):
        return Instruction(
            opcode="addi",
            result=tree[0],
            args=tree[1:]
        )

    def fadd(self, tree):
        return Instruction(
            opcode="fadd",
            result=tree[0],
            args=tree[1:]
        )

    def fmul(self, tree):
        return Instruction(
            opcode="fmul",
            result=tree[0],
            args=tree[1:]
        )

    def fdiv(self, tree):
        return Instruction(
            opcode="fdiv",
            result=tree[0],
            args=tree[1:]
        )

    def fsqrt(self, tree):
        return Instruction(
            opcode="fsqrt",
            result=tree[0],
            args=tree[1:]
        )

    def fneg(self, tree):
        return Instruction(
            opcode="fneg",
            result=tree[0],
            args=tree[1:]
        )

    def fmax(self, tree):
        return Instruction(
            opcode="fmax",
            result=tree[0],
            args=tree[1:]
        )

    def register(self, tree):
        return tree[0]

    def identifier_or_literal(self, tree):
        value = tree[0]
        if isinstance(value, Token):
            assert value.value in self.symbols, f"L{value.line}#{value.column}: Name is not defined: {value.value}"
            return self.symbols[value.value]
        return value

    def integer(self, tree):
        return tree[0]

    def IDENTIFIER(self, token):
        return token

    def REGISTER_INDEX(self, token):
        index = int(token.value[1:])
        assert index >= 0 and index <= 31, f"L{token.line}#{token.column}: Invalid register index: {token.value}"

        return token.value

    def REGISTER_NAMES(self, token):
        return token.value

    def DECIMAL(self, token):
        return int(token.value)

    def HEXADECIMAL(self, token):
        return int(token.value[2:], base=16)
