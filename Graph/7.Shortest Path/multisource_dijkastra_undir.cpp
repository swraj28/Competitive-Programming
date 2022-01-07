#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Given :-Undirected Weighted Graph

// T.c:-O(N+M)log(N).

const int INF = 1000000000;

const int N = (1e5 + 5);

vector<pair<int, int>> adj[N];
vector<int> dis(N);
vector<int> visited(N);
vector<int> par(N);

set<pair<int, int>> s; //{distance,neighbour}

void multisource_dijkastra_undir() {

	while (!s.empty()) {

		int v = s.begin()->second;
		s.erase(s.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (dis[v] + len < dis[to]) {
				s.erase({dis[to], to});
				dis[to] = dis[v] + len;
				par[to] = v;
				s.insert({dis[to], to});
			}
		}
	}
}

void get_path(int v) {

	if (dis[v] == INF) {
		cout << "No Path" << endl;
		return;
	}

	if (par[v] == -1) {
		cout << v << "->";
		return;
	}

	get_path(par[v]);
	cout << v << "->";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	int no_of_source;
	cin >> no_of_source;

	vector<int> sources;

	for (int i = 0; i < no_of_source; i++) {
		int x;
		cin >> x;
		sources.push_back(x);
	}

	set<int> s1;

	for (int i = 0; i < sources.size(); i++) {
		s1.insert(sources[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (s1.find(i) == s1.end()) {
			dis[i] = INF;
		} else {
			dis[i] = 0;
			s.insert({0, i});
			visited[i] = 1;
		}
		par[i] = -1;
	}

	multisource_dijkastra_undir();

	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0) {
			continue;
		}
		cout << "Distance of " << i << " is " << dis[i] << endl;
	}

	cout << endl;

	for (int i = 1; i <= n; i++) {
		if (s1.find(i) != s1.end()) { // Police Stations
			continue;
		}

		get_path(i);
		cout << endl;
	}

	return 0;
}

/*
10 13
1 2 5
1 3 8
2 4 9
3 4 1
1 5 1
3 6 2
5 6 1
6 7 4
5 10 2
6 10 4
7 9 3
10 9 2
8 9 4
3
1 7 10
*/