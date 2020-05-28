//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a, b;
	cin >> a >> b;
	int m = min(a,b);
	int ma = max(a,b);
	if (2*m < ma) {
		printf("%d\n", ma * ma);
	} else {
		printf("%d\n", 4 * m * m);
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
