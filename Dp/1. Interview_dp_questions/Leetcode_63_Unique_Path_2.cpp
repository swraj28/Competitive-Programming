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

// 1. Top down DP:-

class Solution {
public:

    int dp[105][105];

    int recur(int x, int y, int n, int m, vector<vector<int>>& obstacleGrid) {

        if (x<0 or x >= n or y<0 or y >= m) {
            return 0;
        }

        if (dp[x][y] != -1) {
            return dp[x][y];
        }

        if (obstacleGrid[x][y] == 1) {
            return 0;
        }

        if (x == (n - 1) and y == (m - 1)) {
            return 1;
        }

        int cnt = recur(x + 1, y, n, m, obstacleGrid) + recur(x, y + 1, n, m, obstacleGrid);

        return dp[x][y] = cnt;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        ms(dp, -1);

        return recur(0, 0, n, m, obstacleGrid);
    }
};

// 2. Bottom Up Dp:-

class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size(), m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            dp[i][0] = 1;
        }

        for (int j = 0; j < m; j++) {
            if (obstacleGrid[0][j] == 1) {
                break;
            }
            dp[0][j] = 1;
        }


        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }

                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
            }
        }

        return dp[n - 1][m - 1];
    }
};