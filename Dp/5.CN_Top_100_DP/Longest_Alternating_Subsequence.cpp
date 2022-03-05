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

// T.c:- O(n^2) && S.c:- O(n*3)=O(n)  ---> TLE (Gfg)

// Similar Question --> Weegle Subsequence (Leetcode)--> Constraints are small. Therefore it will pass the O(n^2) Approach.

int dp[100005][2];

int recur(vector<int> &arr, int n, int si, int prev) {

	if (si >= n) {
		return 0;
	}

	if (dp[si][prev] != -1) {
		return dp[si][prev];
	}

	int mx = 0;

	for (int i = si; i < n; i++) {

		if ((arr[i] > arr[i - 1]) && prev == 1) {
			mx = max({mx, 1 + recur(arr, n, i + 1, 0)});
		} else if ((arr[i] < arr[i - 1]) && prev == 0) {
			mx = max({mx, 1 + recur(arr, n, i + 1, 1)});
		} else {
			mx = max({mx, recur(arr, n, i + 1, prev)});
		}
	}

	return dp[si][prev] = mx;
}

int AlternatingaMaxLength(vector<int>&nums) {

	int n = nums.size();

	if (n <= 1) {
		return 1;
	}

	ms(dp, -1);

	int ans = 1 + max({recur(nums, n, 1, 1), recur(nums, n, 1, 0)});

	return ans;
}

int lSusbsequence(vector<int> &arr, int n) {

	return AlternatingaMaxLength(arr);
}

// Optimization:-  The Only thing that is required is to  count the increasing and decreasing peaks.



