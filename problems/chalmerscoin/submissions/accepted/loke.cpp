#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef pair<u64, u64> pii;
typedef vector<u64> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

constexpr u64 POW3_40 = 12157665459056928801ull;

unsigned char byteswap[256];

u64 at(u64 x, u64 idx) {
    return (x >> (63 - idx)) & 1;
}

u64 h(u64 x) {
    rep(i, 0, 512) {
        u64 a = at(x, i % 64);
        u64 b = at(x, (i+2) % 64);
        u64 c = at(x, (i+10) % 64);
        u64 val = (!b) | (a & b & c);
        u64 mask = 1ull << (63 - i % 64);
        x = ((~mask) & x) | (val << (63 - i % 64));
    }
    rep(i, 0, 16) {
        u64 xflip = __builtin_bswap64(x);
        xflip = byteswap[xflip & 0xFF]
            | ((u64)byteswap[(xflip >> 8) & 0xFF] << 8)
            | ((u64)byteswap[(xflip >> 16) & 0xFF] << 16)
            | ((u64)byteswap[(xflip >> 24) & 0xFF] << 24)
            | ((u64)byteswap[(xflip >> 32) & 0xFF] << 32)
            | ((u64)byteswap[(xflip >> 40) & 0xFF] << 40)
            | ((u64)byteswap[(xflip >> 48) & 0xFF] << 48)
            | ((u64)byteswap[(xflip >> 56) & 0xFF] << 56);
        __uint128_t xx = ((__uint128_t)x + (__uint128_t)xflip) ^ POW3_40;
        if ((xx >> 64) != 0) {
            xx >>= 1;
        }
        x = xx;
    }
    return x;
}
u32 comp_xpart(u32 xpart) {
    rep(i1, 0, 16) {
        u32 a = (xpart >> 16) & 0xFFFF; // 16-31
        u32 b = (xpart >> 15) & 0xFFFF; // 15-30
        u32 c = (xpart >> 11) & 0xFFFF; // 11-26
        u32 val = ((~b) | (a & b & c)) & 0xFFFF;
        xpart = (0xFFFF & xpart) | (val << 16);
        xpart = (xpart << 16) | (xpart >> 16);
    }
    return xpart;
}
u64 comp_hash(u32 xeven, u32 xodd) {
    u64 x = 0;
    rep(i, 0, 32) {
        x |= (u64)((xeven >> i) & 1) << (2*i);
        x |= (u64)((xodd >> i) & 1) << (2*i + 1);
    }
    rep(i, 0, 16) {
        u64 xflip = __builtin_bswap64(x);
        xflip = byteswap[xflip & 0xFF]
            | ((u64)byteswap[(xflip >> 8) & 0xFF] << 8)
            | ((u64)byteswap[(xflip >> 16) & 0xFF] << 16)
            | ((u64)byteswap[(xflip >> 24) & 0xFF] << 24)
            | ((u64)byteswap[(xflip >> 32) & 0xFF] << 32)
            | ((u64)byteswap[(xflip >> 40) & 0xFF] << 40)
            | ((u64)byteswap[(xflip >> 48) & 0xFF] << 48)
            | ((u64)byteswap[(xflip >> 56) & 0xFF] << 56);

        u64 res;
        bool overflow = __builtin_uaddll_overflow(x, xflip, &res);
        x = ((res ^ POW3_40) >> overflow) | ((u64)overflow << 63);
    }
    return x;
}

int main() {
    rep(i, 0, 256) {
        unsigned char flip = 0;
        rep(j, 0, 8) {
            flip <<= 1;
            flip |= (i >> j) & 1;
        }
        byteswap[i] = flip;
    }
    assert(h(0) == 11282101816170131660ull);
    assert(h(1) == 10851337527331582652ull);
    assert(h(2) == 16398292305311270485ull);
    assert(h(3) == 3485837508360375368ull);

    rep(i, 0, 10) {
        unordered_map<u32, u32> xeven_out;
        unordered_map<u32, u32> xodd_out;
        u64 x; cin >> x;
        // 14 bits each
        u32 xeven_high_in = 0;
        u32 xodd_high_in = 0;
        rep(i, 0, 14) {
            xeven_high_in |= ((x >> (2*i)) & 1) << i;
            xodd_high_in |= ((x >> (2*i + 1)) & 1) << i;
        }
        // we brute lower 18 bits of xeven and xodd
        rep(x_low_in, 0, 1<<18) {
            u32 yeven = comp_xpart((xeven_high_in << 18) | x_low_in);
            u32 yodd = comp_xpart((xodd_high_in << 18) | x_low_in);
            if (!xeven_out.count(yeven)) {
                xeven_out[yeven] = x_low_in;
            }
            if (!xodd_out.count(yodd)) {
                xodd_out[yodd] = x_low_in;
            }
        }
        u64 best_score = ~0;
        u64 best_key = -1;
        trav(i, xeven_out) {
            trav(j, xodd_out) {
                u64 h = comp_hash(i.first, j.first);
                if (h < best_score) {
                    best_score = h;
                    best_key = 0;
                    rep(k, 0, 18) {
                        best_key |= (u64)((i.second >> k) & 1) << (2*k);
                        best_key |= (u64)((j.second >> k) & 1) << (2*k + 1);
                    }
                }
            }
        }
        assert(h((x << 36) | best_key) == best_score);
        cout << best_key << endl;
    }
}
