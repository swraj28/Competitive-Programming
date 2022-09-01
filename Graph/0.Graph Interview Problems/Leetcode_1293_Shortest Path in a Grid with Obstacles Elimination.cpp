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

// DFS --> Exploring All the Path and trying to find the minimum Path (TLE)

class Solution {
public:

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	int dp[41][41][1700];

	int dfs(int x, int y, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& visited, int k) {

		if ((x == n - 1) && (y == m - 1)) {
			return 0;
		}

		if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] == 1) {
			return (1e6);
		}

		if (grid[x][y] == 1 && k == 0) {
			return (1e6);
		}

		if (dp[x][y][k] != -1) {
			return dp[x][y][k];
		}

		if (grid[x][y] == 1) {
			k -= 1;
		}

		visited[x][y] = 1;

		int ans = INT_MAX;

		for (int i = 0; i < 4; i++) {

			int rec_res = 1 + dfs(x + dx[i], y + dy[i], n, m, grid, visited, k);

			ans = min(ans, rec_res);
		}



		/*
		I used dfs so even after visiting one there may be smallest way reach there so
		you have to unvisited that position after your work is done
		so that if we came here again from another way we should take this path to see if ot gives the minimum distance
		*/

		visited[x][y] = 0;

		return (dp[x][y][k] == -1) ? ans : min(ans, dp[x][y][k]);

		// return dp[x][y][k]=ans;
	}

	int shortestPath(vector<vector<int>>& grid, int k) {

		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));

		ms(dp, -1);

		int ans = dfs(0, 0, n, m, grid, visited, k);

		return (ans >= (1e6)) ? -1 : ans;
	}
};

// BFS:-

struct s {

	int x = 0, y = 0, len = 0, k_left = 0;
};

int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

class Solution {
public:
	int shortestPath(vector<vector<int>>& grid, int k) {

		int n = grid.size(), m = grid[0].size();

		vector<vector<int>> visited(n, vector<int>(m, 0));  // Wrong :- Handle Visited Bit Smartly (Approach is fine)

		queue<s> q;

		q.push({0, 0, 0, k});

		visited[0][0] = 1;

		while (!q.empty()) {

			auto node = q.front();
			q.pop();

			int x = node.x, y = node.y, len = node.len, k_left = node.k_left;

			if ((x == n - 1) && (y == m - 1)) {
				return len;
			}

			for (int i = 0; i < 4; i++) {
				int new_x = x + dx[i], new_y = y + dy[i];

				if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
					continue;
				}

				if (!visited[new_x][new_y]) {

					if (grid[new_x][new_y] == 1 && k_left == 0) {
						continue;
					}

					if (grid[new_x][new_y] == 0) {
						visited[new_x][new_y] = 1;

						q.push({new_x, new_y, len + 1, k_left});
					} else {
						visited[new_x][new_y] = 1;

						q.push({new_x, new_y, len + 1, k_left - 1});
					}
				}
			}
		}

		return -1;
	}
};