//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

int n;
int k;

vector<int> adj[200001];
int depths[200001];
int visited[200001];

int dfs(int root, int depth) {
	int c = 1;	
	visited[root] = 1;
	for (auto v : adj[root]) {
		if (!visited[v]){
			c += dfs(v, depth + 1);
		}
	}
	depths[root] = depth - c;
	return c;
}
void solve() {
	cin >> n >> k;
	int u = 0;
	int v = 0;
	for (int i = 0; i < n - 1; i ++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 1);
	sort(depths + 1, depths + n + 1);
	long long sum = 0;
	for (int i = n; k > 0; i --) {
		sum += depths[i];
		k --;
	}
	printf("%lld\n", sum);
	

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    
}