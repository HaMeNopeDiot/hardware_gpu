import argparse
from dataclasses import dataclass

from nyass.parser import parse
from nyass.assembler import Assembler

@dataclass
class CLIArguments:
    source_file: str
    target_file: str
    binary_output: bool


def get_args() -> CLIArguments:
    parser = argparse.ArgumentParser(
        prog="nyass",
        description="Branch-less assembler for the simplified NYA GPU",
    )

    parser.add_argument("source", help="Input assembly file")
    parser.add_argument("-b", "--binary", required=False, action="store_true", help="Output a binary file")
    parser.add_argument("target", default="a.memh", nargs="?", help="Output memh file")

    args = parser.parse_args()
    if args.binary:
        args.target = "a.bin"

    return CLIArguments(
        source_file=args.source,
        target_file=args.target,
        binary_output=args.binary
    )


def main():
    args = get_args()

    source_text = ""
    with open(args.source_file, "r") as file:
        source_text = file.read()

    instructions = parse(source_text)
    asm = Assembler()
    asm.assemble(instructions)

    if args.binary_output:
        with open(args.target_file, "bw") as file:
            file.write(asm.binary)
    else:
        with open(args.target_file, "w") as file:
            file.write(asm.memh)


if __name__ == "__main__":
    main()
