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

	int dp[30005];

	int recur(vector<int> &prices, int si, int n) {

		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int ans = INT_MIN;

		int c_val = prices[si];

		for (int i = si; i < n; i++) {
			if (prices[i] < c_val) {
				continue;
			}

			int rec_res = (prices[i] - c_val) + recur(prices, i + 1, n);

			ans = max(ans, rec_res);
		}

		return dp[si] = ans;
	}

	int maxProfit(vector<int>& prices) {

		int n = prices.size();

		ms(dp, -1);

		return recur(prices, 0, n);
	}
};