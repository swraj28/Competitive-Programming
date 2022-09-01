# include<bits/stdc++.h>
using namespace std;

class Graph {

	int V;
	list<int> *l;//pointer to the array of lists.(Here we do not know the no.of vetices during the compile time but it will be known during run time)

public:
	Graph(int v) {//constructor that create a list of size v.
		V = v;
		//Array of Linked Lists(l is a pointer on array where each element is a list)
		l = new list<int>[V];
	}

	void addEdge(int u, int v, bool bidir = true) {
		l[u].push_back(v);
		if (bidir) {
			l[v].push_back(u);
		}
	}

	void printAdjList() {
		for (int i = 0; i < V; i++) {

			cout << i << "->";
			//l[i] is a linked list
			for (int vertex : l[i]) {
				cout << vertex << ",";
			}
			cout << endl;
		}
	}
};

int main() {

	// Graph has 5 vertices number from 0 to 4
	Graph g(5);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(4, 3);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(1, 3);

	g.printAdjList();

	return 0;
}

// A simple representation of graph using STL

// // A utility function to add an edge in an
// // undirected graph.

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// A utility function to print the adjacency list
// representation of graph
void printGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\n Adjacency list of vertex "
		     << v << "\n head ";
		for (auto x : adj[v])
			cout << "-> " << x;
		printf("\n");
	}
}

// Driver code
int main()
{
	int V = 5;
	vector<int> adj[V];
	addEdge(adj, 0, 1);
	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	printGraph(adj, V);
	return 0;
}

