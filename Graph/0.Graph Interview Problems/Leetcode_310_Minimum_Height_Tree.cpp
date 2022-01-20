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


// 1. Brute Force :- o(V^2)--> V is the number of nodes.

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

		vector<int> adj[n];

		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0], y = edges[i][1];
			adj[x].pb(y);
			adj[y].pb(x);
		}

		map<int, int> m;

		int mn_level = INT_MAX;

		for (int i = 0; i < n; i++) {

			queue<int> q;
			vector<int> visited(n, 0);

			q.push(i);
			visited[i] = 1;

			int level = 0;

			while (true) {

				int s = q.size();

				if (s == 0) {
					break;
				}

				level++;

				while (s--) {
					int node = q.front();
					q.pop();

					for (auto nbr : adj[node]) {
						if (!visited[nbr]) {
							visited[nbr] = 1;
							q.push(nbr);
						}
					}
				}
			}

			m[i] = level;
			mn_level = min(mn_level, level);
		}

		vector<int> v;

		for (auto i : m) {
			if (i.ss == mn_level) {
				v.pb(i.ff);
			}
		}

		return v;
	}
};

// Optimized:- Put all the leaf nodes in the queue and perform bfs simultaneously.

//  One more observation that we need to keep in mind that since we operating on a tree,therefore the number of  nodes from which we will get the max.
//  height is going to be either 1 or 2.

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

		vector<int> ans;

		if (n <= 2) {
			for (int i = 0; i < n; i++) {
				ans.pb(i);
			}

			return ans;
		}

		vector<int> adj[n];

		for (int i = 0; i < edges.size(); i++) {
			int x = edges[i][0], y = edges[i][1];
			adj[x].pb(y);
			adj[y].pb(x);
		}

		vector<int> indegree(n, 0);

		for (int i = 0; i < n; i++) {

			for (auto nbr : adj[i]) {
				indegree[nbr]++;
			}
		}

		queue<int> q;

		vector<int> visited(n, 0);

		for (int i = 0; i < n; i++) {
			if (adj[i].size() == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}

		int cnt = n;

		while (cnt > 2) {

			int sze = q.size();

			while (sze--) {

				int f = q.front();
				q.pop();

				indegree[f] -= 1;

				cnt -= 1;

				for (auto nbr : adj[f]) {
					if (!visited[nbr]) {
						indegree[nbr] -= 1;

						if (indegree[nbr] == 1) {
							visited[nbr] = 1;
							q.push(nbr);
						}
					}
				}
			}
		}

		vector<int> res;

		for (int i = 0; i < n; i++) {
			if (indegree[i] == 1) {
				res.pb(i);
			}
		}

		return res;
	}
};