#include<bits/stdc++.h>
using namespace std;
#define ll long long

// By using Disjoint Set Union

// T.c->O(E)log(V) --> For justification see the notes

const int N = (1e5 + 5);

int parent[N], sz[N];

void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
}

int find_par(int v) {

	if (v == parent[v]) {
		return v;
	}

	return parent[v] = find_par(parent[v]);
}

void union_sets(int a, int b) {

	a = find_par(a);
	b = find_par(b);

	if (a == b) {
		return ;
	}

	if (a != b) {
		if (sz[a] >= sz[b]) {
			parent[b] = a;
			sz[a] += sz[b];
		} else {
			parent[a] = b;
			sz[b] += sz[a];
		}
	}
}

struct Edge {
	int u, v, weight;

	// Overloading the < operator

	bool operator<(Edge const& other) {
		return weight < other.weight;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;  // n-->no. of vertices and m--> no. of edges

	vector<Edge> edges;

	for (int i = 0; i < m; i++) {  // o(m)
		int a, b, w;
		cin >> a >> b >> w;

		edges.push_back({a, b, w});
	}

	sort(edges.begin(), edges.end()); // o(mlog(m))

	// for (int i = 0; i < m; i++) {
	// 	cout << edges[i].u << " " << edges[i].v << " " << edges[i].weight << endl;
	// }

	int mn_cost = 0;

	vector<Edge> result;

	for (int i = 0; i < n; i++) { // o(n)
		make_set(i);
	}

	for (Edge e : edges) {  // o(m)
		if (find_par(e.u) != find_par(e.v)) {
			mn_cost += e.weight;
			result.push_back(e);
			union_sets(e.u, e.v);
		}
	}

	cout << "The Minimum Cost is:" << mn_cost << endl;
	cout << endl;

	cout << "The required Minimum Cost Spanning Tree is:-" << endl;

	for (auto edge : result) {
		cout << edge.u << " " << edge.v << " " << edge.weight << endl;
	}


	return 0;
}


/*
7 9
0 1 12
1 2 13
0 3 18
0 4 2
1 4 9
2 5 3
3 4 22
3 6 100
4 6 15
*/