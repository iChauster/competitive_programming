//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	long long x; long long y;
    cin >> x >> y;
    long long a; long long b;
    cin >> a >> b;
    if (b > 2*a) 
        printf("%lld\n", a * (x + y));
    else 
        printf("%lld\n", (max(x,y) - min(x,y)) * a + min(x,y) * b);
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
