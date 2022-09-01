#include <bits/stdc++.h>
using namespace std;

class Graph {

	map<int, list<int>> adj;
public:

	void add_edges(int src, int dest, bool bidir = true) {
		adj[src].push_back(dest);
		if (bidir) {
			adj[dest].push_back(src);
		}
	}

	void print() {
		for (auto i : adj) {
			cout << i.first << "->";

			for (auto j : i.second) {
				cout << j << ",";
			}
			cout << endl;
		}
	}
	//Recursive Dfs
	void Dfs(int v, bool visited[]) {
		visited[v] = true;
		cout << v << " ";

		for (auto i : adj[v]) {
			if (visited[i] == false) {
				Dfs(i, visited);
			}
		}
	}

	//The value of connected components will be equal to the number of times the dfs function will be called.

	void connected_comp() {

		int n = adj.size();
		bool*visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			if (visited[i] == false) {
				Dfs(i, visited);
				cout << "\n";
				cnt++;
			}
		}

		cout << "No of connected components are " << cnt << endl;
	}
};

int main() {

	Graph g;
	// g.add_edges(1, 0);
	// g.add_edges(2, 3);
	// g.add_edges(3, 4);
	g.add_edges(0, 1);
	g.add_edges(1, 2);
	g.add_edges(2, 3);
	g.add_edges(0, 3);
	g.add_edges(0, 4);
	g.add_edges(5, 6);
	g.add_edges(6, 7);
	g.connected_comp();

	return 0;
}