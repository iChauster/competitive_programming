//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	int n, m, k; cin >> n >> m >> k;
	int decksize = n / k;
	if (decksize > m) {
		printf("%d\n", m);
	} else {
		int win = min(decksize,m);
		int rem = m - win;
		k --; 
		printf("%d\n", win - (int)ceil(1.0 * rem / k));
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
