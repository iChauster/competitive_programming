//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	int n, m, x, y; cin >> n >> m >> x >> y;
	int twoTile = min(2*x, y);
	ll ans = 0;
	for (int i = 0; i < n; i ++) {
		string s; cin >> s;
		int dots = 0;
		for (int j = 0; j < m; j ++) {
			if (s[j] == '.') {
				dots ++;
			} else {
				// take dots, find optimal price
				if (dots % 2) {
					ans += (dots - 1) * twoTile / 2 + x;		
				} else {
					ans += (dots) * twoTile / 2;
				}
				dots = 0;
			}
		}
		
		if (dots % 2) {
			ans += (dots - 1) * twoTile / 2 + x;		
		} else {
			ans += (dots) * twoTile / 2;
		}
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
