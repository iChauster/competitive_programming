//#include <bits/stdc++.h>
#include "../config/bits/stdc++.h"

using namespace std;

long long horses;
int stops;
pair<long long, int> horseMatrix[101];
long long distanceTo[101];
double dp[101];

// watch for number limits... would've fooled me if tests weren't visible.
// only solves small, for large, use floyd-marshall to get shortest distance pairs between all nodes
// then divide nodes by the horses at first node. then re-compute shortest time pairs and 
// return queries.

void solve() {
	
	cin >> horses >> stops;

	// couldn't find out why memset(dp, 0x3f, sizeof(dp)) wasn't working.
	
	for (int i = 0; i < 100; i ++) {
		dp[i] = LLONG_MAX; // setting to 1e9 is not viable here given limits.
	}

	long long endurance;
	int speed;
	for (int horse = 0; horse < horses; horse ++) {
		cin >> endurance >> speed;
		horseMatrix[horse] = make_pair(endurance, speed);
	}

	for (int city = 0; city < horses; city ++) {
		for (int paths = 0; paths < horses; paths ++) {
			long long throwaway;
			cin >> throwaway;
			if (paths == city + 1) {
				distanceTo[paths] = distanceTo[city] + throwaway;
			}
		}
	}

	// compute dp
	dp[0] = 0.0;
	for (int i = 1; i < horses; i ++){
		for (int j = 0; j < i; j ++) {
			long long totalDistance = distanceTo[i] - distanceTo[j];
			pair<long long, int> horse = horseMatrix[j];
			if (totalDistance <= horse.first) {
				dp[i] = min(dp[i],  totalDistance / (double) horse.second + dp[j]);
			} 
		}
	}

	int begin, end;

	cin >> begin >> end;

	printf("%f\n", dp[horses - 1]);
	
}

int tests;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
    	memset(horseMatrix, 0, sizeof(horseMatrix));
		memset(distanceTo, 0, sizeof(distanceTo));
    	solve();
    }
}
