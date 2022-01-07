#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int INF = 1000000000;

// T.c:-O(N+M)log(N).

vector<vector<pair<int, int>>> adj;

void dijkstra_set(int s, vector<int> & d, vector<int> & p) {

	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);

	d[s] = 0;

	set<pair<int, int>> q;

	q.insert({0, s});  // {distance,node}

	while (!q.empty()) {

		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : adj[v]) {

			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {

				auto itr = q.find({d[to], to});

				if (itr != q.end()) {
					q.erase({d[to], to});
				}

				d[to] = d[v] + len;
				p[to] = v;
				q.insert({d[to], to});
			}
		}
	}
}

// vector<int> restore_path(int s, int t, vector<int> const& p) {

// 	vector<int> path;

// 	for (int v = t; v != s; v = p[v]) {
// 		path.push_back(v);
// 	}

// 	path.push_back(s);

// 	reverse(path.begin(), path.end());

// 	return path;
// }

void get_path(int v, vector<int> &d, vector<int> &p) {

	if (d[v] == INF) {
		cout << "No Path" << endl;
		return;
	}

	if (p[v] == -1) {
		cout << v << "->";
		return;
	}

	get_path(p[v], d, p);
	cout << v << "->";
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

	dijkstra_set(0, d, p);

	for (auto i : d) {
		cout << i << " ";
	}
	cout << endl;

	// for (int i = 0; i < n; i++) {
	// 	get_path(i, d, p);
	// 	cout << endl;
	// }

	// vector<int> path = restore_path(0, 5, p);

	// for (auto i : path) {
	// 	cout << i << " ";
	// }
	// cout << endl;

	return 0;
}