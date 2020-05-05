//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n; int d;
	cin >> n >> d;
	vector<int> l(n);
	for (int i = 0; i < n; i ++) {
		cin >> l[i];
	}
	while(d > 0) {
		for (int i = 1; i < n; i ++) {
			if (l[i] > 0){
				l[i - 1] ++;
				l[i] --;
				break;
			}
		}
		d --;
	}

	printf("%d\n", l[0]);
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
