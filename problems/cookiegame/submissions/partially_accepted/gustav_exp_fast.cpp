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

int n;
vi a;

int fastexp2(){
    for(int i = 0; i < n; i++) a[i]++;
    int ans = -1;
    for(int i = 0; i < (1<<n); i++){
        if(__builtin_popcount(i) <= ans) continue;
        int possible = 1;
        int behind = 0;
        int s = 0;
        int mx = 0;
        int p = -1;
        for(int j = 0; j < n; j++){
            int v = (i>>j)&1;
            if(v != p){
                if(p){
                    behind -= s;
                    if(behind + mx < 0){
                        possible = 0;
                        break;
                    }
                }
                else behind += s;
                s = 0;
                mx = 0;
            }
            s += a[j];
            mx = max(mx, a[j]);
            p = v;
        }
        if(p){
            behind -= s;
            if(behind + mx < 0) possible = 0;
        }
        if(possible) ans = max(ans, __builtin_popcount(i));
    }
    for(int i = 0; i < n; i++) a[i]--;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vi(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = fastexp2();
	cout << ans << "\n";
}
