//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	long long n, k;
	cin >> n >> k;
	long long left = k;
	long long right = 2 * k;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long divisors = (long long) floor((mid * 1.0) / n);
		if (mid - divisors > k) {
			right = mid - 1;
		} else if (mid - divisors < k) {
			left = mid + 1;
		} else {
			if (mid % n == 0) {
				mid --;
			}
			printf("%lld\n", mid);
			return;
		}
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
