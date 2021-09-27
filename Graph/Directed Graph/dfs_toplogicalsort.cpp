#include<bits/stdc++.h>
#include<map>
#include<list>
using namespace std;

template<typename T>

class Graph {

	map<T, list<T>> adjList;

public:
	Graph() {

	}

	void addEdge(T u, T v) {
		adjList[u].push_back(v);
	}

	void print() {

		//Iterate over the map
		for (auto i : adjList) {
			cout << i.first << "->";

			//i.second is LL
			for (T entry : i.second) {
				cout << entry << ",";
			}
			cout << endl;
		}
	}

	void dfsHelper(T node, map<T, bool> &visited, list<T> &ordering) {

		//Whenever to come to a node, mark it visited.
		visited[node] = true;

		//Try to find out a node which is neigbour of current node and not yet visited.

		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited, ordering);
			}
		}

		ordering.push_front(node);

		// for (auto node : ordering) {
		// 	cout << node << endl;
		// }
		// cout << endl;
		// return;
	}

	void dfs() {

		map<T, bool> visited;
		list<T> ordering;
		//Mark all the nodes as not visited in the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}

		// Call the helper function

		// Dfs is being called on every node

		for (auto p : adjList) {
			T node = p.first;
			if (!visited[node]) {
				dfsHelper(node, visited, ordering);
			}
		}

		//Print the list

		reverse(ordering.begin(), ordering.end());

		for (auto node : ordering) {
			cout << node << endl;
		}

	}
};

int main() {

	// Graph<string> g;
	// g.addEdge("Python", "DataPreprocessing");
	// g.addEdge("Python", "Pytorch");
	// g.addEdge("Python", "ML");
	// g.addEdge("Pytorch", "DL");
	// g.addEdge("ML", "DL");
	// g.addEdge("DL", "FaceRecognition");
	// g.addEdge("Dataset", "FaceRecognition");

	// g.dfs("Python");

	Graph<int> g;
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 4);
	g.addEdge(3, 4);

	g.dfs();

	// Graph<char> g;
	// g.addEdge('z', 'x');
	// g.addEdge('z', 'y');
	// g.addEdge('y', 'a');
	// g.addEdge('x', 'a');
	// g.addEdge('x', 'b');
	// g.addEdge('x', 'c');

	// g.dfs();


	return 0;
}