//#include <bits/stdc++.h>
#include "../config/bits/stdc++.h"

using namespace std;

int horses;
int horsesArray[6];
map<int, string > specials;

// use python next time

string getMap(int index) {
	switch (index) {
		case 0:
			return "R";
		case 1:
			return "O";
		case 2:
			return "Y";
		case 3:
			return "G";
		case 4:
			return "B";
		case 5:
			return "V";
		default:
			return "ERR";
	}
}

void getHybridString(int index, int inverse, int hybridCount) {
	string r = "";
	for (int i = 0; i < hybridCount; i ++) {
		r.append(getMap(inverse).append(getMap(index)));
	}
	r.append(getMap(inverse));
	specials.insert(make_pair(inverse, r));
}

void solve() {
	cin >> horses;
	string solution[1001];
	specials.clear();
	for (int i = 0; i < 6; i ++){
		cin >> horsesArray[i];
	}
	
	int hybrids = 0;
	int sideConstant = 0;
	int otherCounts = 1;
	for (int i = 1; i <= 5; i += 2) {
		if (horsesArray[i] != 0){
			hybrids = 1;
			int inverse = (i + 3) % 6;
			otherCounts = 0;
			for (int j = 0; j <= 5; j ++) {
				if (i != j && inverse != j && horsesArray[j] != 0) {
					otherCounts = 1;
					break;
				}
			}
			if (otherCounts == 0) {
				sideConstant = -1;

			}
		}
	}
	
	for (int i = 1; i <= 5; i += 2) {
		int inverse = (i + 3) % 6;
		if (horsesArray[i] != 0 && horsesArray[i] <= horsesArray[inverse] + 1 + sideConstant) {
			getHybridString(i, inverse, horsesArray[i]);
			horsesArray[inverse] -= horsesArray[i];
		} else {
			if (horsesArray[i] != 0){
				printf("IMPOSSIBLE");
				return;
			}
		}
	}
	
	// solve general case of only 3
	
	vector<pair<int, int> > v;
	for (int i = 0; i < 6; i += 2) {
		v.push_back(make_pair(horsesArray[i], i));
	}
	sort(v.begin(), v.end());

	int sum = 0;
	for (pair<int, int> p : v) {
		sum += p.first;
	}

	pair<int, int> back = v.back();
	// check if possible
	if (back.first > floor(horses / 2)) {
		printf("IMPOSSIBLE\n");
		return;
	}
	for (int i = 0; i < sum; i += 2) {
		pair<int, int> last = v.back();
		if (last.first == 0) {
			if (v.size() > 0){
				v.pop_back();
				last = v.back();
				v.back().first -= 1;
				solution[i] = getMap(last.second);
			} else {
				break;
			}
		} else {
			v.back().first -= 1;
			solution[i] = getMap(last.second);
		}
	}

	for(int i = 1; i < sum; i += 2) {

		pair<int, int> last = v.back();
		if (last.first == 0) {
			if (v.size() > 0){
				v.pop_back();
				last = v.back();
				v.back().first -= 1;
				solution[i] = getMap(last.second);
			} else {
				break;
			}
		} else {
			v.back().first -= 1;
			solution[i] = getMap(last.second);
		}
	}
	if (otherCounts > 0) {
		for (int i = 0; i < 1001; i ++ ){
			printf("%s", solution[i].c_str());
		}
		printf("\n");
	} else {
		for (int i = 0; i < 6; i ++){
			printf("%s\n", specials[i].c_str());
		}

	}
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
