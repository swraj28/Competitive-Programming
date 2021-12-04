#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recur(string &a, string &b, int n, int m, int si1, int si2, vector<vector<int>> &dp) { // This function will return the length of lcs
        if (si1 >= n or si2 >= m) {
            return 0;
        }

        if (dp[si1][si2] != -1) {
            return dp[si1][si2];
        }

        if ((si1 != si2) and a[si1] == b[si2]) {
            return dp[si1][si2] = 1 + recur(a, b, n, m, si1 + 1, si2 + 1, dp);
        }

        return dp[si1][si2] = max({recur(a, b, n, m, si1 + 1, si2, dp), recur(a, b, n, m, si1, si2 + 1, dp)});
    }

    int LongestRepeatingSubsequence(string str) {

        int n = str.length();
        string t = str;

        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

        return recur(str, t, n, n, 0, 0, dp);
    }
};