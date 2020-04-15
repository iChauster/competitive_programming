//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

long long health[300001];
long long edge[300001];
int n;
void solve() {
	cin >> n;
	long long ld = 0;
	long long d = 0;
	long long edgeSum = 0;

	for (int i = 0; i < n; i ++) {
		cin >> health[i] >> d;
		if (i > 0) {
			edge[i - 1] = (ld >= health[i]) ? 0 : health[i] - ld;
			edgeSum += edge[i - 1];
		}
		ld = d; 
	}

	edge[n - 1] = (ld >= health[0]) ? 0 : health[0] - ld;
	edgeSum += edge[n - 1];

	long long minSum = LLONG_MAX;
	for (int i = 0; i < n; i ++) {
		long long nextEdge = edge[i];
		long long prevEdge;
		if (i == 0) {
			prevEdge = edge[n - 1];
		} else {
			prevEdge = edge[i - 1];
		}
		minSum = min(minSum, edgeSum - prevEdge + health[i]);
	}

	printf("%lld\n", minSum);

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