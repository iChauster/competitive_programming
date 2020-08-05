#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	int evens, odds;
	evens = 0;
	odds = 0;

	for (int i = 0; i < n; i ++) {
		int curr; cin >> curr;
		if (i % 2) {
			if (curr % 2 == 0) {
				odds ++;
			}
		} else {
			if (curr % 2 != 0) {
				evens ++;
			}
		}
	}

	if (evens == odds) {
		printf("%d\n", evens);
	} else {
		printf("-1\n");
	}

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
