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

	// Top down:-

	int dp[1005][1005];
	int recur(string &s, int st, int end) {  // This Function will return the longest pailendromic subsequence.
		if (st == end) {
			return 1;
		}

		if (st == (end - 1)) {
			if (s[st] == s[end]) {
				return 2;
			}
			return 1;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		if (s[st] == s[end]) {
			return dp[st][end] = 2 + recur(s, st + 1, end - 1);
		}

		return dp[st][end] = max({recur(s, st + 1, end), recur(s, st, end - 1)});
	}


	//Bottom Up:-
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

		//Printing The Longest Pailendromic subsequence

		int x = n, y = n;
		string ans = "";

		while (x > 0 and y > 0) {

			if (s[x - 1] == t[y - 1]) {
				ans += s[x - 1];
				x--, y--;
			} else if (dp[x - 1][y] >= dp[x][y - 1]) {
				x--;
			} else {
				y--;
			}
		}

		reverse(all(ans));

		cout << ans << endl;

		return dp[n][n];
	}
};