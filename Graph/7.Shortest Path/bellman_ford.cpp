#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

/*
Steps in Bellman Ford Algorithm
_______________________________

1) Init dist[vertices] = INT_MAX, dist[src] = 0
2) Relax all edges V - 1 times (Most Imp)
3) Negative Weight Cycle Detection

*/

// n->no. of nodes
// m-> no. of edges.

// At max a graph can have (nc2) edges roughly equal to o(n^2)

// Time Complexity :- O(n*m);--> o(n^3)

vector<int> bellman_ford(int V, int src, vector<vector<int> > edges) {

	//create a vector
	vector<int> dist(V + 1, INT_MAX);
	dist[src] = 0;

	//relax all edges v-1 times--> if we have 'v' number of vertices then the longest path  will have at most (v-1) edges.

	/*
	     Assertion of Bellman Ford Algorithm:-
	           -->After the execution of ith phase,
	           the Bellman-Ford algorithm correctly finds all shortest paths whose number of edges does not exceed i.
	*/

	for (int i = 0; i < V - 1; i++) {

		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	// negative wt cycle--> If after (v-1) iterations,i.e.,at the v the iteration if the shortest distance of any node from the source changes then it
	// contains negative weight cycle.

	bool negative_cycle_present_affecting_the_distance_from_src = false;

	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {

			negative_cycle_present_affecting_the_distance_from_src = true;
			break;
		}
	}

	if (negative_cycle_present_affecting_the_distance_from_src) {

		return vector<int>();
	}

	return dist;
}

// Mark all the node as "-INF" that forms a negative weight cycle.

vector<int> bellman_ford_1(int V, int src, vector<vector<int> > edges) {

	//create a vector
	vector<int> dist(V + 1, INT_MAX);
	dist[src] = 0;

	// Perform the relaxation operation for (2*v) times so that all the nodes that associates with negative edge weight gets marked as -INF.

	for (int i = 0; i < 2 * V; i++) {

		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];

			if (i < V - 1) {
				if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
					dist[v] = dist[u] + wt;
				}
			} else {
				if (dist[u] != INT_MAX and dist[u] + wt < dist[v]) {
					dist[v] = INT_MIN;
				}
			}
		}
	}

	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	//edge list
	vector<vector<int>> edges;       // (a,b,3) (c,d,5) ....

	for (int i = 0; i < m; i++) {
		int u, v, wt;
		cin >> u >> v >> wt;
		edges.push_back({u, v, wt});
	}

	//bellman algorithm

	vector<int> distances = bellman_ford(n, 1, edges);

	if (distances.size() == 0)
		cout << "Graph contains negative weight cycle." << endl;
	else {

		for (int i = 1; i <= n; i++) {
			cout << "Node " << i << " is at dist " << distances[i] << endl;
		}
	}

	return 0;
}