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

/*
            Key Observations:-

*/

class Solution {
public:

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	void dfs(int x, int y, int n, int m, vector<vector<int>>& grid) {

		if (x<0 or x >= n or y<0 or y >= m) {
			return;
		}

		if (grid[x][y] != 1) {
			return;
		}

		grid[x][y] += 1;

		for (int k = 0; k < 4; k++) {
			dfs(x + dx[k], y + dy[k], n, m, grid);
		}
	}

	int shortestBridge(vector<vector<int>>& grid) {

		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> res(n, vector<int>(m, 0));

		bool f1 = false;

		// DFS:- DFS is just performed to change the identification of all the nodes associated with any one of the island.
		//It becomes easy to segregate between nodes of two islands.

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					dfs(i, j, n, m, grid);
					f1 = true;
					break;
				}
			}
			if (f1) {
				break;
			}
		}

		vector<vector<int>> temp_grid = grid;

		queue<pair<int, int>> q;

		// Multisource BFS:-

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {  // Push any one of the island to queue and perform bfs simultaneously
					q.push({i, j});
				}
			}
		}

		while (!q.empty()) {

			auto s = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int x = s.ff + dx[k];
				int y = s.ss + dy[k];

				if (x<0 or x >= n or y<0 or y >= m) {
					continue;
				}

				if (temp_grid[x][y] == 2) {
					continue;
				}

				res[x][y] = (res[s.ff][s.ss] + 1);
				q.push({x, y});

				temp_grid[x][y] = 2;
			}
		}

		int ans = INT_MAX;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					ans = min(ans, res[i][j] - 1);
				}
			}
		}

		return ans;
	}
};