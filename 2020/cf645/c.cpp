//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long xo, xf, yo, yf;
	cin >> xo >> yo >> xf >> yf;
	printf("%lld\n", (xf - xo) * (yf - yo) + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	solve();
    }
}
