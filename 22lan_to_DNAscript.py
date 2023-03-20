#!/usr/bin/env python3
from pathlib import Path
import random
import argparse


from lan22.langs.base import BasicGenerator, Lan22Parser, Lan22Tree
from libs.language_definision import LanguageDefinision


class DNAscriptGenerator(BasicGenerator[Lan22Tree]):
    def __init__(self, debug_level=0):
        super().__init__()
        self.debug_level = debug_level
        self.code = ""
        with open(Path(__file__).parent / "DNAscript_codetable.csv", "r", encoding="utf8") as file:
            self.language_definision = LanguageDefinision(file)

    def BASE32(self, node: str):
        for char in node:
            self.code += random.choice(self.language_definision.b32char_to_triplets[char])

    def INSTRUCTION(self, node: str):
        self.code += random.choice(self.language_definision.inst_to_triplets[node])

    def dumps(self) -> str:
        return self.code


def main():
    argument_parser = argparse.ArgumentParser(
        description="convert 22lan source code to DNAscript code", prog="22lan_to_DNAscript.py"
    )
    argument_parser.add_argument("-s", "--source", help="source file", required=True)
    argument_parser.add_argument("-o", "--output", help="output filename (in result folder)")
    argument_parser.add_argument("-d", "--debug", help="enable debug output", type=int, default=0)
    args = argument_parser.parse_args()

    if args.output is None:
        args.output = Path(args.source).with_suffix(".dna")

    generator = DNAscriptGenerator()
    with open(args.source, "r", encoding="utf8") as infile:
        lan22_parser = Lan22Parser()
        generator.from_tree(lan22_parser.parse(infile.read()))

    with open(args.output, "w", encoding="utf8") as outfile:
        generator.dump(outfile)


if __name__ == "__main__":
    main()
