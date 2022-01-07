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

class Solution {
public:
	bool validPath(int n, vector<vector<int>>& edges, int start, int end) {

		if (start == end) {
			return true;
		}

		vector<int> gr[n];

		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];

			gr[u].pb(v);
			gr[v].pb(u);
		}

		vector<int> visited(n, 0);

		stack<int> q;
		q.push(start);

		visited[start] = 1;

		while (!q.empty()) {

			int node = q.top();
			q.pop();

			for (auto nbr : gr[node]) {
				if (!visited[nbr]) {

					if (nbr == end) {
						return true;
					}

					visited[nbr] = 1;
					q.push(nbr);
				}
			}
		}

		return false;
	}
};