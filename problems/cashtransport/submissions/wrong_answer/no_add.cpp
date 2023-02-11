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

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    int N, M, K; cin >> N >> M >> K;
    vi a(N);
    rep(i, 0, N) {
        cin >> a[i];
    }
    vi transported(M);
    vi x(M);
    vi y(M);
    vector<bool> outgoing(N);
    rep(i, 0, M) {
        cin >> x[i] >> y[i];
        transported[i] = a[x[i]];
        a[y[i]] += a[x[i]];
        a[x[i]] = 0;
    }
    vi stealable;
    for(int i = M-1; i >= 0; i--) {
        if (outgoing[y[i]]) {
            continue;
        }
        outgoing[x[i]] = true;
        stealable.push_back(transported[i]);
    }
    sort(rall(stealable));
    ll ans = 0;
    rep(i, 0, min(sz(stealable), K)) {
        ans += stealable[i];
    }
    cout << ans << endl;
}
