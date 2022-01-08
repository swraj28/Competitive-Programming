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

	int dp[80][80][80];

	int recur(vector<vector<int>>& grid, int n, int m, int r1, int c1, int c2) { // This Function will return the max value.

		if ((r1<0 or r1 >= n or c1<0 or c1 >= m) or (c2<0 or c2 >= m)) {
			return INT_MIN;
		}

		if (r1 == (n - 1)) {
			if ((c1 == c2)) {
				return grid[r1][c1];
			} else {
				return (grid[r1][c1] + grid[r1][c2]);
			}
		}


		if (dp[r1][c1][c2] != -1) {
			return dp[r1][c1][c2];
		}

		int val = 0;

		if ((c1 == c2)) {
			val += grid[r1][c1];
		} else {
			val = (grid[r1][c1] + grid[r1][c2]);
		}

		int a = recur(grid, n, m, r1 + 1, c1 - 1, c2 - 1);
		int b =  recur(grid, n, m, r1 + 1, c1 - 1, c2);
		int c =  recur(grid, n, m, r1 + 1, c1 - 1, c2 + 1);

		int d = recur(grid, n, m, r1 + 1, c1, c2 - 1);
		int e = recur(grid, n, m, r1 + 1, c1,  c2);
		int f = recur(grid, n, m, r1 + 1, c1,  c2 + 1);

		int g = recur(grid, n, m, r1 + 1, c1 + 1,  c2 - 1);
		int h = recur(grid, n, m, r1 + 1, c1 + 1,  c2);
		int i = recur(grid, n, m, r1 + 1, c1 + 1, c2 + 1);

		val += max({a, b, c, d, e, f, g, h, i});

		return dp[r1][c1][c2] = val;
	}



	int cherryPickup(vector<vector<int>>& grid) {

		int n = grid.size();
		int m = grid[0].size();

		memset(dp, -1, sizeof(dp));

		return recur(grid, n, m, 0, 0, m - 1);
	}
};