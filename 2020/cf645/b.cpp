#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int i = 0;
	int totalCount = 1;
	int curr = 0;
	int ans = 1;
	while (i < n) {
		if (v[i] != curr)
			curr = v[i];
		while(i < n && v[i] == curr) {
			i ++;
			totalCount ++; 
		}
		if (totalCount >= curr + 1) {
			ans = totalCount;
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
