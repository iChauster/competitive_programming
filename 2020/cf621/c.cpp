//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	string source;
	cin >> source;
	long long one[26];
	long long two[26][26];
	memset(one, 0, sizeof(one));
	memset(two, 0, sizeof(two));
	for (int i = 0; i < source.length(); i ++) {
		int curr = source[i] - 'a';
		// updateCounts on two
		for (int al = 0; al < 26; al ++) {
			two[al][curr] += one[al];
		}
		one[curr] ++;
	}
	// find max on one char and two char
	long long ans = 0;
	for (int i = 0; i < 26; i ++) {
		ans = max(ans, one[i]);
	}
	for (int i = 0; i < 26; i ++) {
		for (int j = 0; j < 26; j ++) {
			ans = max(ans, two[i][j]);
		}
	}
	printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve();
}
