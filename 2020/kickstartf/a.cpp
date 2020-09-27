#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; int x;
	cin >> n >> x;
	vector<pair<int,int>> vec(n);
	for (int i = 0; i < n; i ++) {
		int curr;
		cin >> curr;
		vec[i] = make_pair(i, ceil((1.0 * curr) / x));
	}
	
	sort(vec.begin(), vec.end(), [](auto &left, auto &right) {
		if (left.second == right.second) {
			return left.first < right.first;
		}
		return left.second < right.second;
	});
	for (int i = 0; i < n; i ++) {
		printf("%d ", vec[i].first + 1);
	}
	printf("\n"); 
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
