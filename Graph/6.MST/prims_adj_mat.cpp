#include<bits/stdc++.h>
using namespace std;
#define ll long long

// t.c:- O(V^2)

int minEdgeVertex(vector<int> &weight, vector<bool> &growingSet) {
	int min_idx = -1, mn = INT_MAX;

	for (int i = 0; i < weight.size(); i++) {
		if (growingSet[i] == false and weight[i] < mn) {
			mn = weight[i];
			min_idx = i;
		}
	}

	return min_idx;
}

void updateWeight(vector<int> &weight, vector<bool> &growingSet, vector<vector<int>>&adj, int v) {
	int n = weight.size();

	for (int i = 0; i < n; i++) {
		if (adj[i][v] != 0 and growingSet[i] == false) {
			weight[i] = min(weight[i], adj[i][v]);
		}
	}
}

int mst(vector<vector<int>> &adj) {

	int n = adj.size();

	int cost = 0;
	vector<bool> growingSet(n, false);
	vector<int> weight(n, INT_MAX);

	weight[0] = 0;

	for (int i = 0; i < n; i++) {
		int v = minEdgeVertex(weight, growingSet); //vertex opposite to minimum edge.

		cost += weight[v];
		growingSet[v] = true;
		weight[v] = 0;

		updateWeight(weight, growingSet, adj, v);
	}

	return cost;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> adj = {{0, 12, 0, 18, 2, 0, 0},
		{12, 0, 13, 0, 9, 0, 0},
		{0, 13, 0, 0, 0, 3, 0},
		{18, 0, 0, 0, 22, 0, 100},
		{2, 9, 0, 22, 0, 0, 15},
		{0, 0, 3, 0, 0, 0, 0},
		{0, 0, 0, 100, 15, 0, 0}
	};

	cout << mst(adj) << endl;

	return 0;
}