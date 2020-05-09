//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	int a; 
	cin >> a;
	int start = 10;
	vector<int> ans;
	while (a > 0) {
		int z = a % start;
		if (z != 0) ans.push_back(z);
		a -= z;
		start *= 10;
	}
	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); i ++) {
		printf("%d ", ans[i]);
	}
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
