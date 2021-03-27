#include <bits/stdc++.h>

using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	string c; 
	cin >> c;
	char cur = '\0';
	int ans = 0;
	for (auto chr : c) {
		if (chr != 'C' && chr != 'J') 
			continue;
		if (cur == '\0') {
			cur = chr;
		} else {
			if (cur != chr) {
				if (cur == 'C') {
					ans += x;
				} else {
					ans += y;
				}
				cur = chr;
			}
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
