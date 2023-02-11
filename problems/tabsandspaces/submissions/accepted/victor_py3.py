#!/usr/bin/env python3
from sys import stderr

lengths = {}

for _ in range(int(input())):
    for _ in range(int(input())):
        a = int(input())
        if a in lengths:
            lengths[a] += 1
        else:
            lengths[a] = 1

if 0 in lengths:
    lengths.pop(0)
# print(lengths, file=stderr)

if len(lengths):
    best = 0
    bestl = 1
    for i in range(1, max(lengths) + 1):
        a = 0
        # print(i, file=stderr)

        for l in lengths:
            a += (l - l // i - l % i) * lengths[l]

        if best < a:
            bestl = i
            best = a

    print(bestl)
    print(best)
else:
    print(1, 0, sep="\n")
