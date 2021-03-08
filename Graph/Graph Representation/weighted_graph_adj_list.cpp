#include<bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<string, list<pair<string, int>>> adj;
public:

	void add_edges(string src, string dest, bool bidir, int wt) {
		adj[src].push_back(make_pair(dest, wt));
		if (bidir) {
			adj[dest].push_back(make_pair(src, wt));
		}
	}

	void print() {

		for (auto i : adj) {
			cout << i.first << "->";
			for (auto j : i.second) {
				cout << "(" << j.first << "," << j.second << ")";
			}
			cout << endl;
		}
	}

};

int main() {

	Graph g;
	g.add_edges("A", "B", true, 20);
	g.add_edges("B", "D", true, 30);
	g.add_edges("A", "C", true, 10);
	g.add_edges("C", "D", true, 40);
	g.add_edges("A", "D", false, 50);

	g.print();

	return 0;
}