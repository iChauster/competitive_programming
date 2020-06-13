//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	ll a, b; cin >> a >> b;
	ll ma = max(a, b);
	ll mi = min(a, b);
	int ans = -1;
	int ops = 0;
	while (ma > 0){
		if (ma == mi) {
			ans = ops;
			break;
		} else {
			if (ma & 1) {
				break;
			}
			ma >>= 1;
			ops ++;
		}
	}
	if (ans != -1) ans = (int) ceil((1.0 * ans) / 3);
	printf("%d\n", ans);

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
