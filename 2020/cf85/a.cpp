//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
int n;
void solve() {
	cin >> n;
	int lp = -1;
    int lc = -1;

    int cp = 0;
    int cc = 0;

    int r = 0;
    for (int i = 0; i < n; i ++) {
        cin >> cp >> cc;
        int cChange = cc - lc;
        int pChange = cp - lp;

        if (cChange < 0 || pChange < 0) {
            r = -1;
        } 
        if (cc > cp) {
            r = -1;
        }
        if (cChange > pChange) {
            r = -1;
        }
        lp = cp;
        lc = cc;
    }
    if (r == 0) {printf("YES\n");} else {printf("NO\n");}
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
