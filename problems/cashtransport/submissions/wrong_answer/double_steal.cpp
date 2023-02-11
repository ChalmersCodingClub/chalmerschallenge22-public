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

// Steal from A twice if we have transports A -> B -> C, i.e.
// we duplicate the money we steal instead of removing it from the truck.
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int N, M, K; cin >> N >> M >> K;
    vi a(N);
    rep(i, 0, N) {
        cin >> a[i];
    }
    vi steal(M);
    rep(i, 0, M) {
        int x, y; cin >> x >> y;
        steal[i] = a[x];
        a[y] += a[x];
        a[x] = 0;
    }
    sort(rall(steal));
    ll ans = 0;
    rep(i, 0, min(M, K)) {
        ans += steal[i];
    }
    cout << ans << endl;
}
