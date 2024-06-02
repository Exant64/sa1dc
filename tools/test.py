#!/usr/bin/env python3

with open("1st_read_src_labels.txt", "r") as file:
    lines = file.readlines()
    for line in lines:
        spl = line.split("=")
        print(spl[1][:-1] + " = " + spl[0] + ";")