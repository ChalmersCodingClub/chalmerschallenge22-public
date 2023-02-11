import sys
from random import randint, seed

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))
A1Max = int(cmdlinearg('A1Max', 1e9))
B1Max = int(cmdlinearg('B1Max', 1e9))
A2Max = int(cmdlinearg('A2Max', 1e9))
B2Max = int(cmdlinearg('B2Max', 1e9))

a1 = randint(0, A1Max)
b1 = randint(0, B1Max)
a2 = randint(0, A2Max)
b2 = randint(0, B2Max)

print(a1, b1, a2, b2)
