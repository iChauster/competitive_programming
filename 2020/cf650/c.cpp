//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	int inserts = 0;
	string s; cin >> s;
	vector<int> v;
	v.push_back(-k - 1);
	for (int i = 0; i < n; i ++) {
		if (s[i] == '1') v.push_back(i);
	}
	v.push_back(n + k);
	for (int i = 0; i < v.size() - 1; i ++) {
		int freeBlocks = v[i + 1] - v[i];
		freeBlocks -= k + 1;
		if (freeBlocks > k) {
			inserts += freeBlocks / (k + 1);
		}
	}

	printf("%d\n", inserts);
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
