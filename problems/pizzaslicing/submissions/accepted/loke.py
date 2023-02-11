#!/usr/bin/env python3

from math import gcd

# Apparently Kattis' runs py3.6 which lacks isqrt (from py3.8)
def isqrt(x):
    mini = 0
    maxi = x + 1
    while mini + 1 < maxi:
        mid = (mini + maxi) // 2
        if mid*mid > x:
            maxi = mid
        else:
            mini = mid
    return mini

assert(isqrt(0) == 0)
assert(isqrt(1) == 1)
assert(isqrt(2) == 1)
assert(isqrt(3) == 1)
assert(isqrt(4) == 2)
assert(isqrt(5) == 2)
assert(isqrt(21) == 4)
assert(isqrt(24) == 4)
assert(isqrt(25) == 5)
assert(isqrt(31) == 5)

N, A, B = [int(x) for x in input().split()]

d = gcd(A, B)
A //= d
B //= d

s = isqrt(N // (A*B))
while A*B*s*s < N: s += 1
A *= s
B *= s

ans = 0
while A > 1:
    A -= A // 2;
    ans += 1
while B > 1:
    B -= B // 2
    ans += 1
print(ans)
