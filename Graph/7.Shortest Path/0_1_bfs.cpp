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

// Tutorial:- https://codeforces.com/blog/entry/22276

const int INF = 1000000000;

vector<vector<pair<int, int>>> adj;

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

	int s = 0;

	vector<int> d(n, INF);
	d[s] = 0;

	deque<int> q;
	q.push_front(s);

	while (!q.empty()) {

		int v = q.front();
		q.pop_front();

		for (auto edge : adj[v]) {

			int u = edge.first;
			int w = edge.second;

			if (d[v] + w < d[u]) {

				d[u] = d[v] + w;

				if (w == 1) {
					q.push_back(u);
				} else {
					q.push_front(u);
				}
			}
		}
	}


	return 0;
}