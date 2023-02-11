def p(x):
    print(*x, sep="")

def hash(x):
    # int to list of bits
    def tolist(x):
        return [(x>>i)&1 for i in range(63, -1, -1)]

    # list of bits to int
    def toint(x):
        return sum([x[63-i]<<i for i in range(0, 64)])

    assert 0 <= x < 2**64
    x = tolist(x)
    for i in range(512):
        y = 4*x[i%64] + 2*x[(i+2)%64] + x[(i+10)%64]
        x[i%64] = [1,1,0,0,1,1,0,1][y]
    x = toint(x)
    for i in range(16):
        x += toint(tolist(x)[::-1])
        x ^= 3**40
        if(x >= 2**64): x >>= 1
    assert 0 <= x < 2**64
    return x
