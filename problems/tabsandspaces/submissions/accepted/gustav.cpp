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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	int f;
    cin >> f;
    vi a;
    for(int i = 0; i < f; i++){
        int lines;
        cin >> lines;
        for(int j = 0; j < lines; j++){
            int x;
            cin >> x;
            a.push_back(x);
        }
    }
    pi ans{-1, -1};
    for(int w = 1; w <= 80; w++){
        int saved = 0;
        for(int j = 0; j < sz(a); j++)
            saved += a[j]/w*(w-1);
        ans = max(ans, {saved, -w});
    }
    cout << -ans.second << "\n" << ans.first << "\n";
}
