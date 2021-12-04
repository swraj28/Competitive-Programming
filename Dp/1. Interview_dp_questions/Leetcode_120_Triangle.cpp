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

	int recur(vector<vector<int>>& triangle, int n, int r, int c) { // This Function will return the minimum value
		if (r == (n - 2)) {
			return triangle[r][c] + min({triangle[r + 1][c], triangle[r + 1][c + 1]});
		}

		if (dp[r][c] != -1) {
			return dp[r][c];
		}

		return dp[r][c] = triangle[r][c] + min({recur(triangle, n, r + 1, c), recur(triangle, n, r + 1, c + 1)});
	}

	int minimumTotal(vector<vector<int>>& triangle) {

		int n = triangle.size();

		if (n == 1) {
			return triangle[0][0];
		}

		ms(dp, -1);

		return recur(triangle, n, 0, 0);
	}
};