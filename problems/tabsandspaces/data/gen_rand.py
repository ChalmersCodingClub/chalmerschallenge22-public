import sys
from random import randint, seed
seed(int(sys.argv[1]))

f = randint(1, 10)
print(f)
for i in range(f):
    n = randint(1, 20)
    print(n)
    for j in range(n):
        print(randint(0, 79))

