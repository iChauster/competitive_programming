//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


long long n;
void solve() {
	cin >> n;
    if (n % 4 == 0){
        printf("YES\n");
        long long elements = 0;
        long long current = 2;
        long long sum;
        while (elements < n / 2) {
            printf("%lld ", current);
            sum += current;
            current += 2;
            elements ++;
        }
        long long last = sum - current + 2;
        elements = 0;
        current = 1;
        while (elements < n / 2 - 1) {
            printf("%lld ", current);
            current += 2;
            elements ++;
        }

        printf("%lld\n", sum - last + n/2 - 1);
    } else {
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
