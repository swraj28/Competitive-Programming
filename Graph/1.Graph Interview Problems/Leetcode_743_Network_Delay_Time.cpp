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
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		if (n == 1) {
			return 0;
		}

		vector<vector<pair<int, int>>> adj;

		adj.resize(n + 1);

		//vector<vector<pair<int, int>>> adj((n+1), vector<pair<int, int>>());

		int m = times.size();

		for (int i = 0; i < m; i++) {
			int x = times[i][0];
			int y = times[i][1];
			int w = times[i][2];

			adj[x].pb({y, w});
		}

		vector<int> d((n + 1), INT_MAX);

		vector<int> p((n + 1), -1);

		int src = k;

		d[src] = 0;

		set<pair<int, int>> s;

		s.insert({0, src});

		while (!s.empty()) {

			int v = s.begin()->ss;

			s.erase(s.begin());

			for (auto nbr : adj[v]) {

				int to = nbr.ff;
				int len = nbr.ss;

				if (d[v] + len < d[to]) {

					auto itr = s.find({d[to], to});

					if (itr != s.end()) {
						s.erase(itr);
					}

					d[to] = (d[v] + len);
					p[to] = v;
					s.insert({d[to], to});
				}
			}
		}

		int ans = 0;

		for (int i = 1; i <= n; i++) {
			ans = max(ans, d[i]);
		}

		if (ans == INT_MAX) {
			return -1;
		}

		return ans;
	}
};