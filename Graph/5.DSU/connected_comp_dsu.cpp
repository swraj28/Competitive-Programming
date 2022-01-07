#include<bits/stdc++.h>
using namespace std;

#define pb push_back

#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;

const int nax = 1e5 + 10;
int par[nax] , sz[nax];

int fp(int v) { //Find the leader of the group using path compression
	if ( v == par[v] ) return v;
	return par[v] = fp(par[v]);
}

//The Graph will be represented in the form of edge list

int main() {
	fast;
	int n , m;
	cin >> n >> m;

	for (int i = 1 ; i <= n ; i++ ) {
		par[i] = i;
		sz[i] = 1;
	}

	int mx_sz = 1; //max_size of the component initially.

	int grp_cnt = n; //Intially all the nodes are attached to themsleves.Therefore there will be n connected component

	for (int i = 1 ; i <= m ; i++ ) {

		int u , v;
		cin >> u >> v;

		// Union Find Operation:-
		int pu = fp(u);
		int pv = fp(v);

		if (pu != pv) { //Both Have Different Parent Therefore They can be joined to make one set.
			grp_cnt--;
			if (sz[pu] >= sz[pv]) {
				par[pv] = pu;
				sz[pu] += sz[pv];
				mx_sz = max(mx_sz, sz[pu]);
			} else {
				par[pu] = pv;
				sz[pv] += sz[pu];
				mx_sz = max(mx_sz, sz[pv]);
			}
		}
	}

	cout << grp_cnt << " " << mx_sz << "\n";

	return 0;
}