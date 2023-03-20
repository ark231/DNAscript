#!/usr/bin/python3

import csv


class LanguageDefinision:
    inst_to_triplets: dict[str, list[str]]
    triplet_to_inst: dict[str, str]
    b32char_to_triplets: dict[str, list[str]]
    triplet_to_b32char: dict[str, str]

    def __init__(self, infile):
        self.inst_to_triplets = {}
        self.triplet_to_inst = {}
        self.b32char_to_triplets = {}
        self.triplet_to_b32char = {}

        reader = csv.reader(infile)
        header = next(reader)
        col_triplet = header.index("triplet")
        col_inst = header.index("inst")
        col_b32char = header.index("b32char")
        for row in reader:
            triplet = row[col_triplet]
            inst = row[col_inst]
            b32char = row[col_b32char]
            for sub_inst in inst.split(","):
                if sub_inst not in self.inst_to_triplets:
                    self.inst_to_triplets[sub_inst] = [triplet]
                else:
                    self.inst_to_triplets[sub_inst].append(triplet)
            self.triplet_to_inst[triplet] = inst
            if b32char not in self.b32char_to_triplets:
                self.b32char_to_triplets[b32char] = [triplet]
            else:
                self.b32char_to_triplets[b32char].append(triplet)
            self.triplet_to_b32char[triplet] = b32char


if __name__ == "__main__":
    import sys

    with open(sys.argv[1], "r", encoding="utf-8") as infile:
        definition = LanguageDefinision(infile)
    print(f"i2t: {definition.inst_to_triplets}")
    print(f"t2i: {definition.triplet_to_inst}")
    print(f"b2t: {definition.b32char_to_triplets}")
    print(f"t2b: {definition.triplet_to_b32char}")
