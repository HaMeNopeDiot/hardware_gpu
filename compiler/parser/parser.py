from lark import Lark
from model.code import Code


class Parser:
    def __init__(self) -> None:
        with open("parser/nir.g4", "r") as file:
            self.__parser = Lark(file.read(), ambiguity="explicit")

    def parse(self, source_code: str) -> Code:
        self.__parser.parse(source_code)
        return Code()
