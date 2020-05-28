//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	long long ans;
	if (n % 2 && m % 2) {
		int b = max(n,m);
		int s = min(n,m);
		ans = ceil(((b - 1) * s * 1.0) / 2) + ceil((1.0 * s)/2);
	} else {
		ans = ceil(n * m * 1.0/ 2);
	}
	printf("%lld\n", ans);
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
