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

a = [max(1, max_a-random.randint(0,2)) for i in range(n)]

print(n)
print(*a)
