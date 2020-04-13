//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int skills[200001];
int n;
set<int> s;
void solve() {
	cin >> n;
	if (n == 1) {
		cin >> n;
		printf("%d\n", 0);
		return;
	}
	int skill;
	for (int i = 0; i < n; i ++) {
		cin >> skill;
		skills[i] = skill;
		s.insert(skill);
	}

	sort(skills, skills + n);
	int longestDuplicate = 0;
	int currentDuplicate = 0;
	int prev = -1;

	for (int i = 0; i < n; i ++){
		int curr = skills[i];
		if (curr != prev) {
			longestDuplicate = max(currentDuplicate, longestDuplicate);
			currentDuplicate = 0;
			prev = curr;
		} else {
			currentDuplicate += 1;
		}
	}

	if (currentDuplicate > 0) {
		longestDuplicate = max(currentDuplicate, longestDuplicate);
	}

	// find max of splitting duplicates, splitting them, and no duplicate sets.
	int m =  max(max(min((int)s.size(), longestDuplicate), min((int) s.size() - 1, longestDuplicate + 1)), 1);

	printf("%d\n", m);
	memset(skills, -1, sizeof(skills));
	s.clear();
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