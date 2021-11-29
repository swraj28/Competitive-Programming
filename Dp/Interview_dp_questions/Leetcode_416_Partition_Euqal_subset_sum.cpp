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

	// Top down dp

	int dp[205][20005];
	bool recur(vector<int>& nums, int n, int si, int sm) {
		if (sm == 0) {
			return true;
		}

		if (si >= n) {
			return false;
		}

		if (dp[si][sm] != -1) {
			return dp[si][sm];
		}

		if (nums[si] > sm) {
			return dp[si][sm] = recur(nums, n, si + 1, sm);
		}

		return dp[si][sm] = recur(nums, n, si + 1, sm - nums[si]) or recur(nums, n, si + 1, sm);

	}

	bool canPartition(vector<int>& nums) {

		int n = nums.size();
		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		if (sm & 1) {
			return false;
		}

		ms(dp, -1);

		sm = (sm / 2);

		return recur(nums, n, 0, sm);

		//*************************************************************

		// Bottoms Up Dp:-

		int target = sm;

		bool**dp = new bool*[n + 1];

		for (int i = 0; i <= n; i++) {
			dp[i] = new bool[target + 1];
		}

		dp[0][0] = true;

		for (int i = 0; i <= n; i++) {
			dp[i][0] = true;
		}

		for (int i = 0; i <= target; i++) {
			dp[0][i] = false;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= target; j++) {
				if (j < nums[i - 1]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i - 1]];
				}
			}
		}

		return dp[n][target];

	}
};