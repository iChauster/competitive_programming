#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n; cin >> n;
	vector<long long> v(n); 
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	long long p = 0;
	int topCount = 0;
	int bottomCount = 0;
	int ans = 0;

	for (int i = 0; i < n; i ++) {
		long long curr = v[i];
		if (i) {
			if (curr > p) {
				topCount ++;
				bottomCount = 0;
			}else if (curr < p) {
				bottomCount ++;
				topCount = 0;
			}
			if (topCount == 4 || bottomCount == 4) {
				ans ++;
				topCount = 0;
				bottomCount = 0;
			}
			p = curr;
		} else {
			p = curr;
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
