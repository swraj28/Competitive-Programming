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

int recur(int n, int w, int si, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp) {

	if (si >= n or w <= 0) {
		return 0;
	}

	if (dp[si][w] != -1) {
		return dp[si][w];
	}

	if (w >= weight[si]) {
		return dp[si][w] = max({profit[si] + recur(n, w - weight[si], si, profit, weight, dp), recur(n, w, si + 1, profit, weight, dp)});
	}

	return dp[si][w] = recur(n, w, si + 1, profit, weight, dp);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) {

	vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

	return recur(n, w, 0, profit, weight, dp);

	//********************************************** Top Down********************************************
}
