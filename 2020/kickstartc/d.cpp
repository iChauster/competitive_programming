//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

struct cmp {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		int lena = a.second - a.first + 1;
		int lenb = b.second - b.first + 1;
		if (lena == lenb) return a.first < b.first;
		return lena > lenb;
	}
};

void d(int left, int right, int num, vector<int> *v, set<pair<int, int>, cmp> *q) {
	int mid = (left + right) / 2;
	(*v)[mid] = num;
	if (left < mid) q -> insert(make_pair(left, mid - 1));
	if (right > mid) q -> insert(make_pair(mid + 1, right));
}


void solve() {
	int n; cin >> n;
	set<pair<int, int>, cmp> q;
	q.insert(make_pair(0, n-1));
	vector<int> v(n);
	int i = 1;
	while (i <= n) {
		pair<int, int> curr = *(q.begin());
		q.erase(q.begin());
		d(curr.first, curr.second, i, &v, &q);
		i ++;
	}
	for (int i = 0; i < n; i ++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	solve();
    }
	return 0;
}
