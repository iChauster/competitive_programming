//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int n;
long long b[100001];
int a[100001];

void solve() {
	cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    int sz = 0;
    int sp = 0;
    int sn = 0;
    long long diff = 0;
    for (int i = 0; i < n; i ++) {
        if (sp && sn) break;
        diff = b[i] - a[i];
        if (diff == 0) {
            if (a[i] == 0) {
                sz = 1;
            } else if (a[i] == 1){
                sp = 1;
            } else {
                sn = 1;
            }
        } else {

            if (diff > 0 && sp != 1) {
                printf("NO\n");
                return;
            } else if (diff < 0 && sn != 1){
                printf("NO\n");
                return;
            }
            if (a[i] == 0) {
                sz = 1;
            } else if (a[i] == 1){
                sp = 1;
            } else {
                sn = 1;
            }
        }
    }
    printf("YES\n");

    

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
