//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	int len = s.length();
	vector<int> v(len + 1);
	for (int i = 0; i < len; i ++) {
		int curr = s[i] - '0';
		int bon = (curr == 1) ? 1 : 0;
		if (i) {
			v[i] = bon + v[i - 1];
		} else {
			v[i] = bon;
		}
	}
	int total = v[len - 1];
	int ans = 1e9;
	for (int i = 0; i < len; i ++) {
		// convert right to ones
		int leftOnes = v[i];
		int leftZeroes = i - v[i] + 1;
		int rightOnes = total - v[i];
		int rightZeroes = len - i - 1 - rightOnes;

		ans = min(ans, leftOnes + rightZeroes);
		// convert left to ones
		ans = min(ans, leftZeroes + rightOnes);
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
