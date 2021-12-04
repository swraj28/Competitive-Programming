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

	int longestPalindromeSubseq(string s) {

		// Longest_Pailen_subseq(s)=Longest_increasing_subseq(s,reverse(s));

		int n = s.length();

		string t = "";

		for (int i = n - 1; i >= 0; i--) {
			t += s[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = (dp[i - 1][j - 1] + 1);
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}

		return dp[n][n];
	}

	int minInsertions(string s) {

		int n = s.length();

		return (n - longestPalindromeSubseq(s));
	}
};