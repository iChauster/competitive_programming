#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	int left = a - c;
	int right = b - c;
	string th = "1 ";
	string share = "3 ";
	string visible = "2 ";
	if (n == 1) {
		share = "1 ";
	} else if (n == 2) {
		share = "2 ";
		visible = "1 ";
	}

	if (left == 0 || right == 0) {
		if (left == 0 && right == 0){
			if (n != c){
				printf("IMPOSSIBLE\n");
				return;
			}
		}
	}
	if (left + right + c > n || left < 0 || right < 0) {
		printf("IMPOSSIBLE");
	} else {
		for (int i = 0; i < left; i ++) {
			printf("%s", visible.c_str());
		}
		if (left > 0) {
			if (left + right + c < n) {
				for (int i = 0; i < n - left - right -c; i ++) {
					printf("%s", th.c_str());
				}
			}	
		}
		for (int i = 0; i < c; i ++) {
			printf("%s", share.c_str());
		}

		if (left == 0 && left + right + c < n) {
			for (int i = 0; i < n - left - right -c; i ++) {
				printf("%s", th.c_str());
			}
		}
		for (int i = 0; i < right; i ++) {
			printf("%s", visible.c_str());
		}
	}
	printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
