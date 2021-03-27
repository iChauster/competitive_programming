#include <bits/stdc++.h>

using namespace std;

vector<int> sub(int num, int size, int target) {
//    printf("%d %d %d\n", num, size, target);
	if (size == 2) {
		if (target == 1) {
			return {num, num + 1};
		} else {
			return {num + 1, num};
		}
	} else {
		vector<int> v;
		v.push_back(num);
		--size;
		int maxBelow = ((size + 1) * size) / 2 - 1;
		vector<int> res = sub(num + 1, size, (target - 1 <= maxBelow) ? target - 1 : target - size - 1);
		if (target - 1 <= maxBelow) {
			v.insert(v.end(), res.begin(), res.end());
			return v;
		} else {
			reverse(res.begin(), res.end());
			res.insert(res.end(), v.begin(), v.end());
			return res;
		}
	}
}
void solve() {
	int n, c;
	cin >> n >> c;
	if (c < n - 1 || c > ((n + 1) * n) / 2 - 1){
		printf("IMPOSSIBLE\n");
	} else {
		for (auto i : sub(1, n, c)) {
			printf("%d ", i);
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
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
