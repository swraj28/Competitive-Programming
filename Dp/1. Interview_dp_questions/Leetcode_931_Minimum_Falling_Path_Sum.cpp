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

class Solution {
public:

	int dp[105][105];

	int recur(vector<vector<int>>& matrix, int n, int m, int i, int j) { // This function will min cost from a particular index(i,j) of first row
		if (i >= n) {
			return 0;
		}

		if (j<0 or j >= m) {
			return 0;
		}

		if (dp[i][j] != -1) {
			return dp[i][j];
		}

		int v1 = INT_MAX, v2 = INT_MAX, v3 = INT_MAX;

		if ((j - 1) >= 0) {
			v1 = matrix[i][j] + recur(matrix, n, m, i + 1, j - 1);
		}

		if (j >= 0 and j < m) {
			v2 = matrix[i][j] + recur(matrix, n, m, i + 1, j);
		}

		if ((j + 1) < m) {
			v3 = matrix[i][j] + recur(matrix, n, m, i + 1, j + 1);
		}

		return dp[i][j] = min({v1, v2, v3});
	}

	int minFallingPathSum(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int m = matrix[0].size();

		int ans = INT_MAX;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < m; i++) {
			ans = min(ans, recur(matrix, n, m, 0, i));
		}

		return ans;

	}
};