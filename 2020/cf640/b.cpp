//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	long long n;
	int k;
	cin >> n >> k;
	long long test = n - (k - 1);
	if (test > 0 && test % 2 == 1) {
		printf("YES\n");
		for (int i = 0; i < (k - 1); i ++) {
			printf("1 ");
		}
		printf("%lld\n", test);
		return;
	} else if (test <= 0) {
		printf("NO\n");
		return;
	}
	test = n - 2 * (k - 1);
	if (test > 0 && test % 2 == 0) {
		printf("YES\n");
		for (int i = 0; i < (k - 1); i ++ ){
			printf("2 ");
		}
		printf("%lld\n", test);
		return;
	}else {
		printf("NO\n");
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
