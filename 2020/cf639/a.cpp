//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	int m, n;
	cin >> m >> n;
	if (m == 1 || n == 1) {
		printf("YES\n");
	} else if (m == 2 && n == 2) {
		printf("YES\n");
	} else {
		printf("NO\n");
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
