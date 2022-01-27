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

	int dp[205][205];

	int recur(vector<vector<int>>& grid, int n, int si, int prev) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][prev] != -1) {
			return dp[si][prev];
		}

		int ans = INT_MAX;

		for (int i = 0; i < n; i++) {
			if (i == prev) {
				continue;
			}

			int rec_res = grid[si][i] + recur(grid, n, si + 1, i);

			ans = min(ans, rec_res);
		}

		return dp[si][prev] = ans;
	}

	int minFallingPathSum(vector<vector<int>>& grid) {

		int n = grid.size();

		ms(dp, -1);

		int ans = INT_MAX;

		for (int i = 0; i < n; i++) {
			ans = min({ans, grid[0][i] + recur(grid, n, 1, i)});
		}

		return ans;
	}
};