#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution {
public:
	int recur(string &s, string &t, int n, int m, int si1, int si2, vector<vector<int>> &dp) { //Function to find length of shortest common supersequence of two strings.
		if (si1 >= n) {
			return (m - si2);
		}

		if (si2 >= m) {
			return (n - si1);
		}

		if (dp[si1][si2] != -1) {
			return dp[si1][si2];
		}

		if (s[si1] == t[si2]) {
			return dp[si1][si2] = 1 + recur(s, t, n, m, si1 + 1, si2 + 1, dp);
		}

		return dp[si1][si2] = 1 + min({recur(s, t, n, m, si1 + 1, si2, dp), recur(s, t, n, m, si1, si2 + 1, dp)});
	}

	int shortestCommonSupersequence(string X, string Y, int m, int n) {

		vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

		return recur(X, Y, m, n, 0, 0, dp);



		// Bottom Up:-

// 		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

// 		for (int i = 0; i <= m ; i++) {
// 			dp[i][0] = i;
// 		}

// 		for (int i = 0; i <= n ; i++) {
// 			dp[0][i] = i;
// 		}

// 		for (int i = 1; i <= m; i++) {
// 			for (int j = 1; j <= n; j++) {
// 				if (X[i - 1] == Y[j - 1]) {
// 					dp[i][j] = (1 + dp[i - 1][j - 1]);
// 				} else {
// 					dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1]});
// 				}
// 			}
// 		}

// 		return dp[m][n];
	}
};
