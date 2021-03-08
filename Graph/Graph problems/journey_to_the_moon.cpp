// Connected Components:-
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Graph {

	map<int, list<int>> adj;
public:

	void add_edges(int src, int dest, bool bidir = true) {
		adj[src].push_back(dest);
		if (bidir) {
			adj[dest].push_back(src);
		}
	}

	//This dfs function counts the size of each components
	void dfs(int src, bool visited[], int &cnt) {
		visited[src] = true;
		cnt++;

		for (auto i : adj[src]) {
			if (visited[i] == false) {
				dfs(i, visited, cnt);
			}
		}
	}

	void journey_to_the_moon(int n) {
		bool*visited = new bool[n];
		for (int i = 0; i < n; i++) {
			visited[i] = false;
		}
		//Out of n choices we need to select 2 choices (nc2)
		ll total = ((ll)n * (n - 1)) / 2;

		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				int cnt = 0;
				dfs(i, visited, cnt);
				ll temp = ((ll)cnt * (cnt - 1)) / 2;
				total -= temp;
			}
		}
		cout << total << endl;
	}
};

int main() {

	int n, p;
	cin >> n >> p;
	Graph g;
	while (p--) {
		int a, b;
		cin >> a >> b;
		g.add_edges(a, b);
	}

	g.journey_to_the_moon(n);


	return 0;
}