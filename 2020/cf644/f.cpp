//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int m,n; cin >> m >> n;
	string initial; cin >> initial; m --;
	vector<string> v(m);
	for (int i = 0; i < m; i ++) {
		string next; cin >> next;
		v[i] = next;
	}
	for (int i = 0; i < n; i ++) {
		char before = initial[i];
		for (int j = 'a'; j <= 'z'; j ++) {
			initial[i] = j;
			int good = 1;
			for(int k = 0; k < m; k ++) {
				string test = v[k];
				int diffs = 0;
				for (int l = 0; l < n; l ++) {
					if (initial[l] != test[l])
						diffs ++;
					if (diffs > 1) {
						good = 0;
						break;
					}
				}
			}
			if (good){ 
				printf("%s\n", initial.c_str());
				return;
			}
		}
		initial[i] = before;
	}
	printf("-1\n"); 
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
