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
    This Question is Same as (Minimum Sum Partition)--> Only the language has been changed.

    // Minimum Sum Partition:- https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1
*/

/*
        Reason :- Why this question is similar to "divide the set into two subsets having difference between their sum is minimum"

                -->Say you have four stones a,b,c,d.
					first you smash b against c, you get (b-c)
					now you smash (b-c) against a
					you get a-(b-c) which is same as (a+c)-(b)
					now you smash d against (a+c)-b
					you get d-((a+c)-b) which is same as (d+b)-(a+c).

				Basically for the given stones we can create two sets,the sum of second set of stones to be subtracted from sum of first one.
				ideally we want sum of each set to be sum(stones)/2 so that they cancel each other out.
*/

class Solution {
public:

	bool recur(vector<int> &v, int n, int si, int sm, vector<vector<int>> &dp) {

		if (sm == 0) {
			return true;
		}

		if (si >= n) {
			return false;
		}

		if (dp[si][sm] != -1) {
			return dp[si][sm];
		}

		if (v[si] > sm) {
			return dp[si][sm] = recur(v, n, si + 1, sm, dp);
		}

		return dp[si][sm] = recur(v, n, si + 1, sm - v[si], dp) or recur(v, n, si + 1, sm, dp);
	}

	int lastStoneWeightII(vector<int>& stones) {

		int n = stones.size();

		if (n == 1) {
			return stones[0];
		}

		if (n == 2) {
			return abs(stones[0] - stones[1]);
		}

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += stones[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(sm + 1, -1));

		int mn = INT_MAX;

		for (int i = sm / 2; i >= 0; i--) {
			if (recur(stones, n, 0, i, dp)) {
				int val = sm - i;
				val = abs(val - i);
				if (val < mn) {
					mn = val;
				}
				break;
			}
		}

		return mn;
	}
};