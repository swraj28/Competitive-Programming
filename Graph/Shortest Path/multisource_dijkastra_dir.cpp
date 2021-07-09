#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Given:- Directed Weighted Graph

const int INF = 1000000000;

const int N = (1e5 + 5);

vector<pair<int, int>> adj[N];
vector<int> dis(N);
vector<int> visited(N);
vector<int> par(N);

vector<pair<int, int>> rev_gr[N];

set<pair<int, int>> s; //{distance,neighbour}

void multisource_dijkastra_dir() {

	while (!s.empty()) {

		int v = s.begin()->second;
		s.erase(s.begin());

		for (auto edge : rev_gr[v]) {
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
		rev_gr[b].push_back({a, w});
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

	multisource_dijkastra_dir();

	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0) {
			continue;
		}
		cout << "Distance from " << i << " is " << dis[i] << endl;
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
7 9
1 2 1
1 3 1
3 6 2
2 5 4
6 5 5
2 4 2
5 7 1
4 7 8
6 7 3
3
2 5 7
*/