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

    ll n, a, b;
    cin >> n >> a >> b;
    ll g = __gcd(a, b);
    a /= g;
    b /= g;
    if((__int128_t)a * b < n){
        g = sqrtl(n / a / b);
        while(g*a * g*b < n) g++;
        a *= g;
        b *= g;
    }
    ll ans = 0;
    while(a > 1 || b > 1){
        if(b > a) swap(a, b);
        a = (a+1)/2;
        ans++;
    }
    cout << ans << "\n";
}
