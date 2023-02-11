#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const ll inf = 1234567890123456789;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << (x) << endl
#define sz(x) ((ll)(x).size())
#define rep(i, a, b) for(ll i = (a); i < ll(b); i++)
#define trav(x, a) for(auto& x : a)

ll n;
vi a;

vvi dp_n3_vec;
ll _dp_n3(ll pos, ll answer){
    if(answer <= 0) return -inf;
    if(pos == n) return inf;
    if(dp_n3_vec[pos][answer] != -1) return dp_n3_vec[pos][answer];
    ll s = 0;
    ll mx = 0;
    ll r = _dp_n3(pos+1, answer) - a[pos];
    for(ll i = pos; i < min(n, answer+pos); i++){
        s += a[i];
        mx = max(mx, a[i]);
        r = min(r, s + max(_dp_n3(i+1, answer - (i-pos+1)), -mx));
    }
    return dp_n3_vec[pos][answer] = r;
}
ll dp_n3(){
    for(ll i = 0; i < n; i++) a[i]++;
    dp_n3_vec = vvi(n, vi(n+1, -1));
    ll ans = 0;
    for(ll i = 0; i <= n; i++){
        if(_dp_n3(0, i) <= 0) ans = i;
        else break;
    }
    for(ll i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vi(n);
	for(ll i = 0; i < n; i++) cin >> a[i];
	ll ans = dp_n3();
	cout << ans << "\n";
}
