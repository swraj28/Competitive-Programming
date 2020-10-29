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
				cout << j << " ";
			}
			cout << endl;
		}
	}

	void Dfs(int v, map<int, bool> &visited, map<int, list<int>> &adj) {
		visited[v] = true;
		for (auto i : adj[v]) {
			if (visited[i] == false) {
				Dfs(i, visited, adj);
			}
		}
	}

	int find_articulation_point() {
		int count = 0;
		int v = adj.size();
		map<int, bool> visited;
		for (int i = 0; i < v; i++) {
			visited[i] = false;
		}
		int initial_comp = 0;
		for (int i = 0; i < v; i++) {
			if (visited[i] == false) {
				Dfs(i, visited, adj);
				initial_comp++;
			}
		}

		map<int, list<int>> adj1;
		for (int i = 0; i < v; i++) {

			for (auto j : adj) {
				if (j.first == i) {
					for (auto k : j.second) {
						for (auto t : adj[k]) {
						}
					}
					continue;
				} else {
					for (auto k : j.second) {
						if (k == i) {
							continue;
						} else {
							adj1[j.first].push_back(k);
						}
					}
				}
			}
			for (auto i : adj1) {
				cout << i.first << "->";
				for (auto j : i.second) {
					cout << j << " ";
				}
				cout << endl;
			}
			cout << endl;
			int temp_val = 0;
			map<int, bool> visited1;

			for (auto i : adj1) {
				int node = i.first;
				visited1[node] = false;
			}
			for (auto i : adj1) {
				int node = i.first;

				if (visited1[node] == false) {
					Dfs(node, visited1, adj1);
					temp_val++;
				}
			}
			if (temp_val > initial_comp) {
				count++;
			}
			adj1.clear();
		}
		return count;
	}
};

int main() {

	Graph g;
	g.add_edges(1, 0);
	g.add_edges(0, 2);
	g.add_edges(2, 1);
	g.add_edges(0, 3);
	g.add_edges(3, 4);
	// g.add_edges(2, 4);
	// g.add_edges(3, 4);

	cout << g.find_articulation_point() << endl;

	return 0;
}