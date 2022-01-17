#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Given:-Directed Weighted Graph

// T.c:-O(V+E)

const int N = (1e5 + 5);

vector<int> adj[N];
vector<int> visited(N);
vector<int> dis(N);

vector<int> rev_gr[N];

void bfs(vector<int> &sources) {

	queue<int> q;

	for (int i = 0; i < sources.size(); i++) {
		int src = sources[i];
		visited[src] = 1;
		dis[src] = 0;
		q.push(src);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (auto nbr : rev_gr[node]) {
			if (visited[nbr] == 0) {
				visited[nbr] = 1;
				dis[nbr] = dis[node] + 1;
				q.push(nbr);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		// Reverse all the edges
		rev_gr[b].push_back(a);
	}

	int no_of_source;
	cin >> no_of_source;

	vector<int> sources;

	for (int i = 0; i < no_of_source; i++) {
		int x;
		cin >> x;
		sources.push_back(x);
	}

	bfs(sources);

	for (int i = 1; i <= n; i++) {
		if (dis[i] == 0) {
			continue;
		}
		cout << "Distance from " << i << " is " << dis[i] << endl;
	}

	return 0;
}

/*
7 9
1 2
1 3
2 4
3 6
2 5
6 5
5 7
6 7
4 7
3
2 5 7
*/