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
	int dp[25][25];

	int recur(vector<int>& nums, int l, int r) {
		if (l > r) {
			return 0;
		}

		if (dp[l][r] != -1) {
			return dp[l][r];
		}

		int val1 = nums[l] + min({recur(nums, l + 2, r), recur(nums, l + 1, r - 1)});

		int val2 = nums[r] + min({recur(nums, l + 1, r - 1), recur(nums, l, r - 2)});

		return dp[l][r] = max(val1, val2);
	}

	bool PredictTheWinner(vector<int>& nums) {

		int n = nums.size();

		ms(dp, -1);

		int val = recur(nums, 0, n - 1);

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		sm -= val;

		if (val >= sm) {
			return true;
		}

		return false;
	}
};