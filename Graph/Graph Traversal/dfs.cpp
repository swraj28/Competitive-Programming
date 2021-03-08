#include<bits/stdc++.h>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph {

	map<T, list<T>> adjList;

public:
	// Default Constructor
	Graph() {

	}
	void addEdge(T u, T v, bool bidir = true) {

		adjList[u].push_back(v);
		if (bidir) {
			adjList[v].push_back(u);
		}
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
	//Dfs Recursive:-(Implict Stack)
	void dfsHelper(T node, map<T, bool> &visited) {
		//Whenever to come to a node, mark it visited
		visited[node] = true;
		cout << node << " ";

		//Try to find out a node which is neigbour of current node and not yet visited
		for (T neighbour : adjList[node]) {
			if (!visited[neighbour]) {
				dfsHelper(neighbour, visited);
			}
		}
	}
	void dfs(T src) {
		map<T, bool> visited;
		//Mark all the nodes as not visited in the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}
		dfsHelper(src, visited);
	}

	//Dfs Iterative:-(We use Explict stack)
	void Dfs_iterative(T src) {
		map<T, bool> visited;
		//Mark all the nodes as not visited in the beginning
		for (auto p : adjList) {
			T node = p.first;
			visited[node] = false;
		}
		stack <T> s;
		s.push(src);
		visited[src] = true;
		while (!s.empty()) {
			T v = s.top();
			s.pop();
			cout << v << " ";

			for (auto neighbour : adjList[v]) {
				if (!visited[neighbour]) {
					s.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
		cout << endl;
	}
};

int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(0, 4);
	g.addEdge(2, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(3, 5);
	cout << "The required Graph is " << endl;
	g.print();
	cout << "Dfs Recursive Implementaion" << endl;
	g.dfs(0);
	cout << endl;
	cout << "Dfs Iterative Implementaion" << endl;
	g.Dfs_iterative(0);


	return 0;
}