#!/usr/bin/env python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
max_a = int(cmdlinearg('aMax'))

a = [min(max_a, random.randint(1,3)) for i in range(n)]

for i in range(max(4, n//(max_a//3))):
    a[random.randrange(len(a))] = max(1, max_a-random.randint(0, 2))

print(n)
print(*a)
