#include <bits/stdc++.h>
//#include "../config/bits/stdc++.h"

using namespace std;

int people;
int n;
vector< pair<int,int> > xp;
vector< pair<int,int> > yp;

int subProb(vector<pair<int,int> > p){
	int maxIndex = 0;
	int maxVotes = 0;
	for (int i = 0; i <= n; i ++) {
		int votes = 0;
		for (int j = 0; j < p.size(); j ++) {
			pair<int,int> person = p[j];
			if (i > person.first && person.second == 1) {
				votes += 1;
			} else if (i < person.first && person.second == -1) {
				votes += 1;
			}
		}
		if (votes > maxVotes) {
			maxVotes = votes;
			maxIndex = i;
		}
	}
	return maxIndex;
}

void solve() {
	cin >> people >> n;
	
	int x;
	int y;
	char z;

	xp.clear();
	yp.clear();

	for (int p = 0; p < people; p ++) {
		cin >> x >> y >> z;
		int constant = 0;
		if (z == 'N' || z == 'S') {
			if (z == 'N') {
				constant = 1;
			} else {
				constant = -1;
			}
			yp.push_back(make_pair(y, constant));
		} else {
			if (z == 'E') {
				constant = 1;
			} else {
				constant = -1;
			}
			xp.push_back(make_pair(x, constant));
		}
	}

	int horizontalAnswer = subProb(xp);
	int verticalAnswer = subProb(yp);

	printf("%d %d\n", horizontalAnswer, verticalAnswer);
}

int tests;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
    	solve();
    }
}
