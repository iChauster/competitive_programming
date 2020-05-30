//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	ll c, h, t; cin >> h >> c >> t;
	if (t <= (h + c) / 2) {
		printf("%d\n", 2);
	} else {
		float k = 1.0 * (h - t) / (2 * t - (h + c));
		ll f = (ll) floor(k);
		ll ce = (ll) ceil(k);
		float res1 = abs(t - (((ll) f * h) + ((ll) f * c) + h) * 1.0 / (2*f + 1));
		float res2 = abs(t - (((ll) ce * h) + ((ll) ce * c) + h) * 1.0 / (2 * ce + 1));
		if (res1 <= res2) {
			printf("%lld\n", 2*f + 1);
		} else {
			printf("%lld\n", 2*ce + 1);
		}
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
