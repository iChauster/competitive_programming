#include <bits/stdc++.h>
//#include "./config/bits/stdc++.h"

using namespace std;

void solve() {

    int n;
    cin >> n;
    long long initialHash = 0;
    int collision = (n % 2 == 0);
    for (int i = 0; i < n; i ++){
        long long num = 0;
        cin >> num;
        if (i % 2 == collision){
            initialHash += num;
        } else {
            initialHash -= num;
        }
    }

    long long ops;
    long long left;
    long long right;
    long long added;

    int result;
    cin >> ops;
    for (int x = 0; x < ops; x ++){
        cin >> left >> right >> added;
        if ((right - left) % 2 == 0) {
            if (left % 2 == !collision) {
                initialHash += added;
            } else {
                initialHash -= added;
            }
        }
        printf("%lld\n", initialHash);
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
