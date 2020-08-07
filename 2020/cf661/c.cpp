//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> cnt(n + 1);
	for (int i = 0; i < n; i ++){
		int curr; cin >> curr;
		cnt[curr] ++; 
	}
	int ans = 0;
	for (int s = 2; s <= 2*n; s ++) {
		int cur = 0;
		for (int i = 1; i < (s + 1) / 2; i ++) {
			int complement = s - i;
			if (complement > n) continue;
			cur += min(cnt[i], cnt[complement]);
		}
		if (s % 2 == 0) cur += (cnt[s/2] / 2);
		ans = max(ans, cur);
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
