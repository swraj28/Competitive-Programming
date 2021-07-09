#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

void bfs(vector<int> graph[], int src, int n, int &ans) {

	vector<int> dis(n + 1, INT_MAX);
	queue<int> q;
	q.push(src);
	dis[src] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto nbr : graph[cur]) {
			//The neighbour is not visited
			if (dis[nbr] == INT_MAX) {
				// 1 is added for the backedge
				dis[nbr] = dis[cur] + 1;
				q.push(nbr);
			} else if (dis[nbr] >= dis[cur]) {
				// Backedge is encountered (Cycle is encountered)
				ans = min(ans, dis[nbr] + dis[cur] + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	//No of vertices and no of edges
	int n, m;
	cin >> n >> m;

	vector<int> graph[n + 1];
	while (m--) {
		int x, y;
		cin >> x >> y;
		//Bidirectional Edges
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	//Length of the smallest cycle.
	//Cycle of length (n+1) not possible
	int ans = n + 1;
	//nodes are from 1 to n
	// T.c -O(node*node)->as we are masking bfs call on every node
	for (int i = 1; i <= n; i++) {
		bfs(graph, i, n, ans);
	}

	if (ans == n + 1) {
		cout << "No Cycle" << endl;
	} else {
		cout << "shortest cycle is of length " << ans << endl;
	}

	return 0;
}