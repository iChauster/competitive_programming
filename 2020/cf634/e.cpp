//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int n;
int sequence[2001];

// overkill backtracking; better ways to solve

int getBestSequence(int i, int j, pair<int,int> target) {
    if (j < i) {
        return 0;
    } else if (i == j) {
        if ((sequence[i] == target.first && target.second == -1) || sequence[i] == target.second) {
            return 1;
        } else {
            return 0;
        }
    }
    // if we already have a target
    if (target.second != -1) {
        int constant = 0;
        if (sequence[i] == sequence[j] && sequence[i] == target.second) {
            constant = 1;  
            return getBestSequence(i + 1, j - 1, target) + 2;  
        } else {
            constant = (sequence[i] == target.second) || (sequence[j] == target.second) ? 1 : 0;
            return getBestSequence(i + 1, j - 1, target) + constant;
        }
    } else if (target.first != -1) {
        // looking for potential second target
        pair<int, int> oldpair = target;
        // make left the target
        pair<int, int> leftpair = make_pair(target.first, sequence[i]);
        // make right the target
        pair<int, int> rightpair = make_pair(target.first, sequence[j]);
        // they equal each other!
        if (sequence[i] == sequence[j]) {
            // and they are the target!
            if (sequence[i] == oldpair.first) {
                // we have no decision to make.
                return getBestSequence(i + 1, j - 1, oldpair) + 2;
            } else {
                // they aren't the target!
                // make them the target, or don't
                return max(getBestSequence(i + 1, j - 1, oldpair), getBestSequence(i + 1, j - 1, leftpair) + 2);
            }
        } else {
            // they don't equal each other
            // make left the tar, move right
            // make right the tar, move left
            // increment both and drop the potential target.
            int lc = (sequence[i] == target.first) ? 1 : 0;
            int rc = (sequence[j] == target.first) ? 1 : 0;
            if (lc > 0) {
                return max(getBestSequence(i + 1, j - 1, oldpair) + lc, getBestSequence(i + 1, j - 1, rightpair) + lc + 1);
            } else if (rc > 0) {
                return max(getBestSequence(i + 1, j - 1, oldpair) + rc, getBestSequence(i + 1, j - 1, leftpair) + rc + 1);
            } else {
                return max(max(getBestSequence(i + 1, j - 1, leftpair) + 1, getBestSequence(i + 1, j - 1, rightpair) + 1), getBestSequence(i + 1, j - 1, oldpair));
            }
        }
    } else {
        // same deal as before
        // looking for potential second target
        pair<int, int> oldpair = target;
        // make left the target
        pair<int, int> leftpair = make_pair(sequence[i], -1);
        // make right the target
        pair<int, int> rightpair = make_pair(sequence[j], -1);
        // they equal each other!
        if (sequence[i] == sequence[j]) {
            // make them the target, or don't
            return max(getBestSequence(i + 1, j - 1, oldpair), getBestSequence(i + 1, j - 1, leftpair) + 2);
        } else {
            // they don't equal each other
            // make left the tar, move right
            // make right the tar, move left
            // increment both and drop the potential target.
            return max(max(getBestSequence(i + 1, j - 1, leftpair) + 1, getBestSequence(i + 1, j - 1, rightpair) + 1), getBestSequence(i + 1, j - 1, oldpair));
        }
    }

}
void solve() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
        cin >> sequence[i];
    }
    int ans = 1;
    if (n > 2) {
        ans = getBestSequence(0, n - 1, make_pair(-1,-1));
    }
    printf("%d\n", ans);
    memset(sequence, 0, sizeof(sequence));
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
