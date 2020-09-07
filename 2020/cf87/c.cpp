//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


long long f(long long p, int lcm, int mf) {
    long long ans = p / lcm * mf;
    ans += min(p % lcm, (long long)mf);
    return p - ans + 1; 
}
void solve() {

	int x; int y; int q;
    cin >> x >> y >> q;
    // get gcd
    int b = y;
    int gcd = x;
    while (b != 0) {
        int t = b;
        b = gcd % b;
        gcd = t;
    }
    int lcm = (x * y) / gcd;
    int mf = max(x,y);
    for (int i = 0; i < q; i ++) {
        long long left; long long right; cin >> left >> right;
        
        printf("%lld ", f(right + 1, lcm, mf)- f(left, lcm, mf));
    }
    printf("\n");

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
