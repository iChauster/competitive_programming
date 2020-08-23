#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}

	int ans = 0;
	long long diff = LLONG_MAX;
	int currentCount = 2;
	for (int i = 1; i < n; i ++) {
		int currentDiff = v[i] - v[i - 1];
		if (currentDiff == diff){
			currentCount += 1;
		} else {
			ans = max(currentCount, ans);
			currentCount = 2;
			diff = currentDiff;
		}
	}
	ans = max(currentCount, ans);
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
