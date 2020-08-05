#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	string s; cin >> s;
	string ans = s.substr(0, 2);
	for (int i = 3; i < s.length(); i += 2) {
		ans += s[i];
	}
	cout << ans << endl;
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
