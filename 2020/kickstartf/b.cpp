#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
	int n;
	ll k;
	cin >> n >> k;
	vector<pair<ll, ll>>v(n);
	for (int i = 0; i < n; i ++) {
		ll left, right;
		cin >> left >> right;
		v[i] = make_pair(left, right);
	}
	sort(v.begin(), v.end(), [](auto &left, auto &right) {
		return left.first < right.first;
	});
	ll right = 0;
	ll ans = 0;
	for (int i = 0; i < n; i ++) {
		pair<ll, ll> p = v[i];
		if (right < p.second) {
			ll rightMost = max(p.first, right);
			int adds = ceil((1.0 * (p.second - rightMost)) / k);
			ans += adds;
			right = rightMost + k * adds;
		}
	}
	printf("%lld\n", ans);
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
