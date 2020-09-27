#include <bits/stdc++.h>

using namespace std;

int arr[6][11];
using ll = long long;

ll solveSub(int s, pair<int,int> lP, pair<int,int> lR, vector<pair<int,int>> &c, int turn, int paintLeft, int paintRight, int stalled = 0) {
	memset(arr, 0, 6 * 11 * sizeof(int));
	for (auto i : c) {
		arr[i.first][i.second] = 1;
	}
	
	if (turn % 2 == 0) {
		ll ans = 0;
		int pot = 0;
		if (lP.second % 2 == 1){
			
			if (!arr[lP.first - 1][lP.second - 1]) {
				pot = 1;
				c.push_back(make_pair(lP.first - 1, lP.second));
				ans = max(ans, solveSub(s, make_pair(lP.first - 1, lP.second - 1), lR, c, 1 ^ turn, paintLeft + 1, paintRight));
				c.pop_back();
			} 
		} else {
			
			if (lP.first + 1 < s && !arr[lP.first + 1][lP.second + 1]) {
				pot = 1;
				c.push_back(make_pair(lP.first + 1, lP.second + 1));
				ans = max(ans, solveSub(s, make_pair(lP.first + 1, lP.second + 1), lR, c, 1 ^ turn, paintLeft + 1, paintRight));
				c.pop_back();
			} 
		}
		if (lP.second > 0 && !arr[lP.first][lP.second - 1]) {
			pot = 1;
			c.push_back(make_pair(lP.first, lP.second - 1));
			ans = max(ans, solveSub(s, make_pair(lP.first, lP.second - 1), lR, c, 1 ^ turn, paintLeft + 1, paintRight));
			c.pop_back();
		}
		if (lP.second < lP.first * 2 && !arr[lP.first][lP.second + 1]) {
			pot = 1;
			c.push_back(make_pair(lP.first, lP.second + 1));
			ans = max(ans, solveSub(s, make_pair(lP.first, lP.second + 1), lR, c, 1 ^ turn, paintLeft + 1, paintRight));
			c.pop_back();
		}
		if (!pot && stalled)
			return paintLeft - paintRight;
		else if (!pot)
			ans = solveSub(s, lP, lR, c, 1 ^ turn, paintLeft, paintRight, 1);
		return ans;
	} else {
		ll ans = LLONG_MAX;
		int pot = 0;
		if (lR.second % 2 == 1){
			if (!arr[lR.first - 1][lR.second - 1]) {
				pot = 1;
				c.push_back(make_pair(lR.first - 1, lR.second - 1));
				ans = min(ans, solveSub(s, lP, make_pair(lR.first - 1, lR.second - 1), c, 1 ^ turn, paintLeft, paintRight + 1));
				c.pop_back();
			} 
		} else {
			
			if (lR.first + 1 < s && !arr[lR.first + 1][lR.second + 1]) {
				pot = 1;
				c.push_back(make_pair(lR.first + 1, lR.second + 1));
				ans = min(ans, solveSub(s, lP, make_pair(lR.first + 1, lR.second + 1), c, 1 ^ turn, paintLeft, paintRight + 1));
				c.pop_back();
			} 
		}
		if (lR.second > 0 && !arr[lR.first][lR.second - 1]) {
			pot = 1;
			c.push_back(make_pair(lR.first, lR.second - 1));
			ans = min(ans, solveSub(s, lP, make_pair(lR.first, lR.second - 1), c, 1 ^ turn, paintLeft, paintRight + 1));
			c.pop_back();
		}
		if (lR.second < lR.first * 2 && !arr[lR.first][lR.second + 1]) {
			pot = 1;
			c.push_back(make_pair(lR.first, lR.second + 1));
			ans = min(ans, solveSub(s, lP, make_pair(lR.first, lR.second + 1), c, 1 ^ turn, paintLeft, paintRight + 1));
			c.pop_back();
		}
		if (!pot && stalled)
			return paintLeft - paintRight;
		else if (!pot)
			ans = solveSub(s, lP, lR, c, 1 ^ turn, paintLeft, paintRight, 1);

		return ans;
	}
}

void solve() {
	int s, ra, pa, rb, pb, c;
	cin >> s >> ra >> pa >> rb >> pb >> c;
	// simulate??
	ra --; pa --;
	rb --; pb --;
	memset(arr, 0, 6 * 11 * sizeof(int));
	vector<pair<int,int>> v;
	for (int i = 0; i < c; i ++){
		int left, right;
		cin >> left >> right;
		left --; right --;
		v.push_back(make_pair(left,right));
	}
	v.push_back(make_pair(ra, pa));
	v.push_back(make_pair(rb, pb));
	int ans = solveSub(s, make_pair(ra, pa), make_pair(rb, pb), v, 0, 0, 0);
	printf("%d\n", ans);
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
