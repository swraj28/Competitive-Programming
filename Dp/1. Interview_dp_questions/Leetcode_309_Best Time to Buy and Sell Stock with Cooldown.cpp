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

	int dp[5005][2];

	int recur(vector<int> &prices, int n, int si, bool f = false) { // This Function will return the maximum profit gained
		if (si >= n) {
			return 0;
		}

		if (dp[si][f] != -1) {
			return dp[si][f];
		}

		if (f == false) {
			return dp[si][f] = max({recur(prices, n, si + 1, true) - prices[si], recur(prices, n, si + 1, f)});
		}

		return dp[si][f] = max({prices[si] + recur(prices, n, si + 2, false), recur(prices, n, si + 1, f)});
	}

	int maxProfit(vector<int>& prices) {

		int n = prices.size();

		if (n == 1) {
			return 0;
		}

		ms(dp, -1);

		return recur(prices, n, 0);
	}
};