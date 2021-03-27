#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	map<int, int> m;
	for (int i = 0; i < n; i ++) {
		int c; cin >> c;
		m[c] = i;
	}
	int current = 0;
	int ans = 0;
	vector<pair<int, int>> flips;
	for (auto const& [key, val] : m) {
		int j = val;
		for (auto x : flips) {
			if (j < x.second)
				j = x.second - (j - x.first);
		}
		if (j != current){
			flips.push_back(make_pair(current, j));
		}
		ans += j - current + 1;
		current ++;
	}
	printf("%d\n", ans - 1);
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
