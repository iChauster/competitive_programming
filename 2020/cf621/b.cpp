//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n; long long x;
	cin >> n >> x;
	long long cM = 0;
	int match = 0;
	for (int i = 0; i < n; i ++) {
		long long curr;
		cin >> curr;
		if (curr > cM){
			cM = curr;
		}
		if (curr == x) {
			match = 1;
		}
	}
	if (match) {
		printf("1\n");
	}else{
		long long ans = max(2*1LL, (long long) ceil(x*1.0 / cM));
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
