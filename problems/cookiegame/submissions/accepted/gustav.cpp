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

struct dp_n2_ds{
    map<ll, pair<ll,ll>> m;

    void add(ll first, ll second){
        auto ptr = m.lower_bound(first-second);
        if(ptr != m.begin()) ptr--;
        while(ptr != m.begin() && first <= ptr->second.first){
            auto x = ptr;
            x--;
            m.erase(ptr);
            ptr = x;
        }
        while(ptr != m.end() && second <= ptr->second.second){
            auto x = ptr;
            x++;
            m.erase(ptr);
            ptr = x;
        }
        m[first-second] = {first, second};
    }

    ll query(ll move){
        auto ptr = m.lower_bound(move);
        if(ptr == m.end()) ptr--;
        ll r = ptr->second.first;
        if(ptr != m.begin()){
            ptr--;
            r = min(r, ptr->second.second+move);
        }
        return r;
    }
};
vvl dp_n2_vec;
dp_n2_ds _dp_n2_ds;
ll dp_n2(){
    for(ll i = 0; i < n; i++) a[i]++;
    dp_n2_vec = vvl(n+1, vl(n+1, linf));
    for(ll i = 0; i <= n; i++)
        dp_n2_vec[0][i] = -linf;

    ll ans = 0;
    for(ll diag = 0; diag <= n-1; diag++){
        _dp_n2_ds = dp_n2_ds();
        _dp_n2_ds.add(0, dp_n2_vec[max(0ll, -diag)][n-max(0ll, diag)]);
        ll addextra = 0;
        for(ll j = 1; j <= n-abs(diag); j++){
            ll pos = n - max(0ll, diag) - j;
            ll answer = max(0ll, -diag) + j;

            ll r = min(_dp_n2_ds.query(a[pos]) + addextra, dp_n2_vec[answer][pos+1] - a[pos]);

            addextra += a[pos];

            dp_n2_vec[answer][pos] = r;
            _dp_n2_ds.add(-addextra, r - addextra);
        }
        if(diag >= 0 && dp_n2_vec[n-diag][0] <= 0){
            ans = n-diag;
            break;
        }
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
	ll ans = dp_n2();
	cout << ans << "\n";
}
