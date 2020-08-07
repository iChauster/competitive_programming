#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> ans(n);
	vector<int> z, o;

	for (int i = 0; i < n; i ++) {
		int position = z.size() + o.size();
		if (s[i] == '0') {
			if (o.empty()){
				z.push_back(position);
			} else {
				position = o.back();
				o.pop_back();
				z.push_back(position);
			}
		} else {
			if (z.empty()){
				o.push_back(position);
			} else {
				position = z.back();
				z.pop_back();
				o.push_back(position);
			}
		}
		ans[i] = position;
	}
	printf("%lu\n", o.size() + z.size());
	for (auto i : ans) printf("%d ", i + 1);
	printf("\n");
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
