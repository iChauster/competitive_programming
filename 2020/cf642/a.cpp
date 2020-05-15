//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	if (a == 1) {
		printf("0\n");
		return;
	} else if (a == 2) {
		printf("%lld\n", b);
		return;
	} else {
		printf("%lld\n", 2 * b);
		return;
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
