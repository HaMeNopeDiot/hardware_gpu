from instruction import Instruction
from lark import Token, Transformer, Tree


class NirCodeLoader(Transformer):
    """
    This is ASS
    """

    def size(self, tree):
        size = tree[0].value.split("x")
        if len(size) == 1:
            size = 1
        else:
            size = int(size[1])

        return size

    def DEPENDENCY(self, tree):
        return int(tree[1:])

    def SUBSCRIPT(self, tree):
        return tree.value

    def PARAMETER(self, tree):
        return tree.value[1:]

    def LITERAL(self, tree):
        return tree
        if "0x" in tree:
            return int(tree, base=16)
        elif "." in tree:
            return float(tree)
        else:
            return int(tree)

    def list_of_literals(self, tree):
        if len(tree) == 1:
            return tree
        else:
            return tree[0] + [tree[1]]

    def expanded_dependency(self, tree):
        return tree[0]

    def notated_dependency(self, tree):
        parsed_value = None
        if len(tree) == 1:
            parsed_value = (tree[0], None)
        else:
            parsed_value = (tree[0], tree[1])
        return parsed_value

    def deref_var(self, tree):
        return ("deref_var", tree)

    def load_deref(self, tree):
        return ("load_deref", tree)

    def load_const(self, tree):
        if isinstance(tree[0], list):
            return ("load_const", tree[0])
        else:
            return ("load_const", tree)

    def load_const_buf_base_addr_lvp(self, tree):
        return ("load_const_buf_base_addr_lvp", tree)

    def load_ubo(self, tree):
        return ("load_ubo", tree[0:2])

    def fmul(self, tree):
        return ("fmul", tree)

    def fadd(self, tree):
        return ("fadd", tree)

    def fdiv(self, tree):
        return ("fdiv", tree)

    def fneg(self, tree):
        return ("fneg", tree)

    def fsqrt(self, tree):
        return ("fsqrt", tree)

    def fmax(self, tree):
        return ("fadd", tree)

    def store_deref(self, tree):
        return ("store_deref", tree[0:6])

    def opcode_and_arguments(self, tree):
        return tree[0]

    def instruction(self, tree):
        return Instruction(
            opcode=tree[2][0], result=tree[1], result_size=tree[0], args=tree[2][1]
        )

    def start(self, tree):
        return tree
