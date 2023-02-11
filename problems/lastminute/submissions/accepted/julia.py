#!/usr/bin/env python3
Auniq, Buniq, Areuse, Breuse = [int(q) for q in input().split()]

if Areuse == 0 and Breuse == 0:
    print(min(Auniq, Buniq))
elif Areuse == 0:
    print(Auniq)
elif Breuse == 0:
    print(Buniq)
else:
    print(Auniq + Buniq + Areuse * Breuse)
