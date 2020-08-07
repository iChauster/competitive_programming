#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> c(n);
	vector<long long> o(n);
	long long  minCandy, minOrange;
	minCandy = LLONG_MAX;
	minOrange = LLONG_MAX;
	for (int i = 0; i < n; i ++){
		long long curr; cin >> curr;
		c[i] = curr;
		minCandy = min(minCandy, curr);
	}	
	for (int i = 0; i < n; i ++) {
		long long curr; cin >> curr;
		o[i] = curr;
		minOrange = min(minOrange, curr);
	}
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		long long oranges = o[i];
		long long candy = c[i];
		long long moves = min(candy - minCandy, oranges - minOrange);
		ans += moves;
		ans += (oranges - moves) - minOrange;
		ans += (candy - moves) - minCandy;
	}
	printf("%lld\n", ans);

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
