//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	int even, odd;
	even = odd = 0;
	for (int i = 0; i < n; i ++) {
		int curr; cin >> curr;
		v[i] = curr;
		if (curr % 2) 
			odd ++;
		else
			even ++;
	}
	// both even
	if (even % 2 == 0 && odd % 2 == 0) {
		printf("YES\n");
	} else if (even % 2 != odd % 2) {
		printf("NO\n");
	} else {
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i ++) {
			if (v[i] - v[i - 1] == 1){
				printf("YES\n");
				return;
			}
		}
		printf("NO\n");
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
