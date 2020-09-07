//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int o = 0, z = 0;
	for (int i = 0; i < n; i ++) {
		if(s[i] == '0') z ++;
		else o ++;
	}
	
	long long ans = LLONG_MAX;
	for (int i = 0; i < k; i ++) {
		int currz = 0; int curro = 0;
		for (int j = i; j < n; j += k) {
			if (s[j] == '0') currz ++;
			else curro ++;
		}
		long long start = o;
		long long change = 0;
		for (int j = i; j < n; j += k) {
			if (s[j] == '0') change ++;
			else change --;
			change = min(change, (long long) 0);
			ans = min(ans, start + change);
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
    	solve();
    }
}
