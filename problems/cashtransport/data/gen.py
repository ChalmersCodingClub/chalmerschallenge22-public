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
n_max = int(cmdlinearg('n_max', 3*10**5))
m_max = int(cmdlinearg('m_max', 3*10**5))
k_max = int(cmdlinearg('k_max', 3*10**5))

def random_balance():
    return random.randint(0, 10**random.randint(1, 9))

N = random.randint(2, n_max)
M = random.randint(1, m_max)
K = random.randint(1, min(k_max, M))
print(N, M, K)
print(" ".join(str(random_balance()) for _ in range(N)))
for i in range(M):
    a = random.randrange(N)
    b = random.randrange(N)
    while b == a:
        b = random.randrange(N)
    print(a, b)
