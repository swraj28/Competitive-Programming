#include<bits/stdc++.h>
using namespace std;
#define ll long long

//	Suppose we are given requests to add an edge and we have to answer after
//	which edge the graph stops being bipartite.

//	A graph is bipartite,if its vertices can be split into two sets,named parts,such that there does not exist an edge inside a part.

//	Two vertices belong to the same part/set if length of any path between them will be of even length.

const int nax = 2e5 + 10;

int sz[nax];

int parent[nax];

bool bipartite[nax]; //If a particualr node returns false then adding that node to the graph stops the grpah from being bipartite.

int len[nax];  // Parity to the leader


void make_set(int v) {
	parent[v] = v;
	sz[v] = 1;
	bipartite[v] = true;
	len[v] = 0;
}

pair<int, int> find_par(int v) {

	if (v == parent[v]) {
		return {v, 0};
	}

	//It recursively calculates the leader of the group and the parity of parent of 'v' with the leader of the group.

	pair<int, int> val = find_par(parent[v]);

	parent[v] = val.first; //leader

	len[v] = (len[v] + val.second) % 2;

	return {parent[v], len[v]};
}

void union_set(int a, int b) {

	pair<int, int> pa = find_par(a);
	a = pa.first;
	int x = pa.second;

	pair<int, int> pb = find_par(b);
	b = pb.first;
	int y = pb.second;

	if (a == b) { //Condition of cycle
		if (x == y) { // Odd length cycle
			bipartite[a] = false;
		}
	} else {
		if (sz[a] >= sz[b]) {
			parent[b] = a;
			len[b] = (x + y + 1) % 2;
			bipartite[a] &= bipartite[b];
		} else {
			parent[a] = b;
			len[a] = (x + y + 1) % 2;
			bipartite[b] &= bipartite[a];
		}
	}
}

bool is_bipartite(int v) {
	return bipartite[find_par(v).first];
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		make_set(i);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		union_set(a, b);
	}

	for (int i = 1; i <= n; i++) {
		cout << bipartite[i] << " ";
	}
	cout << endl;


	return 0;
}