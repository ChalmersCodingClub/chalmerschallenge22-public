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

int n, m, k;
vl a;
vvl t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    a = vl(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    t = vvl(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        t[x].clear();
        t[y].push_back(a[x]);
        a[y] += a[x];
        a[x] = 0;
    }
    vl o;
    for(int i = 0; i < n; i++){
        for(ll x : t[i]){
            o.push_back(x);
        }
    }
    sort(all(o));
    reverse(all(o));
    ll ans = 0;
    for(int i = 0; i < min(sz(o), k); i++){
        ans += o[i];
    }
    cout << ans << "\n";
}