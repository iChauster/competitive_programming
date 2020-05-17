//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	long long n, s; cin >> n >> s;
	if (s < 2 * n) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i = 0; i < n - 1; i ++) {
			printf("2 ");
		}
		printf("%lld\n", s - 2 * (n-1));
		printf("1\n");
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	solve();
	return 0;
}
