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
	int minCostConnectPoints(vector<vector<int>>& points) {

		int n = points.size();

		set<pair<int, int>> unvis, vis;

		for (int i = 0; i < n; i++) {
			int x = points[i][0], y = points[i][1];
			unvis.insert({x, y});
		}

		// Prims algorithm

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;

		int ans = 0;

		pair<int, int> st = {points[0][0], points[0][1]};

		q.push({0, st});

		while ((!q.empty()) and (vis.size() < n)) {

			auto best = q.top();
			q.pop();

			int weight = best.ff;
			auto to = best.ss;

			if (vis.find(to) != vis.end()) {
				continue;
			}

			ans += weight;
			vis.insert(to);
			unvis.erase(to);

			for (auto nbr : unvis) {
				int d = abs(nbr.ff - to.ff) + abs(nbr.ss - to.ss);
				q.push({d, nbr});
			}
		}

		return ans;
	}
};

//Kruskals Algo

class Solution {
public:

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	void Union(int a, int b, vector<int> &parent, vector<int> &sze) {

		a = find_parent(a, parent);
		b = find_parent(b, parent);

		if (a == b) {
			return;
		}

		if (sze[a] >= sze[b]) {
			parent[b] = a;
			sze[a] += sze[b];
		} else {
			parent[a] = b;
			sze[b] += sze[a];
		}
	}

	int minCostConnectPoints(vector<vector<int>>& points) {

		int n = points.size();

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > q;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {

				int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);

				q.push({d, {i, j}});
			}
		}

		vector<int> parent(n);
		vector<int> sze(n);

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			sze[i] = 1;
		}

		int ans = 0;

		int cnt = 0;

		// We cannot set iterators on the priority queue.

		while (!q.empty()) {

			if (cnt == (n - 1)) {
				break;
			}

			auto node = q.top();
			q.pop();

			int weight = node.ff;
			auto to = node.ss;

			if ((find_parent(to.ff, parent)) != (find_parent(to.ss, parent))) {
				cnt++;
				ans += weight;

				Union(to.ff, to.ss, parent, sze);
			}
		}

		return ans;
	}
};