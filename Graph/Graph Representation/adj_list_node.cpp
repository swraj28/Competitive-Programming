#include<bits/stdc++.h>
using namespace std;

class Node {

public:
	list<string> nbrs;
};

class Graph {

	// This map stores the neighbour for every city
	unordered_map<string, Node*> adj;

public:

	Graph(vector<string> cities) {
		for (auto city : cities) {
			adj[city] = new Node();
		}
	}

	void addEdge(string x, string y, bool bidir = false) {
		adj[x]->nbrs.push_back(y);
		if (bidir) {
			adj[y]->nbrs.push_back(x);
		}
	}

	void print_list() {

		for (auto cityPair : adj) {

			string city = cityPair.first;

			cout << city << "->";

			Node* node = cityPair.second;

			for (auto nbr : node->nbrs) {
				cout << nbr << ",";
			}
			cout << endl;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<string> cities = {"Delhi", "London", "Paris", "New York"};
	Graph g(cities);
	g.addEdge("Delhi", "London");
	g.addEdge("New York", "London");
	g.addEdge("Delhi", "Paris");
	g.addEdge("Paris", "New York");

	g.print_list();

	return 0;
}