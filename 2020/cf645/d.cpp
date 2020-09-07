//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;
	if (k >= n) {
		printf("1\n");
	} else {
		long long ans = 3e9;
		for (long long i = 1; i <= sqrt(n); i ++) {
			long long mod = (n % i + i) % i;
			if (mod == 0) {
				if (n / i <= k) {
					ans = min(ans, i);
				} else {
					if (i <= k)
						ans = min(ans, n/i);
				}
			}
		}
		printf("%lld\n", ans);
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
