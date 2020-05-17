//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<long long> v(2e6);
	for (int i = a; i <= b; i ++) {
		// segment
		v[i + b] ++;
		v[i + c + 1] --;
	}
	for (int i = 1; i < 2e6; i ++) {
		v[i] += v[i - 1];
	}
	for (int i = 1; i < 2e6; i ++) {
		v[i] += v[i - 1];
	}
	long long ans = 0;
	for (int z = c; z <= d; z ++) {
		ans += v[2e6 - 1] - v[z];
	}
	printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	solve();
}
