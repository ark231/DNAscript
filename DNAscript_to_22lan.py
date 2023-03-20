#!/usr/bin/env python3
from pathlib import Path
import random
import argparse


from libs.language_definision import LanguageDefinision
from lan22.libs.common import Code as Lan22Code


def main():
    argument_parser = argparse.ArgumentParser(
        description="convert DNAscript source code to 22lan code", prog="DNAscript_to_22lan.py"
    )
    argument_parser.add_argument("-s", "--source", help="source file", required=True)
    argument_parser.add_argument("-o", "--output", help="output filename (in result folder)")
    argument_parser.add_argument("-d", "--debug", help="enable debug output", type=int, default=0)
    args = argument_parser.parse_args()

    if args.output is None:
        args.output = Path(args.source).with_suffix(".22l")

    with open(Path(__file__).parent / "DNAscript_codetable.csv", "r", encoding="utf8") as file:
        language_definision = LanguageDefinision(file)
    with open(args.source, "r", encoding="utf8") as infile:
        is_in_function = False
        code = Lan22Code()
        base32_str = ""
        while True:
            triplet = infile.read(3)
            if triplet == "":
                break
            if is_in_function:
                inst = language_definision.triplet_to_inst[triplet]
                if inst == "endfunc":
                    is_in_function = False
                    code.set_indent("")
                elif len(inst.split(",")) > 1:
                    inst = inst.split(",")[0]
                code.add_line(inst)
            else:
                b32char = language_definision.triplet_to_b32char[triplet]
                if b32char == "EOS":
                    code.add_line(base32_str)
                    code.add_line(language_definision.triplet_to_inst[triplet].split(",")[1])
                    code.set_indent("    ")
                    base32_str = ""
                    is_in_function = True
                else:
                    base32_str += b32char

    with open(args.output, "w", encoding="utf8") as outfile:
        outfile.write(code.as_str())


if __name__ == "__main__":
    main()
