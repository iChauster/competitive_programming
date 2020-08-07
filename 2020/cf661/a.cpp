#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i ++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i ++) {
		if (v[i] - v[i - 1] > 1) {
			printf("NO\n");
			return;
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
