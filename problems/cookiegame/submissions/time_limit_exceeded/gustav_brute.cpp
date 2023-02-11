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
vi tmp;

int _opt_bruteforce(int turn, int p1eat, int p2eat, int negtill){
    int k = min(p1eat, p2eat);
    p1eat -= k;
    p2eat -= k;
    if(turn == 1 && p1eat) p1eat--, turn ^= 3;
    if(turn == 2 && p2eat) p2eat--, turn ^= 3;
    if(turn == 2){
        for(int i = negtill; i < n; i++){
            if(tmp[i] != -1){
                int x = tmp[i];
                tmp[i] = -1;
                int ans = _opt_bruteforce(turn^3, p1eat, x, i+1);
                tmp[i] = x;
                return ans;
            }
        }
        return 0;
    }
    else{
        int ans = 0;
        for(int i = negtill; i < n; i++){
            if(tmp[i] != -1){
                int x = tmp[i];
                tmp[i] = -1;
                ans = max(ans, _opt_bruteforce(turn^3, x, p2eat, negtill) + 1);
                tmp[i] = x;
            }
        }
        return ans;
    }
}
int opt_bruteforce(){
    tmp = a;
    return _opt_bruteforce(1, 0, 0, 0);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
	cin >> n;
	a = vi(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	int ans = opt_bruteforce();
	cout << ans << "\n";
}
