//#include "../../cpp/config/bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x; cin >> n >> x;
	vector<int> degree(n + 1, 0);
	vector<int> adj[1001];

	for (int i = 0; i < n - 1; i ++) {
		int to, from; cin >> to >> from;
		adj[to].push_back(from);
		adj[from].push_back(to);
		degree[to] ++; degree[from] ++;
	}
	if (n == 1) {
		printf("Ayush\n");
		return;
	}
	if (degree[x] <= 1) {
		printf("Ayush\n");
		return;
	}
	/*
	vector<int> leafs;
	for (int i = 0; i < n; i ++) {
		if (degree[i] == 1) {
			//leafs.push_back(i);
			if (i == x) {
				printf("Ayush\n");
				return;
			}
		}
	}
	*/
	if (n % 2) {
		printf("Ashish\n");
		return;
	} else {
		printf("Ayush\n");
		return;
	}
	/*
	int lowestDepth = 1e9;
	for (auto leaf : leafs) {
		printf("doing bfs");
		queue<int> q;
		q.push(leaf);
		int depth = 0;
		while(!q.empty()){
			int front = q.front();
			q.pop();
			if (front == x) {
				lowestDepth = min(lowestDepth, depth);
				break;
			}
			for (auto e : adj[front]) {
				if (e != front)
					q.push(e);
			}
			depth ++;
		}
	}
	if (lowestDepth % 2 == 0) printf("Ayush\n"); 
	else printf("Ashish\n");
	*/
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
