#include <iostream>
#include <vector>
using namespace std;
int V;
int L;
vector<vector<int>> adj;
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;
int installed;
int dfs(int here) {
	visited[here] = true;
	int children[3] = { 0,0,0 };
	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there])
			++children[dfs(there)];
	}
	if (children[UNWATCHED]) {
		++installed;
		return INSTALLED;
	}
	if (children[INSTALLED])
		return WATCHED;
	return UNWATCHED;
}
int installCamera() {
	installed = 0;
	visited = vector<bool>(V, false);
	for (int u = 0; u < V; ++u) {
		if (!visited[u] && dfs(u) == UNWATCHED)
			++installed;
	}
	return installed;
 }

void main() {
	cin >> V >> L;
	for (int i = 0; i < V; i++) {
		vector<int> a;
		adj.push_back(a);
	}
	for (int i = 0; i < L; i++) {
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}
	cout << installCamera();
}