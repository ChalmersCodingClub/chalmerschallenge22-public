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

int n, m;
vi a;

vvi dp_n3m_vec;
int _dp_n3m(int pos, int behind){
    if(pos == n) return 0;
    if(dp_n3m_vec[pos][behind+n*m] != -1) return dp_n3m_vec[pos][behind+n*m];
    int ans = _dp_n3m(pos+1, behind+a[pos]);
    int s = 0;
    int mx = 0;
    for(int i = pos; i < n; i++){
        s += a[i];
        mx = max(mx, a[i]);
        if(behind-s + mx < 0) break;
        ans = max(ans, _dp_n3m(i+1, behind-s) + i-pos+1);
    }
    return dp_n3m_vec[pos][behind+n*m] = ans;
}
int dp_n3m(){
    for(int i = 0; i < n; i++) a[i]++;
    dp_n3m_vec = vvi(n, vi(2*n*m+1, -1));
    int ans = _dp_n3m(0, 0);
    for(int i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
    m = 0;
	a = vi(n);
	for(int i = 0; i < n; i++){
        cin >> a[i];
        m = max(m, a[i]+1);
    }
	int ans = dp_n3m();
	cout << ans << "\n";
}
