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
	string shortestCommonSupersequence(string str1, string str2) {

		int n = str1.length();
		int m = str2.length();

		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 0; i <= n ; i++) {
			dp[i][0] = i;
		}

		for (int i = 0; i <= m ; i++) {
			dp[0][i] = i;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (str1[i - 1] == str2[j - 1]) {
					dp[i][j] = (1 + dp[i - 1][j - 1]);
				} else {
					dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1]});
				}
			}
		}

		// for (int i = 0; i <= n; i++) {
		// 	for (int j = 0; j <= m; j++) {
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		string ans = "";

		int x = n, y = m;

		while (x > 0 and y > 0) {

			if (str1[x - 1] == str2[y - 1]) {
				ans += str1[x - 1];
				x--, y--;
			} else if (dp[x - 1][y] <= dp[x][y - 1]) {
				ans += str1[x - 1];
				x--;
			} else {
				ans += str2[y - 1];
				y--;
			}
		}

		while (x > 0) {
			ans += str1[x - 1];
			x--;
		}

		while (y > 0) {
			ans += str2[y - 1];
			y--;
		}

		reverse(all(ans));

		return ans;
	}
};