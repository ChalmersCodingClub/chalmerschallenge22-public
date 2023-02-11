import sys
from random import seed, randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

seed(int(cmdlinearg('seed', sys.argv[-1])))
MaxD = int(cmdlinearg('MaxD', 10**4))
MaxAB = int(cmdlinearg('MaxAB', 10**18))
MaxN = int(cmdlinearg('MaxN', 10**18))

MaxABd = 10**18

d = randint(1, MaxD)
MaxAB = min(MaxAB, MaxABd//d)

A = d*randint(1, MaxAB)
B = d*randint(1, MaxAB)
N = randint(2, MaxN)

print(N, A, B)
