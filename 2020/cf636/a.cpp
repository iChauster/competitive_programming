//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
    long long n;

    cin >> n;
    
    long long hit = 4;
    while(1) {
        if (n % (hit - 1) == 0) {
            printf("%lld\n", n / (hit - 1));
            break;
        } else {
            hit *= 2;
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
