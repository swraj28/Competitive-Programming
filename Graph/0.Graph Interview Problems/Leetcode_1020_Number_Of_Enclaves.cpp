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
	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	void dfs(int i, int j, int n, int m, vector<vector<int>> &grid) {

		if (i<0 or i >= n or j<0 or j >= m) {
			return;
		}

		if (grid[i][j] == 0) {
			return;
		}

		grid[i][j] = 0;

		for (int k = 0; k < 4; k++) {
			dfs(i + dx[k], j + dy[k], n, m, grid);
		}
	}


	int numEnclaves(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		if (n == 1 and m == 1) {
			if (grid[0][0] == 0) {
				return 1;
			}
			return 0;
		}

		for (int j = 0; j < m; j++) {
			if (grid[0][j]) {
				dfs(0, j, n, m, grid);
			}
		}

		for (int j = 0; j < m; j++) {
			if (grid[n - 1][j]) {
				dfs(n - 1, j, n, m, grid);
			}
		}

		for (int i = 0; i < n; i++) {
			if (grid[i][0]) {
				dfs(i, 0, n, m, grid);
			}
		}

		for (int i = 0; i < n; i++) {
			if (grid[i][m - 1]) {
				dfs(i, m - 1, n, m, grid);
			}
		}

		int cnt = 0;

		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				if (grid[i][j] ) {
					cnt++;
				}
			}
		}

		return cnt;
	}
};