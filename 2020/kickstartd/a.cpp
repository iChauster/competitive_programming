#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	int m = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		int next = -1;
		if (i + 1 <  n) {
			next = v[i + 1];
		}
		int curr = v[i];
		if (next < curr) {
			if (curr > m) {
				m = curr;
				ans ++;
			}
		}
		m = max(m, curr); 
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
