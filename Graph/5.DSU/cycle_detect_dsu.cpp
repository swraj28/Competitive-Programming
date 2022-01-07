#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair

const int nax = 1e5 + 10;
int par[nax] , sz[nax];

int find_par(int v) { //Find the leader of the group using path compression
	if ( v == par[v] ) return v;
	return par[v] = find_par(par[v]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) { //Initially all the nodes in a graph are acting as a dijoint set in itself.
		par[i] = i;
		sz[i] = 1;
	}

	// The Graph Will represented in the form of Edge List
	vector<pair<int, int>> gr;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		//There is an edge between x and y in the graph.
		gr.pb({x, y});
	}

	for (int i = 0; i < m; i++) {
		int a = gr[i].first;
		int b = gr[i].second;

		a = find_par(a);
		b = find_par(b);

		//	If the parent of both 'a' and 'b' are same.It means that they belong to the same group/set.
		//	Adding an edge between the element of same set will create a cycle.

		if (a == b) { //Cycle Found
			cout << "Cycle Is Present" << endl;
			return 0;
		}

		//Union->
		if (a != b) {
			if (sz[a] >= sz[b]) {
				par[b] = a;
				sz[a] += sz[b];
			} else {
				par[a] = b;
				sz[b] += sz[a];
			}
		}
	}

	cout << "No Cycle Is Present" << endl;

	return 0;
}