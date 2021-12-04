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
// 	int dp[1005][1005];

// 	int recur(string &a, string &b, int n, int m, int si1, int si2) { // This function will return the length of lcs

// 		if (si1 >= n or si2 >= m) {
// 			return 0;
// 		}

// 		if (dp[si1][si2] != 0) {
// 			return dp[si1][si2];
// 		}

// 		if (a[si1] == b[si2]) {
// 			return dp[si1][si2] = 1 + recur(a, b, n, m, si1 + 1, si2 + 1);
// 		}

// 		return dp[si1][si2] = max({recur(a, b, n, m, si1 + 1, si2), recur(a, b, n, m, si1, si2 + 1)});
// 	}

	int longestCommonSubsequence(string text1, string text2) {

		int x = text1.length();
		int y = text2.length();

		// ms(dp, 0);

		// int ans=recur(text1, text2, n, m, 0, 0);

		vector<vector<int>>dp(x + 1, vector<int>(y + 1, 0));

		for (int i = 1; i <= x; i++) {
			for (int j = 1; j <= y; j++) {
				if (text1[i - 1] == text2[j - 1]) {
					dp[i][j] = (dp[i - 1][j - 1] + 1);
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		// for (int i = 0; i < x + 1; i++) {
		// 	for (int j = 0; j < y + 1; j++) {
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		// return ans;

		return dp[x][y];
	}
};