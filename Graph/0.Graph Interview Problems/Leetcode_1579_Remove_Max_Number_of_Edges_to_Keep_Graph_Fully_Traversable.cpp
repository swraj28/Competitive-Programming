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

	int find_parent(int v, vector<int> &parent) {
		if (v == parent[v]) {
			return v;
		}

		return parent[v] = find_parent(parent[v], parent);
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

		int m = edges.size();

		// All the edges have been sorted in descending of colors. (give preference to bidirectional Edges).

		sort(edges.begin(), edges.end(), [] (vector<int> &a, vector<int> &b) { return a[0] > b[0];});

		// Our Aim is to connect the graph using bidirectional edges as much as possible.

		vector<int> p_a(n + 1, 0);
		vector<int> p_b(n + 1, 0);

		vector<int> sze_a(n + 1, 0);
		vector<int> sze_b(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			p_a[i] = i;
			p_b[i] = i;
			sze_a[i] = 1;
			sze_b[i] = 1;
		}

		int total_a = n, total_b = n;

		int removed = 0;

		for (int i = 0; i < m; i++) {
			int c = edges[i][0];
			int a = edges[i][1];
			int b = edges[i][2];

			if (c == 3) {

				int x = a, y = b;
				x = find_parent(x, p_a);
				y = find_parent(y, p_a);

				if (x != y) {
					total_a -= 1;

					if (sze_a[x] >= sze_a[y]) {
						p_a[y] = x;
						sze_a[x] += sze_a[y];
					} else {
						p_a[x] = y;
						sze_a[y] += sze_a[x];
					}
				} else {
					removed++;
				}

				x = a, y = b;

				x = find_parent(x, p_b);
				y = find_parent(y, p_b);

				if (x != y) {
					total_b -= 1;

					if (sze_b[x] >= sze_b[y]) {
						p_b[y] = x;
						sze_b[x] += sze_b[y];
					} else {
						p_b[x] = y;
						sze_b[y] += sze_b[x];
					}
				}
			} else if (c == 2) {
				int x = a, y = b;
				x = find_parent(x, p_b);
				y = find_parent(y, p_b);

				if (x != y) {
					total_b -= 1;

					if (sze_b[x] >= sze_b[y]) {
						p_b[y] = x;
						sze_b[x] += sze_b[y];
					} else {
						p_b[x] = y;
						sze_b[y] += sze_b[x];
					}
				} else {
					removed++;
				}
			} else {
				int x = a, y = b;
				x = find_parent(x, p_a);
				y = find_parent(y, p_a);

				if (x != y) {
					total_a -= 1;

					if (sze_a[x] >= sze_a[y]) {
						p_a[y] = x;
						sze_a[x] += sze_a[y];
					} else {
						p_a[x] = y;
						sze_a[y] += sze_a[x];
					}
				} else {
					removed++;
				}
			}
		}

		if (total_a > 1 or total_b > 1) {
			return -1;
		}

		return removed;
	}
};