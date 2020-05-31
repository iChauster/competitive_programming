//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	int evens, odds; evens = odds = 0;
	for (int i = 0; i < n; i ++) {
		int curr; cin >> curr;
		if (curr % 2) odds ++; else evens ++;
	}
	// odd + even is odd
	// even # of odds is bad
	if (odds > x) odds = x;
	int maxOdd = (odds % 2) ? odds : odds - 1;
	if (maxOdd <= 0){
		printf("No\n"); return;
	}
	int rem = x - maxOdd;
	if (evens >= rem) {
		printf("Yes\n");
	}else {
		printf("No\n");
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
