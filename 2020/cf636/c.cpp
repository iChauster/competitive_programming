//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n;

    cin >> n;
    long long currentMax = 0;
    long long currentMin = 0;
    int inPos = 0;
    int inNeg = 0;
    long long sum = 0;
    for (int i = 0; i < n; i ++){
    	long long curr; cin >> curr;
    	if (curr > 0 && !inPos) {
    		sum += currentMin;
    		currentMin = 0;
    		inNeg = 0;
    		inPos = 1;
    		currentMax = curr;
    	} else if (curr > 0 && curr > currentMax) {
    		currentMax = curr;
    	}

    	if (curr < 0 && !inNeg) {
    		sum += currentMax;
    		currentMax = 0;
    		inNeg = 1;
    		inPos = 0;
    		currentMin = curr;
    	} else if (curr < 0 && curr > currentMin) {
    		currentMin = curr;
    	}

    }
    if (currentMax) {
    	sum += currentMax;
    }
    if (currentMin) {
    	sum += currentMin;
    }
    printf("%lld\n", sum);
    
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
