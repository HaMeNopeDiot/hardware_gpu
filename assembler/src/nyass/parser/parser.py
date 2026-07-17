
from nyass.parser import Instruction, NyassLoader
from lark import Lark
from pathlib import Path

grammar = Path(Path(__file__).parent, "grammar.g4")
with open(grammar, "r") as file:
    grammar = file.read()
parser = Lark(grammar, ambiguity="explicit", propagate_positions=True)

def parse(source_text: str) -> list[Instruction]:
    ast = parser.parse(source_text)
    return NyassLoader().transform(ast)
