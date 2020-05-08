//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[200000], radj[200000];
int vis[200000], rvis[200000];

bool fdfs(int i) {
	vis[i] = -1;
	for(auto edge: adj[i]) {
		if (vis[edge] == -1) return false;
		if (vis[edge] == 0 && !fdfs(edge)) return false;
	}
	vis[i] = 1;
	return true;
}

bool rdfs(int i) {
	rvis[i] = -1;
	for (auto edge: radj[i]) {
		if (rvis[edge] == -1) return false;
		if (rvis[edge] == 0 && !rdfs(edge)) return false;
	}
	rvis[i] = 1;
	return true;
}


void solve() {
	string r = "";
	int u = 0;
	for (int i = 0; i < n; i ++) {
		if(vis[i] == 0 && rvis[i] == 0) {
			u ++; r += "A";
		} else {
			r += "E";
		}
		
		// run DFS
		if ((vis[i] == 0 && !fdfs(i)) || (rvis[i] == 0 && !rdfs(i))){
			printf("-1\n");
			return;
		}
	}
	printf("%d\n%s\n", u, r.c_str());
}

int main() {
    ios_base::sync_with_stdio(false);
    
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i ++) {
		int left, right; cin >> left >> right;
		--left; --right;
		adj[left].push_back(right);
		radj[right].push_back(left);
	}

    solve();
}
