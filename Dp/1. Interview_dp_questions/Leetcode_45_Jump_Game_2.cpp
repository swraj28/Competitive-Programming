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

// T.c:- O(n^2)--> Passed On Leetcode. But it might give TLE on some other platforms(Code Studio).

class Solution {
public:

	int dp[10005];

	int recur(vector<int> &nums, int n, int si) { // This Function will return minimum jumps required
		if (si >= (n - 1)) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int ans = (1e8);

		for (int jump = 1; jump <= nums[si]; jump++) {

			if ((si + jump) < (n - 1) and nums[si + jump] == 0) {
				continue;
			}

			int rec_res = 1 + recur(nums, n, si + jump);

			ans = min(ans, rec_res);
		}

		return dp[si] = ans;
	}

	int jump(vector<int>& nums) {

		int n = nums.size();
		if (n == 1) {
			return 0;
		}

		ms(dp, -1);

		return recur(nums, n, 0);
	}
};

// Optimized :- O(n) Solution:- (Greedy)

/*

   The Idea here is while traversing keep on increasing the max reach of the player.

*/

class Solution {
public:

	int jump(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return 0;
		}

		int steps = 0, mx_reach = 0, temp_mx = INT_MIN;

		for (int i = 0; i < n; i++) {

			if (mx_reach >= (n - 1)) {
				break;
			}

			if (i == mx_reach) {
				steps++;
				temp_mx = max({temp_mx, (i + nums[i])});
				mx_reach = max({mx_reach, temp_mx});

			} else if ((i + nums[i]) > mx_reach) {

				temp_mx = max({temp_mx, (i + nums[i])});
			}
		}

		return steps;
	}
};