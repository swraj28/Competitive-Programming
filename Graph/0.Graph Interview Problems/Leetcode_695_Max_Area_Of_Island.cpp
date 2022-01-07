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

	vector<int> dx{ -1, 0, 1, 0};
	vector<int> dy{0, -1, 0, 1};

	void dfs(int i, int j, int n, int m, vector<vector<int>>& grid, int &cnt) {
		// Matrix Boundary Condition
		if (i<0 or j<0 or i >= n or j >= m) {
			return;
		}

		if (grid[i][j] == 0) {
			return;
		}

		grid[i][j] = 0;

		cnt += 1;

		for (int k = 0; k < 4; k++) {
			dfs(i + dx[k], j + dy[k], n, m, grid, cnt);
		}
	}

	int maxAreaOfIsland(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		// O in the grid states the visited cell and 1 in the grid states unvisited cell

		int mx = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					int cnt = 0;
					dfs(i, j, n, m, grid, cnt);

					mx = max(mx, cnt);
				}
			}
		}

		return mx;
	}
};