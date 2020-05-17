#include "../../cpp/config/bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	int countdown = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (v[i] == k - countdown) {
			countdown ++;
		}else{
			countdown = 0;
			if (v[i] == k) countdown ++;
		}
		if (countdown >= k) {
			ans ++;
			countdown = 0;
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
