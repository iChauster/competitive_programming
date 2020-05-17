#include "../../cpp/config/bits/stdc++.h"
//#include <bits/stdc++.h>

using namespace std;
int deg[26];
vector<int> adj[26];
int arr[31][31];
int visited[26];
void solve() {
	int r, c;
	cin >> r >> c;
	memset(deg, -1 ,sizeof(deg));
	for (int i = r - 1; i >= 0; i --) {
		string row; cin >> row;
		for (int j = 0; j < c; j ++) {
			arr[i][j] = row[j] - 'A';
			deg[arr[i][j]] = 0;
			visited[arr[i][j]] = 0;
			adj[arr[i][j]].clear();
		}
	}
	for (int i =  1; i < r; i ++) {
		for (int j = 0; j < c; j ++) {
			int below = arr[i-1][j];
			int current = arr[i][j];
			if (below != current && find(adj[below].begin(), adj[below].end(), current) == adj[below].end()) {
				// add dpenedncy
				deg[current] ++;
				adj[below].push_back(current);
			}
		}
	}
	// bfs
	queue<int> q;
	int toProcess = 0;
	for (int i = 0; i < 26; i ++) {
		if (deg[i] == 0) {
			q.push(i);
		} 
		if (deg[i] != -1) {
			toProcess ++;
		}
	}
	string ans = "";
	if (q.empty()) {
		printf("-1\n");
		return;
	}
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		if (visited[f]) continue;
		visited[f] = 1;
		ans.push_back((char)(f + 'A'));
		for (auto i : adj[f]) {
			deg[i] --;
			if (deg[i] == 0)
				q.push(i);
		}

	}
	if (ans.length() == toProcess)
		printf("%s\n", ans.c_str());
	else
		printf("-1\n"); 



}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tests = 0;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
    	printf("Case #%d: ", i + 1);
		solve();
    }
}
