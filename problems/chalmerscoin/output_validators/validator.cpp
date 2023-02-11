// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

vi tolist(ull x){
    vi r(64);
    for(int i = 0; i < 64; i++){
        r[63-i] = x&1;
        x >>= 1;
    }
    return r;
}
ull toint(vi x){
    ull r = 0;
    for(int i = 0; i < 64; i++){
        r <<= 1;
        r |= x[i];
    }
    return r;
}
ull Hash(ull x){
    vi X = tolist(x);
    for(int i = 0; i < 512; i++){
        int y = 4*X[i%64] + 2*X[(i+2)%64] + X[(i+10)%64];
        X[i%64] = (y == 0 || y == 1 || y == 4 || y == 5 || y == 7);
    }
    x = toint(X);

    for(int i = 0; i < 16; i++){
        X = tolist(x);
        reverse(all(X));
        __int128_t tmp = (__int128_t)x+toint(X);
        tmp ^= 12157665459056928801ull;
        if(tmp >= (((__int128_t)1)<<64)) tmp >>= 1;
        x = (ull)tmp;
    }

    return x;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
	vector<ull> inputs(10);
	for(int i = 0; i < 10; i++){
		fin >> inputs[i];
	}
    assert_done(fin, judge_error);
    fin.close();

    bool sample = (inputs[0] == 111131462);

    fin = ifstream(answer_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);
	vector<ull> best(10);
	for(int i = 0; i < 10; i++){
		fin >> best[i];
	}
    assert_done(fin, judge_error);
    fin.close();

    vector<ull> outputs(10);
    for(int i = 0; i < 10; i++){
        if(!(cin >> outputs[i])){
            die("Could not read");
        }
    }
    assert_done(cin, die);

    long double total_score = 0;
    for(int i = 0; i < 10; i++){
        if(outputs[i] >= (1ll<<36)) die("too big or small output");
        ull hashout = Hash((inputs[i]<<36)^outputs[i]);
        ull besthash = Hash((inputs[i]<<36)^best[i]);
        if(!sample && hashout < besthash) judge_error("better than best");
        long double t = (64-log2l(hashout))/(64-log2l(besthash));
        long double score = max(2*t, 30*t-20);
        total_score += score;
    }

    if(sample) accept(0);
    accept(total_score);
}
