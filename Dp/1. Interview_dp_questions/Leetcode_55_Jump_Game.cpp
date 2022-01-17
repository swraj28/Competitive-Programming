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


// 1. Dynamic Programming:-

class Solution {
public:

	int dp[10005];

	vector<int> v;
	int n;

	bool recur(int si) {
		if (si >= (n - 1)) {
			return true;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		for (int jump = 1; jump <= v[si]; jump++) {

			if ((si + jump) < (n - 1) and v[si + jump] == 0) {
				continue;
			}

			bool rec_res = recur(si + jump);

			if (rec_res == true) {
				return dp[si] = true;
			}
		}

		return dp[si] = false;
	}

	bool canJump(vector<int>& nums) {

		n = nums.size();

		if (n == 1) {
			return true;
		}

		v = nums;

		ms(dp, -1);

		return recur(0);
	}
};

// 2. Simple Iteration:-

class Solution {
public:
	bool canJump(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return true;
		}

		int mx = nums[0];

		for (int i = 1; i < n; i++) {
			if (mx == 0) {
				return false;
			}
			mx -= 1;
			mx = max(mx, nums[i]);
		}

		return true;
	}
};