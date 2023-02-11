#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << endl
#define sz(x) ((int)(x).size())
#define rep(i, a, b) for(int i = (a); i < int(b); i++)
#define trav(x, a) for(auto& x : a)
typedef unsigned long long ull; 

vi tolist(ull x){
    vi r(64);
    for(int i = 0; i < 64; i++){
        r[63-i] = x&1;
        x >>= 1;
    }
    return r;
}

ull toint(vi x){
    ull r = 0;
    for(int i = 0; i < 64; i++){
        r <<= 1;
        r |= x[i];
    }
    return r;
}

ull step1a(ull x){
    vi X = tolist(x);
    for(int i = 0; i < 256; i++){
        int y = 4*X[32+i%32] + 2*X[32+(i+1)%32] + X[32+(i+5)%32];
        X[32+i%32] = (y == 0 || y == 1 || y == 4 || y == 5 || y == 7);
    }
    x = toint(X);
    return x;
}

pair<ull, ull> split(ull x){
    ull a = 0, b = 0;
    for(int i = 0; i < 64; i++){
        if(i%2 == 0) a |= ((x>>i)&1)<<(i/2);
        else b |= ((x>>i)&1)<<(i/2);
    }
    return {a, b};
}

ull combine(ull a, ull b){
    ull x = 0;
    for(int i = 0; i < 64; i++){
        if(i%2 == 0) x |= ((a>>(i/2))&1)<<i;
        else x |= ((b>>(i/2))&1)<<i;
    }
    return x;
}

ull step1(ull x){
    ull a, b;
    tie(a, b) = split(x);

    a = step1a(a);
    b = step1a(b);

    x = combine(a, b);
    return x;
}

ull step2(ull x){
    for(int i = 0; i < 16; i++){
        ull z = 0;
        for(int i = 0; i < 64; i++){
            z |= ((x>>i)&1)<<(63-i);
        }
        x += z;
        int sh = 0;
        if(x < z) sh = 1;
        x ^= 12157665459056928801ull;
        if(sh){
            x >>= 1;
            x |= (1ull << 63);
        }
    }
    return x;
}

ull Hash(ull x){
    x = step1(x);
    x = step2(x);

    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(4);


    ull inputs[] = {
        267775413,
        21347554,
        27955642,
        53083115,
        262453518,
        80381146,
        169522623,
        72797448,
        26617584,
        34529522
    };
    
    /*
    ull inputs[] = { //sample
        111131462,
        229052375,
        257596593,
        38597773,
        23809983,
        258400715,
        233947578,
        110845532,
        114293771,
        9972238
    };
    */

    double score = 0;
    for(int i = 0; i < 10; i++){
        ull x = inputs[i]; //(rand()^((ll)rand()<<20))%(1<<28);
        //cin >> x;
        x <<= 36;

        ull x1, x2;
        tie(x1, x2) = split(x);
        map<ull, ull> good1;
        for(int i = 0; i < (1<<18); i++){
            ull k = i;
            ull y = step1a(x1^k);
            if(good1.count(y)) continue;
            good1[y] = k;
        }

        map<ull, ull> good2;
        for(int i = 0; i < (1<<18); i++){
            ull k = i;
            ull y = step1a(x2^k);
            if(good2.count(y)) continue;
            good2[y] = k;
        }

        cout << sz(good1) << " " << sz(good2) << endl;

        ull best = ULLONG_MAX;
        ull bestk = 0;
        for(pair<ull, ull> a : good1){
            for(pair<ull, ull> b : good2){
                ull h = step2(combine(a.first, b.first));
                if(h < best){
                    best = h;
                    bestk = combine(a.second, b.second);
                }
            }
        }
        cout << bestk << " " << best << endl;
        score += 10-log2l((long double)best)/6.4;
    }
    debug(score);
}
