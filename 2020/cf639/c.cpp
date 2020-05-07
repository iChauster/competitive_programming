//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
void solve() {
	int n;
	cin >> n;
	set<long long> hit;
	int fail = 0;
	for (int i = 0; i < n; i ++) {
		long long curr; cin >> curr;
		long long propose = (curr + i) % n;
		if (propose < 0) propose += n;
		if (hit.count(propose) > 0) {
			fail = 1;
		} else {
			hit.insert(propose);
		}
	}
	if (fail) {
		printf("NO\n");
		return;
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
