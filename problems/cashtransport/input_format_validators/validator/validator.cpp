#include "validator.h"
#include <bits/stdc++.h>
using namespace std;

void run() {
    int N = Int(2, 3e5);
    Space();
    int M = Int(1, 3e5);
    Space();
    int K = Int(1, M);
    Endl();
    for(int i = 0; i < N; i++){
        Int(0, 1e9);
        if(i != N-1) Space();
    }
    Endl();
    for(int i = 0; i < M; i++){
        int A = Int(0, N-1);
        Space();
        int B = Int(0, N-1);
        Endl();
        assert(A != B);
    }
    Eof();
}
