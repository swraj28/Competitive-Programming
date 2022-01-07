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

// The worst case of this algorithm is equal to the O(nm) of the Bellman-Ford,
// but in practice it works much faster and some people claim that it works even in O(m) on average.

// However be careful, because this algorithm is deterministic and it is easy to create counterexamples that make the algorithm run in O(nm).

// Link:- 1.https://www.geeksforgeeks.org/shortest-path-faster-algorithm/
//		  2.https://cp-algorithms.com/graph/bellman_ford.html

const int INF = 1000000000;

vector<vector<pair<int, int>>> adj;

void addEdge(int frm, int to, int weight) {

	adj[frm].pb({ to, weight });
}

bool spfa(int s, vector<int>& d) {

	int n = adj.size();

	d.assign(n + 1, INF);

	vector<int> cnt(n + 1, 0);

	vector<bool> inqueue(n + 1, false);

	queue<int> q;

	d[s] = 0;
	q.push(s);
	inqueue[s] = true;

	while (!q.empty()) {

		int v = q.front();
		q.pop();
		inqueue[v] = false;

		for (auto edge : adj[v]) {

			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {

				d[to] = d[v] + len;

				if (!inqueue[to]) {

					q.push(to);
					inqueue[to] = true;
					cnt[to]++;

					if (cnt[to] > n) {
						return false;  // negative cycle
					}
				}
			}
		}
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int V = 5;
	int S = 1;

	adj.resize(V + 1);

	addEdge(1, 2, 1);
	addEdge(2, 3, 7);
	addEdge(2, 4, -2);
	addEdge(1, 3, 8);
	addEdge(1, 4, 9);
	addEdge(3, 4, 3);
	addEdge(2, 5, 3);
	addEdge(4, 5, -3);

	vector<int> d;

	bool ans = spfa(1, d);

	if (ans == false) {
		cout << "Negative Edge weight Cycle Is Present" << endl;
	}

	for (int i = 1; i <= V; i++) {
		cout << i << " " << d[i] << '\n';
	}

	return 0;
}