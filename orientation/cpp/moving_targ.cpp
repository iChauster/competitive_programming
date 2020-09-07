//#include "./config/bits/stdc++.h"

#include <bits/stdc++.h>

using namespace std;
int n;


void solve() {
    cin >> n;
    printf("%d\n", (int)ceil((n+1)/2.0));
    int x = 1;
    for (int i = 0; i < (int)ceil((n+1)/2.0); i ++) {
        if (x > n) {
            printf("%d ", n);
        } else {
            printf("%d ", x);
        }
        x += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
