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

int fastexp(){
    for(int i = 0; i < n; i++) a[i]++;
    int ans = -1;
    for(int i = 0; i < (1<<n); i++){
        if(__builtin_popcount(i) <= ans) continue;
        int possible = 1;
        int t = 0;
        vpi choices;
        for(int j = 0; j < n; j++){
            if(i&(1<<j)){
                choices.emplace_back(t+a[j], a[j]);
            }
            else t += a[j];
        }
        sort(all(choices));
        t = 0;
        for(int j = 0; j < sz(choices); j++){
            t += choices[j].second;
            if(t > choices[j].first){
                possible = 0;
                break;
            }
        }
        if(possible) ans = max(ans, sz(choices));
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
	int ans = fastexp();
	cout << ans << "\n";
}
