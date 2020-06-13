//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	vector<int> here(1025);
	int n; cin >> n;
	vector<int> ye(n);
	for (int i = 0; i < n; i ++) {
		int cur; cin >> cur;
		here[cur] = 1;
		ye[i] = cur;
	}
	for (int k = 1; k < 1024; k ++) {
		int fail = 0;
		for (int i = 0; i < n; i ++) {
			if (!here[ye[i] ^ k]) {
				fail = 1;
				break;
			}
		}
		if (!fail) {
			printf("%d\n", k);
			return;
		}
	}
	printf("-1\n");

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
