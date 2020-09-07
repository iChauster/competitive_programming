#include <bits/stdc++.h>
//#include "./config/bits/stdc++.h"

using namespace std;
int n;


void solve() {
    cin >> n;
    long long m = LLONG_MAX;
    long long sum = 0;
    for (int i = 0; i < n; i ++) {
        long long curr; cin >> curr;
        sum += curr;
        m = min(m, sum);
    }
    if (m < 0) {
        printf("%lld\n", m * -1);
    } else {
        printf("0\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
