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
sort_type = cmdlinearg('sortType', 'no')
assert sort_type in ['no', 'sort', 'rev', 'almostsort', 'almostrev']

a = [random.randint(1, max_a) for i in range(n)]

if 'sort' in sort_type:
    a.sort()
elif 'rev' in sort_type:
    a.sort()
    a.reverse()
if 'almost' in sort_type:
    for i in range(n):
        x = random.randrange(n)
        y = min(max(0, x + random.randint(-4, 4)), n-1)
        a[x], a[y] = a[y], a[x]


print(n)
print(*a)
