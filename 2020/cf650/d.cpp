#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s; cin >> s;
	sort(s.begin(), s.end());
	int n; cin >> n;
	vector<int> v(n);
	vector<int> targs(n);
	vector<char> ans(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
		if (v[i] == 0) {
			targs.push_back(i);
			ans[i] = 1;
		}
	}
	int rem = s.length() - 1;
	int added = 0;
	while (added <= n) {
		for (int i : targs) {
			ans[i] = s[rem];
			for (int j = 0; j < n; j ++) {
				if (v[j] != 0) v[j] -= i;
				
				if (v[j] == 0 && ans[j] == 0){
					targs.push_back(j);
					ans[j] = 1;
				}
			}
			rem --;
			added ++;
		}
	}
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " and ";
	}
	cout << endl;
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
