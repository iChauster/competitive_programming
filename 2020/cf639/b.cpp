//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
vector<long long> z;
void solve() {
	long long s;
	cin >> s;
	long long ans = 0;
	while (s > 0) {
		if (s == 1) {
			break;
		}
		auto left = upper_bound(z.begin(),z.end(), s);
		long long v = *(left - 1);
		s -= v;
		ans += 1;
	}
	printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
	z.push_back(2);
	long long add = 5;
	int i = 1;
	while(1) {
		long long value = z[i - 1] + add;
		z.push_back(value);
		add += 3;
		i += 1;
		if (value > 1000000000) {
			break;
		}
	}
    for (int i = 0; i < tests; i ++) {
    	solve();
    }
}
