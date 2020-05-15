//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	if (n == 1) {
		printf("0\n");
	} else {
		int i = 3;
		long long sum = 8;
		while (i < n) {
			i += 2;
			// add cells
			sum += 4 * (i - 1) * (long long) floor(1.0 * i / 2); 
		}
		printf("%lld\n", sum);
	}
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
