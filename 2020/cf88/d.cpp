//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	ll ans = 0;
	ll negInf = -1e9;
	for (int i = 0; i < 31; i ++) {
		ll best = 0;
		for (auto j: v) {
			ll val = (j > i) ? negInf : j;
			best = max(best + val, val);
			ans = max(best - i, ans);
		}
	}
	printf("%lld\n",ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
