//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> f(n + 1);
	vector<int> v(n);
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		int c; cin >> c;
		if (i) v[i] = v[i - 1] + c; 
		else v[i] = c;
		f[c] ++;
	}
	for(int i = 0; i < n; i ++) {
		if (i > 0) {
			if (v[i] <= n) {
				cnt += f[v[i]];
				f[v[i]] = 0;
			}
		}
		for (int j = 0; j < i - 1; j ++) {
			int val = v[i] - v[j];
			if (val <= n && f[val]) {
				cnt += f[val];
				f[val] = 0;
			}
		}
	}
	printf("%d\n", cnt);
	
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
