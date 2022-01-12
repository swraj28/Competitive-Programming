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

const int INF = 1000000000;

class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

		vector<pair<int, int>> adj[n];

		for (auto p : flights) {
			adj[p[0]].pb({p[1], p[2]});
		}

		vector<int> dis(n, INF);

		dis[src] = 0;

		set <pair<int, pair<int, int>>> s;

		s.insert({0, {0, src}});

		while (!s.empty()) {

			auto p = *(s.begin());

			s.erase(s.begin());

			int v = p.ss.ss;

			int st = p.ff;

			int d = p.ss.ff;

			for (auto nbr : adj[v]) {

				int to = nbr.first;
				int len = nbr.second;

				if ((st <= k) and (d + len < dis[to])) {

					dis[to] = (d + len);

					s.insert({(st + 1), {dis[to], to}});
				}
			}
		}

		if (dis[dst] == INF) {
			return -1;
		}

		return dis[dst];
	}
};