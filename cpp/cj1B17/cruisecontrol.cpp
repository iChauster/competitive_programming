//#include <bits/stdc++.h>
#include "../config/bits/stdc++.h"

using namespace std;

long long d;
int n;

void solve() {
	cin >> d >> n;
	double maxTime = -1;
	double horsePos;
	double horseRate;
	for (int horse = 0; horse < n; horse ++) {
		cin >> horsePos >> horseRate;
		maxTime = max((d - horsePos) / (horseRate * 1.0), maxTime * 1.0);
	}
	printf("%f\n", d / maxTime);
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
