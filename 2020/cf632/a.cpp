//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

long long r; long long c;
void solve() {
	cin >> r >> c;
	for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (i == 0 && j == 0) {
                printf("W");
            } else {
                printf("B");
            }
        }
        printf("\n");
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
