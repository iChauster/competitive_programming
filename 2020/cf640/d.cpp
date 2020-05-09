//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	int left = 0;
	int lc = 0;
	int right = n - 1;
	int rc = 0;
	int moves = 1;
	int turn = 0;
	int clc = lc;
	int crc = rc;
	while (left <= right) {
		if (clc < crc) {
			if (turn != 0) {moves ++; turn = 0; clc = 0;}
			lc += a[left];
			clc += a[left];
			left ++;
			//move from left
		} else if (clc > crc) {
			if (turn != 1) {moves ++; turn = 1; crc = 0;}
			rc += a[right];
			crc += a[right];
			right --;
			//move from right
		} else {
			if (turn) {
				rc += a[right];
				crc += a[right];
				right --;
			} else {
				lc += a[left];
				clc += a[left];
				left ++;
			}
		}
	}
	printf("%d %d %d\n", moves, lc, rc);
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
