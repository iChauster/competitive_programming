//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


int n;
int d;
int m;
void solve() {
	cin >> n >> d >> m;
    if (n > 20) {
        while (d > 0) {
            n = floor(n/2) + 10;
            d --;
        }
    }
    if (n > m * 10) {
        printf("NO\n");
    } else {
        printf("YES\n");
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
