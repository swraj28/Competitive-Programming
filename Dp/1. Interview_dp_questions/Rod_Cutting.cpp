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

// Link:- https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

class Solution {
public:

	int dp[1005];

	int recur(int n, int price[]) {
		if (n == 0) {
			return 0;
		}

		if (n == 1) {
			return price[n - 1];
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		int ans = INT_MIN;

		for (int i = 1; i <= n; i++) {

			int rec_res = price[i - 1] + recur(n - i, price);

			ans = max(ans, rec_res);
		}

		return dp[n] = ans;
	}

	int cutRod(int price[], int n) {

		memset(dp, -1, sizeof(dp));

		return recur(n, price);
	}
};