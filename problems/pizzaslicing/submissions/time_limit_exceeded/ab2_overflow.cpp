#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()

ll gcd(ll a, ll b) {
    while (a != 0) {
        ll t = b % a;
        b = a;
        a = t;
    }
    return b;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    ll N, A, B; cin >> N >> A >> B;
    ll d = gcd(A, B);
    A /= d; B /= d;
    ll s = sqrt(N / (A*B));
    if (s != 0) {
        while (A*B*s*s < N) s++;
        A *= s;
        B *= s;
    }
    ll ans = 0;
    if (__builtin_popcountll(A) == 1) {
        ans += __builtin_ctzll(A);
    } else {
        ans += 64 - __builtin_clzll(A);
    }
    if (__builtin_popcountll(B) == 1) {
        ans += __builtin_ctzll(B);
    } else {
        ans += 64 - __builtin_clzll(B);
    }
    cout << ans << endl;
}
