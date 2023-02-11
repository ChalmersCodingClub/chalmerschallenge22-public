#!/usr/bin/env python3
N, M, K = [int(q) for q in input().split()]

values = [int(a) for a in input().split()]
transported = []
A = []
B = []

for i in range(M):
    a, b = [int(q) for q in input().split()]
    A.append(a)
    B.append(b)
    transported.append(values[a])
    values[b] += values[a]
    values[a] = 0

legal_transport = []
seen_before = set()

for i in range(M-1, -1, -1):
    seen_before.add(A[i])
    if B[i] in seen_before:
        continue
    legal_transport.append(transported[i])

legal_transport.sort()

print(sum(legal_transport[-K:]))
