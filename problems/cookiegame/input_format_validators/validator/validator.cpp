#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int nMax = Arg("nMax");
	int aMax = Arg("aMax");

	int n = Int(1, nMax);
	Endl();
	SpacedInts(n, 1, aMax);
	Eof();
}
