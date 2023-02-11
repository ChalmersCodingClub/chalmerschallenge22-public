#!/usr/bin/env python3

au, bu, ar, br = map(int, input().split())

ans = ar*br
if br != 0: ans += au
if ar != 0: ans += bu
if ar == 0 and br == 0: ans += min(au, bu)
print(ans)
