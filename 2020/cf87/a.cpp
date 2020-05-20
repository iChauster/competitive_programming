//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	ll a,b,c,d; cin >> a >> b >> c >> d;
	ll remaining = a - b;
	ll plus = c - d;
	
	if (remaining > 0 && plus <= 0) {
		printf("-1\n");
		return;
	} else {
		if (remaining <= 0) {
			printf("%lld\n", b);
			return;
		}
		ll rotations = (ll) ceil((1.0 * remaining) / plus);
		ll ans = b + rotations * c;
		printf("%lld\n", ans);
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
