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

};

int main() {

	Graph g;
	g.add_edges(1, 0);
	g.add_edges(0, 2);
	g.add_edges(2, 1);
	g.add_edges(0, 3);
	g.add_edges(3, 4);
	g.add_edges(2, 4);
	g.add_edges(3, 4);

	return 0;
}