//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int m = 1e9;
	for (int i = 1; i < n; i ++) {
		m = min(m, v[i] - v[i - 1]);
	}
	printf("%d\n", m); 
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
