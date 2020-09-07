//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int mat[51][51];
int dp[51][51];

void solve() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		string jString; cin >> jString;
		for (int j = 0; j < n; j ++) {
			mat[i][j] = (jString[j] == '1') ? 1 : 0;
			if (mat[i][j] && (j == n - 1 || i == n - 1)) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
		}
	}
	for (int i = n - 2; i >= 0; i --) {
		for (int j = n - 2; j >= 0; j --) {
			if (mat[i][j]) {
				int val = dp[i + 1][j] | dp[i][j + 1];
				if (val == 0) {
					printf("NO\n");
					return;
				} else {
					dp[i][j] = val;
				}
			}
		}
	}
	printf("YES\n");
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
