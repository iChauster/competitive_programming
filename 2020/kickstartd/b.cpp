#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n; cin >> n;
	vector<long long> v(n); 
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	long long m = 0;
	long long mi = 0;
	int topCount = 0;
	int bottomCount = 0;
	int ans = 0;

	for (int i = 0; i < n; i ++) {
		long long curr = v[i];
		if (i) {
			if (curr > m) {
				topCount ++;
				m = curr;
			}
			if (curr < mi) {
				bottomCount ++;
				mi = curr;
			}
			if (topCount + bottomCount > 3) {
				bottomCount = 0;
				topCount = 0;
				m = curr;
				mi = curr;
				ans ++;
			}
		} else {
			m = curr;
			mi = curr;
		}
	}

	printf("%d\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
