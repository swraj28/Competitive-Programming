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
    The main idea behind the recurrance is that the Longest incresing sequence may start from any index of the array.
    Therefore we will recursively try to find the Longest incresing subsequnce from each and every index of the array.
*/

/*
        Time Complexity:-

        Let the complexity of the solution without dynamic programming for an input size n = f(n)

		Now, observe the recurrence:
		f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(1)
		where recursively f(n-1) = f(n-2) + f(n-3) + ... f(1)

		Clearly, we can observe that f(n) = 2*f(n-1)
		So our compact recurrence relation is f(n) = 2*f(n-1)

		f(n) = 2*f(n-1)
		f(n-1) = 2*f(n-2)
		...
		f(2) = 2*f(1)
		f(1) = 2*f(0)

		Among the above equations, multiply the ith equation by 2^(i-1) and then add all the equations. We clearly then have f(n) = (2^n)*f(0) = O(2^n)

		Hence the complexity is exponential = O(2^n)

		Now let's look at what happens when we use dynamic programming. When we use DP, we are saving f(n) once we compute it,
		so that we don't compute it ever again in the recursion. That leaves us with:

		f(n) = f(n-1) + f(n-2) + ... f(1)

		but this time when the recursive call of f(n-1) computes f(n-2), f(n-3), etc. then we don't have to recompute it while calculating f(n).

		So now, f(n) = n + (n-1) + (n-2) + ... 1 which is O(n^2)
*/

// Top Down DP:-

class Solution {
public:

	int dp[3000];

	int recur(vector<int> &nums, int n, int si) {

		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int ans = 1;

		for (int i = si + 1; i < n; i++) {

			if (nums[i] > nums[si]) {
				int rec_res = 1 + recur(nums, n, i);

				ans = max(ans, rec_res);
			}
		}

		return dp[si] = ans;
	}

	int lengthOfLIS(vector<int>& nums) {

		int n = nums.size();

		if (n <= 1) {
			return n;
		}

		int mx = 1;

		ms(dp, -1);

		for (int i = 0; i < n; i++) {
			mx = max(mx, recur(nums, n, i));
		}

		return mx;
	}
};

// Bottom Up Dp:-

/*
      The Key Idea in Bottom Up DP:-

      For each element, we will find the length of the Longest Increasing Subsequence(LIS) that ends at that element (i).
*/

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {

		if (nums.size() == 0)return 0;

		vector<int>dp(nums.size(), 1);

		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int max_size = 1;
		for (auto i : dp) {
			max_size = max(max_size, i);
		}

		return max_size;

	}
};

// Greedy Approach:-



// Greedy + Binary Search:-

