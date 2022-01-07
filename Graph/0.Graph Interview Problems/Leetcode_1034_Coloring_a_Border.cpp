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

	void dfs(vector<vector<int>>& grid, vector<vector<int>> &visited, int i, int j, int pre_x, int pre_y, int n, int m, int c1, int color) {

		if (i<0 or i >= n or j<0 or j >= m) {
			grid[pre_x][pre_y] = color;
			return;
		}

		if (visited[i][j]) {
			return;
		}

		if (grid[i][j] != c1) {
			grid[pre_x][pre_y] = color;
			return;
		}

		visited[i][j] = 1;

		for (int k = 0; k < 4; k++) {
			dfs(grid, visited, i + dx[k], j + dy[k], i, j, n, m, c1, color);
		}

	}

	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {

		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));

		dfs(grid, visited, row, col, -1, -1, n, m, grid[row][col], color);

		return grid;
	}
};