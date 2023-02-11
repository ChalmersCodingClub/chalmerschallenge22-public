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

ll n;
vl a;

vvl dp_n3_iter_vec;
ll dp_n3_iter(){
    for(ll i = 0; i < n; i++) a[i]++;
    dp_n3_iter_vec = vvl(n+1, vl(n+1));

    ll ans = 0;
    for(ll i = 0; i <= n; i++){
        dp_n3_iter_vec[i][n] = linf;
        dp_n3_iter_vec[0][i] = -linf;
    }
    for(ll answer = 1; answer <= n; answer++){
        for(ll pos = n-1; pos >= 0; pos--){
            ll s = 0;
            ll r = dp_n3_iter_vec[answer][pos+1] - a[pos];
            for(ll i = 0; i < min(n-pos, answer); i++){
                s += a[i+pos];
                if(a[i+pos] >= a[pos] && i > 0) break; // optional pruning
                if(s-a[pos] >= r) break; // optional pruning
                r = min(r, s + max(dp_n3_iter_vec[answer-i-1][pos+i+1], (ll)-a[pos]));
            }
            dp_n3_iter_vec[answer][pos] = r;
        }
        if(dp_n3_iter_vec[answer][0] <= 0) ans = answer;
        else break;
    }

    for(ll i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vl(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	ll ans = dp_n3_iter();
	cout << ans << "\n";
}
