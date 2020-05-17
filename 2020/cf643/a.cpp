//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, k;
	cin >> a >> k;
	long long x = a;
	k --;
	while(k) {
		int mi = 1e9;
		int ma = -1e9;
		long long digit = x;
		while (digit) {
			int z = digit % 10;
			mi = min(mi, z);
			ma = max(ma, z);
			digit /= 10;
		}
		if (mi == 0) break;
		x += mi * ma;
		k --;
	}
	printf("%lld\n", x);
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
