#include "../../cpp/config/bits/stdc++.h"
//#include <bits/stdc++.h>
//brute forced approach
using namespace std;

set<long long> perfs;


void solve() {
	
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i + 1];
		v[i + 1] += v[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < i; j ++) {
			long long loo = v[i] - v[j];
			if (perfs.count(loo) != 0) {
				ans ++;
			}
		}
	}	
	printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
	for (int i = 0; i <= 500; i ++) {
		perfs.insert(i * i);
	}
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
