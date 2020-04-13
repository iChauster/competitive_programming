//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long m = LLONG_MIN;
	long long currentMin = m;
	long long total = -1;
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		long long curr;
		cin >> curr;
		if (curr >= m) {
			m = curr;
			currentMin = m;
		} else if (curr < currentMin){
			currentMin = curr;
			total = max(total, m - currentMin);
		}
	}
	if (total != -1){
		long long ans = 0;
		while(total >>= 1) {
			ans ++;
		}
		printf("%lld\n", ans + 1);
	} else {
		printf("%d\n", 0);
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