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

/*
    Gustav och Oskar äter mackor. För att göra det rättvist har de bestämt att de ska äta det som ett spel.
    De turas om att göra drag. Ett drag består av att ta en macka eller att ta en tugga av en tagen macka.
    Varje macka kräver olika mängd tuggor. Om man har tagit en macka men inte ätit upp den är man tvungen att ta en tugga.
    Man får välja vilken o-tagen macka man vill när man tar en macka.
    Oskar orkar inte tänka, så han tar alltid den första otagna mackan i listan.
    Gustav vet detta och vill äta så många mackor som möjligt. Hur många kan han som mest lyckas äta?
    Om man har ätit upp och det inte finns några fler mackor kvar att ta får man passa.
    När båda har ätit upp sina mackor och det inte finns några kvar att ta är spelet slut.
*/


int n, m;
vi a;
vi tmp;


int _bruteforce(int turn, int p1eat, int p2eat){
    if(turn == 1 && p1eat) return _bruteforce(turn^3, p1eat-1, p2eat) + (p1eat==1);
    if(turn == 2 && p2eat) return _bruteforce(turn^3, p1eat, p2eat-1);
    if(turn == 2){
        for(int i = 0; i < n; i++){
            if(tmp[i] != -1){
                int x = tmp[i];
                tmp[i] = -1;
                int ans = _bruteforce(turn^3, p1eat, x);
                tmp[i] = x;
                return ans;
            }
        }
        if(p1eat == 0) return 0;
        else return _bruteforce(turn^3, p1eat, 0);
    }
    else{
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(tmp[i] != -1){
                int x = tmp[i];
                tmp[i] = -1;
                ans = max(ans, _bruteforce(turn^3, x, p2eat) + (x==0));
                tmp[i] = x;
            }
        }
        if(ans == -1){
            if(p2eat == 0) return 0;
            else return _bruteforce(turn^3, 0, p2eat);
        }
        return ans;
    }
}
int bruteforce(){
    tmp = a;
    return _bruteforce(1, 0, 0);
}


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


vvi dp_n3_vec;
int _dp_n3(int pos, int answer){
    if(answer <= 0) return -inf;
    if(pos == n) return inf;
    if(dp_n3_vec[pos][answer] != -1) return dp_n3_vec[pos][answer];
    int s = 0;
    int mx = 0;
    int r = _dp_n3(pos+1, answer) - a[pos];
    for(int i = pos; i < min(n, answer+pos); i++){
        s += a[i];
        mx = max(mx, a[i]);
        r = min(r, s + max(_dp_n3(i+1, answer - (i-pos+1)), -mx));
    }
    return dp_n3_vec[pos][answer] = r;
}
int dp_n3(){
    for(int i = 0; i < n; i++) a[i]++;
    dp_n3_vec = vvi(n, vi(n+1, -1));
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(_dp_n3(0, i) <= 0) ans = i;
        else break;
    }
    for(int i = 0; i < n; i++) a[i]--;
    return ans;
}

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
    srand(4);

    n = 5000;
    m = 1000000000;

    for(int test = 0; test < 10; test++){
        a = vi(n);
        for(int i = 0; i < n; i++){
            a[i] = rand()%m;
            //cout << a[i] << " ";
        }
        //cout << endl;
        sort(all(a));
        reverse(all(a));

        int ans = dp_n3_iter();
        int ans2 = dp_n2();
        cout << ans << " ";
        cout << ans2 << " ";
        cout << endl;
        assert(ans == ans2);
    }
    cout << "OK" << endl;
}
