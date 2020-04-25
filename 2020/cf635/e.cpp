//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
string s;
string target;
long long dp[3001][3001];
void solve() {
	cin >> s >> target;
	int m = target.size();
	int n = s.size();

	long long ans = 0;
	for (int i = 0; i <= n; i ++) {
		dp[i][i] = 1;
	}

	for(int right = 1; right <= n; right ++) {
		char curr = s[right - 1];
		for (int left = 0; left + right <= n; left ++) {
			int r = left + right;
			
			// add to front
			if (left >= m || curr == target[left]) {
				dp[left][r] += dp[left + 1][r] % 998244353;
				dp[left][r] %= 998244353;
			}
			// add to back
			if (r > m || curr == target[r - 1]) {
				dp[left][r] += dp[left][r - 1] % 998244353;
				dp[left][r] %= 998244353;
			}

		}
	}

	for (int j = m; j <= n; j ++) {
		ans += dp[0][j];
		ans %= 998244353;
	}

	printf("%lld\n", ans % 998244353);
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
