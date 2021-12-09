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

	void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>> &visited) {

		if (x<0 or x >= n or y<0 or y >= m) {
			return;
		}

		if (grid[x][y] == '0') {
			return;
		}

		if (visited[x][y]) {
			return;
		}

		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			dfs(x + dx[i], y + dy[i], n, m, grid, visited);
		}

	}

	int numIslands(vector<vector<char>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));

		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] and grid[i][j] == '1') {
					dfs(i, j, n, m, grid, visited);
					cnt++;
				}
			}
		}

		return cnt;
	}
};
