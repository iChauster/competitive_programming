//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n0, n1, n2;
	cin >> n0 >> n1 >> n2;
	if (n1 == 0) {
		string f = "0";
		if (n2) f = "1";
		for (int i = 0; i < max(n0, n2) + 1; i ++) {
			cout << f;
		}
		cout << endl;
		return;
	} else {
		string ans;
		for (int i = 0; i < n1 + 1; i ++) {
			if (i % 2) {
				ans += "0";
			} else {
				ans += "1";
			}
		}
		ans.insert(1, string(n0, '0'));
		ans.insert(0, string(n2, '1'));
		cout << ans << endl;
	}
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
