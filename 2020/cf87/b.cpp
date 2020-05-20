//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
	string s; cin >> s;
	int length = s.length();
	map<int, int> m;
	set<int> st;
	m[3] = 0; m[1] = 0; m[2] = 0;
	int lastStart = 0;
	int shortest = 200002;
	for (int i = 0; i < length; i ++) {
		int z = s[i];
		m[z] ++;
		st.insert(z);
		if (st.size() == 3) {
			shortest = min(shortest, i - lastStart + 1);
			while (st.size() != 2) {
				m[s[lastStart]] --;
				if (m[s[lastStart]] == 0) {
					st.erase(s[lastStart]);
				}
				lastStart++;
			}
			// the one before it had 3.
			shortest = min(shortest, i - lastStart + 2);
		}
	}
	if (shortest == 200002) {
		printf("0\n");
	} else {
		printf("%d\n", shortest);
	}

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
