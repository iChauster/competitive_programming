//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int currentCount = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		int curr = v[i];
		currentCount ++;
		if (curr <= currentCount) {
			ans ++;
			currentCount = 0;
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
    	solve();
    }
}
