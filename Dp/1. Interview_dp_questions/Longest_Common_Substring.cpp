#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    int ans;

    int recur(string &a, string &b, int n, int m, int si1, int si2, vector<vector<int>> &dp) { // This function will return the length of lcsubstring
        if (si1 >= n or si2 >= m) {
            return 0;
        }

        if (dp[si1][si2] != -1) {
            return dp[si1][si2];
        }

        recur(a, b, n, m, si1 + 1, si2, dp);   // iterate over all (n*m) states
        recur(a, b, n, m, si1, si2 + 1, dp);

        if (a[si1] == b[si2]) {
            dp[si1][si2] = 1 + recur(a, b, n, m, si1 + 1, si2 + 1, dp);
            ans = max(ans, dp[si1][si2]);
            return dp[si1][si2];
        }

        return dp[si1][si2] = 0;
    }

    int longestCommonSubstr (string S1, string S2, int n, int m) {

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        ans = 0;

        int ending_idx = n;

        // recur(S1, S2, n, m, 0, 0, dp);

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (S1[i - 1] == S2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > ans) {
                        ans = dp[i][j];
                        ending_idx = i;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        //  cout << S1.substr(ending_idx - ans, ans) << endl;  // printing the longest common substring using dp

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}