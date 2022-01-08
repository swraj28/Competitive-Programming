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

// 1. Recursion + Backtracking (Brute Force Solution)---> Time Complexity --> Exponential

class Solution {
public:

	int mx = 0;

	void helper(vector<vector<int>> &grid, int x, int y, int n, int cnt) {

		if (x<0 or x >= n or y<0 or y >= n or grid[x][y] == -1) {
			return;
		}

		if (x == 0 and y == 0) {
			mx = max(mx, cnt);
			return;
		}

		int cherry = grid[x][y];
		grid[x][y] = 0;

		helper(grid, x - 1, y, n, cnt + cherry);
		helper(grid, x, y - 1, n, cnt + cherry);

		grid[x][y] = cherry;  // Backtracking
	}

	void dfs(vector<vector<int>> &grid, int x, int y, int n, int cnt) {

		if (x<0 or x >= n or y<0 or y >= n or grid[x][y] == -1) {
			return;
		}

		if (x == (n - 1) and y == (n - 1)) {
			helper(grid, n - 1, n - 1, n, cnt);
			return;
		}

		int cherry = grid[x][y];
		grid[x][y] = 0;

		dfs(grid, x + 1, y, n, cnt + cherry);
		dfs(grid, x, y + 1, n, cnt + cherry);

		grid[x][y] = cherry;  // Backtracking
	}

	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();

		if (n == 1) {
			return grid[0][0];
		}

		dfs(grid, 0, 0, n, 0);

		return mx;
	}
};

// Recursion + Memoization

class Solution {
public:

	int dp[60][60][60][60];

	int recur(vector<vector<int>>& grid, int n, int r1, int c1, int r2, int c2) {  // This Function will return the max value.

		if ((r1<0 or r1 >= n or c1<0 or c1 >= n) or (r2<0 or r2 >= n or c2<0 or c2 >= n) or grid[r1][c1] == -1 or grid[r2][c2] == -1) {
			return INT_MIN;
		}

		if ((r1 == (n - 1) and c1 == (n - 1)) or (r2 == (n - 1) and c2 == (n - 1))) {
			return grid[n - 1][n - 1];
		}

		if (dp[r1][c1][r2][c2] != -1) {
			return dp[r1][c1][r2][c2];
		}

		int val = 0;

		if ((r1 == r2) and (c1 == c2)) {
			val += grid[r1][c1];
		} else {
			val = (grid[r1][c1] + grid[r2][c2]);
		}

		int a = recur(grid, n, r1, c1 + 1, r2, c2 + 1);
		int b = recur(grid, n, r1 + 1, c1, r2 + 1, c2);

		int c = recur(grid, n, r1 + 1, c1, r2, c2 + 1);
		int d = recur(grid, n, r1, c1 + 1, r2 + 1, c2);

		val += max({a, b, c, d});

		return dp[r1][c1][r2][c2] = val;
	}

	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();

		if (n == 1) {
			return grid[0][0];
		}

		memset(dp, -1, sizeof(dp));

		int val = recur(grid, n, 0, 0, 0, 0);

		if (val < 0) {
			return 0;
		}
		return val;
	}
};