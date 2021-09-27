#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {

	map<int, list<int>> adj;
public:

	Graph() {  // Default Constructor

	}

	void addEdges(int src, int dest) {
		//We have a directed Graph
		adj[src].push_back(dest);
	}

	void toplogical_sort() {

		queue<int> q;
		map<int, bool> visited;
		map<int , int> indegree;

		for (auto i : adj) {
			int node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}

		//Init the indegree of each node
		for (auto i : adj) {
			int node = i.first;

			for (auto nbr : adj[node]) {
				indegree[nbr]++;
			}
		}

		//Find all the nodes with 0 indegree
		for (auto i : adj) {
			int node = i.first;
			if (indegree[node] == 0) {
				q.push(node);
			}
		}

		// Starts with algorithm

		while (!q.empty()) {

			int node = q.front();
			q.pop();

			cout << node << " ";

			for (auto nbr : adj[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Graph g;

	g.addEdges(0, 1);
	g.addEdges(1, 2);
	g.addEdges(1, 4);
	g.addEdges(2, 3);
	g.addEdges(2, 5);
	g.addEdges(3, 5);
	g.addEdges(4, 5);

	cout << "The one of the Possible Toplogical ordering is" << endl;
	g.toplogical_sort();

	return 0;
}