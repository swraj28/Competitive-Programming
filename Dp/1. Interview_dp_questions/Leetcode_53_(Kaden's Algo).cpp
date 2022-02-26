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

/*

Time Complexity : O(N2), where N is the number of elements in nums.
There are N*(N+1)/2 total sub-arrays and trying out each one takes time of O(N2).

Space Complexity : O(1)

*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = size(nums), ans = INT_MIN;

		for (int i = 0; i < n; i++) {
			for (int j = i, curSum = 0; j < n ; j++) {
				curSum += nums[j], ans = max(ans, curSum);
			}
		}

		return ans;
	}
};

// Recursive:-

/*
Time Complexity : O(N2), we are basically considering every subarray sum and choosing maximum of it.
Space Complexity : O(N), for recursive space
*/

class Solution {
public:

	int recur(vector<int> &nums, int n, int si, bool pick = false) { // This function will give us maximum subarray sum
		if (si >= n) {

			return pick ? 0 : (-1e5);  // This is done to make a check if we do not select any element.
		}

		if (pick == true) {
			return max({0, nums[si] + recur(nums, n, si + 1, pick)});
		}

		return max({recur(nums, n, si + 1, pick), recur(nums, n, si + 1, true) + nums[si]});
	}

	int maxSubArray(vector<int>& nums) {

		int n = nums.size();

		return recur(nums, n, 0);
	}
};


// Memoization:-

class Solution {
public:

	int dp[100005][2];

	int recur(vector<int> &nums, int n, int si, bool pick = false) { // This function will give us maximum subarray sum
		if (si >= n) {
			return pick ? 0 : (-1e5);  // This is done to make a check if we do not select any element.
		}

		if (dp[si][pick] != -1) {
			return dp[si][pick];
		}

		if (pick == true) {
			return dp[si][pick] = max({0, nums[si] + recur(nums, n, si + 1, pick)});
		}

		return dp[si][pick] = max({recur(nums, n, si + 1, pick), recur(nums, n, si + 1, true) + nums[si]});
	}

	int maxSubArray(vector<int>& nums) {

		int n = nums.size();

		ms(dp, -1);

		return recur(nums, n, 0);
	}
};

// Bottom Up Approach:- (Tabulation)

class Solution {
public:

	int maxSubArray(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> dp(n + 1, vector<int>(2, 0));

		dp[0][0] = dp[0][1] = nums[0];

		for (int i = 1; i < n; i++) {

			dp[i][1] = max({nums[i], dp[i - 1][1] + nums[i]});

			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1]});
		}

		return max({dp[n - 1][0], dp[n - 1][1]});
	}
};

// Optimized Tabulation:-

class Solution {
public:

	int maxSubArray(vector<int>& nums) {

		int n = nums.size();

		vector<int> dp(n, 0);

		dp[0] = nums[0];

		// dp[i] indicates the maximum sum ending at i

		for (int i = 1; i < n; i++) {
			dp[i] = max({nums[i], dp[i - 1] + nums[i]});
		}

		return *max_element(all(dp));
	}
};


// Kaden's Algorithm:-

/*
    We can observe that in the previous approach, dp[i] only depended on dp[i-1].
    Thus, we only need to maintain curMax which is the maximum subarray sum ending at i and maxTillNow which is the maximum sum we have seen till now.
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int curMax = 0, maxTillNow = INT_MIN;

		for (auto c : nums) {
			curMax = max(c, curMax + c),
			maxTillNow = max(maxTillNow, curMax);
		}

		return maxTillNow;
	}
};

// Divide and Conqure Techniques to solve the maximum subarray sum:-