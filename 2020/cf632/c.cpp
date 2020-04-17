//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;


void solve() {
	long long n;
	cin >> n;
	long long prefix[200001];
	prefix[0] = 0;
	for (int i = 0; i < n; i ++) {
		long long curr; cin >> curr;
		prefix[i + 1] = prefix[i] + curr;
	}
	int begin = 0;
	int end = 0;
	set<long long> prefixes = {0};
	long long ans = 0;
	while (begin < n) {
		while (end < n && prefixes.count(prefix[end + 1]) == 0) {
			prefixes.insert(prefix[end + 1]);
			end ++;
		}
		ans += end - begin;
		prefixes.erase(prefix[begin]);
		begin ++;
	}
	printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}