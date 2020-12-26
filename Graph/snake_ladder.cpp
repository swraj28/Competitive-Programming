#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
// 10 x 10 board
#define N 100

// data structure to store graph edges
struct Edge {
	int src, dest;
};

// class to represent a graph object
class Graph
{
public:
	// An array of vectors to represent adjacency list
	vector<int> adjList[N + 1];

	// Constructor
	Graph(vector<Edge> const &edges)
	{
		// add edges to the graph
		for (Edge edge : edges)
		{
			int src = edge.src;
			int dest = edge.dest;

			// Please note that directed is directed
			adjList[src].push_back(dest);
		}
	}
};

// A queue node
struct Node
{
	// stores number associated with graph node
	int ver;

	// minDist stores minimum distance of node from source node
	int minDist;
};

// Perform BFS on graph g starting from given source vertex
void BFS(Graph const& g, int source)
{
	// create a queue used to do BFS
	queue<Node> q;

	// stores vertex is discovered or not
	vector<bool> discovered(N + 1);

	// mark source vertex as discovered
	discovered[source] = true;

	// assign minimum distance of source vertex as 0 and
	// push it into the queue
	Node node = { source, 0 };
	q.push(node);
	vector<int> pred(N + 1);
	pred[source] = -1;

	// loop till queue is empty
	while (!q.empty())
	{
		// pop front node from queue
		node = q.front();
		q.pop();

		// Stop BFS if we have reached last node
		if (node.ver == N)
		{
			cout << "The Minimum No dice throw required is" << endl;
			cout << node.minDist << endl;
			break;
		}

		// do for every adjacent node of current node
		for (int u : g.adjList[node.ver])
			if (!discovered[u])
			{
				// mark it discovered & push it into queue
				discovered[u] = true;

				// assign minimum distance of current node
				// as minimum distance of parent node + 1
				Node n = { u, node.minDist + 1 };
				pred[u] = node.ver;
				q.push(n);
			}
	}
	vector<int> path;
	path.push_back(100);
	int x = 100;
	while (pred[x] != 0) {
		path.push_back(pred[x]);
		x = pred[x];
	}
	cout << "One of the Probable Path is" << endl;
	cout << 0 << " ";
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << " ";
	}
	cout << endl;
}

void findSolution(unordered_map<int, int> &ladder, unordered_map<int, int> &snake)
{
	// find all edges involved and store them in a vector
	vector<Edge> edges;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= 6 && i + j <= N; j++)
		{
			int src = i;

			// update destination if there is any ladder
			// or snake from current position.
			int dest = (ladder[i + j] || snake[i + j]) ?
			           (ladder[i + j] + snake[i + j]) : (i + j);

			// add edge from src to dest
			Edge e = { src, dest };
			edges.push_back(e);
		}
	}

	// construct directed graph
	Graph g(edges);
	//Print The Directed Graph
	// for (int i = 0; i <= 100; i++) {
	// 	cout << i << "->";
	// 	for (auto j : g.adjList[i]) {
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }
	// Find Shortest path between 1 and 100 using BFS
	BFS(g, 0);
}

int main()
{
	// snakes and ladders are represented using a map
	unordered_map<int, int> ladder, snake;

	// insert ladders into the map
	ladder[1] = 38;
	ladder[4] = 14;
	ladder[9] = 31;
	ladder[21] = 42;
	ladder[28] = 84;
	ladder[51] = 67;
	ladder[72] = 91;
	ladder[80] = 99;

	// insert snakes into the map
	snake[17] = 7;
	snake[54] = 34;
	snake[62] = 19;
	snake[64] = 60;
	snake[87] = 36;
	snake[93] = 73;
	snake[95] = 75;
	snake[98] = 79;

	findSolution(ladder, snake);

	return 0;
}