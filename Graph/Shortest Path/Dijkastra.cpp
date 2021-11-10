#include<bits/stdc++.h>
using namespace std;
#define ll long long

//T.c-O((n^2)+m)

const int INF = 1000000000;

vector<vector<pair<int, int>>> adj;

void dijkstra(int s, vector<int> & d, vector<int> & p) {

	int n = adj.size();
	d.assign(n, INF); //distance from the src node
	p.assign(n, -1);  // Predecessor of every node

	vector<bool> u(n, false);  // Every node in u will be marked only when if we find its minimum distance from the src node.

	d[s] = 0;

	for (int i = 0; i < n; i++) {

		int v = -1;

		// optimization:-

		// Since for every we are iterating n times to find its least length neighbour.
		// Therefore we can use some data structure like sets or priority queue to reduce the searching for every node from n to log(n).
		// The set or priority queue will only contain the unmarked node.
		for (int j = 0; j < n; j++) {

			if (!u[j] && (v == -1 || d[j] < d[v])) { // Least length neighbour
				v = j;
			}
		}

		if (d[v] == INF) { // This node is unreachable from the src.
			break;
		}

		u[v] = true;

		//  In totallity it will loop 2*m times (upper_bound) only throughout the process (m->no of edges)

		// suppose two vertices 'u' and 'v' are connected to each other then u will make a relallxation operation on v and v will make a
		// relaxation operation on u. Therefor for a single edge at max 2 relaxation operation can be performed.

		for (auto edge : adj[v]) { // Relaxation

			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}

vector<int> restore_path(int s, int t, vector<int> const& p) {

	vector<int> path;

	for (int v = t; v != s; v = p[v]) {
		path.push_back(v);
	}

	path.push_back(s);

	reverse(path.begin(), path.end());

	return path;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	adj.resize(n);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}


	vector<int> d;
	vector<int> p;

	dijkstra(0, d, p);

	for (auto i : d) {
		cout << i << " ";
	}
	cout << endl;

	vector<int> path = restore_path(0, 5, p);

	for (auto i : path) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}

/*
7 9
0 1 12
1 2 13
0 3 18
0 4 2
1 4 9
2 5 3
3 4 22
3 6 100
4 6 15
*/