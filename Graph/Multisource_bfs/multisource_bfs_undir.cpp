#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Given:-Undirected Unweighted Graph

// T.c:-O(V+E)

const int N = (1e5 + 5);

vector<int> adj[N];
vector<int> visited(N);
vector<int> dis(N);

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

		for (auto nbr : adj[node]) {
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
		adj[b].push_back(a);
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
		cout << "Distance of " << i << " is " << dis[i] << endl;
	}


	return 0;
}

/*
10 13
1 2
1 3
2 4
3 4
1 5
3 6
5 6
6 7
5 10
6 10
9 10
7 9
8 9
3
1 7 10
*/