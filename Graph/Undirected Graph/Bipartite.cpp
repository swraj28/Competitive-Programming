#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color) {

	//come to a node
	visited[node] = color; //1 or 2,both means visited

	for (auto nbr : graph[node]) {
		if (visited[nbr] == 0) {

			bool rec_result = dfs_helper(graph, nbr, visited, node, 3 - color);

			if (rec_result == false) {
				return false;
			}

		} else if (nbr != parent  and color == visited[nbr]) {
			return false;
		}
	}

	return true;
}

bool dfs(vector<int> graph[], int n) {

	// 0-Not Visited, 1-Visited and color is 1,2- Visited and color 2.
	int visited[n] = {0};

	//Let us assume that the graph has single component.
	// If the graph several component then we need pass the dfs_helper function inside a for loop.
	int color = 1;
	bool ans = dfs_helper(graph, 0, visited, -1, color);

	//Colors
	for (int i = 0; i < n; i++) {
		cout << i << " - Color " << visited[i] << endl;
	}

	return ans;
}

// Bipartiteness using BFS:-

bool bipartiteBfs(int src, vector<int> adj[], int color[]) {

	queue<int>q;
	q.push(src);
	color[src] = 1;

	while (!q.empty()) {

		int node = q.front();
		q.pop();

		for (auto it : adj[node]) {

			if (color[it] == -1) {
				color[it] = 1 - color[node];
				q.push(it);
			} else if (color[it] == color[node]) {
				return false;
			}
		}
	}

	return true;
}

bool checkBipartite(vector<int> adj[], int n) {

	int color[n];
	memset(color, -1, sizeof color);

	for (int i = 0; i < n; i++) {

		if (color[i] == -1) {
			if (!bipartiteBfs(i, adj, color)) {
				return false;
			}
		}
	}

	return true;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//No of vertices and no of edges
	int n, m;
	cin >> n >> m;

	vector<int> graph[n];
	while (m--) {
		int x, y;
		cin >> x >> y;
		//Bidirectional Edges
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// Bfs or Dfs by coloring the node at each step (current node has color 1, nbr should have a clor 2)

	if (dfs(graph, n)) {
		cout << "Bipartite Graph" << endl;
	} else {
		cout << "Not a Bipartite Graph" << endl;
	}


	return 0;
}