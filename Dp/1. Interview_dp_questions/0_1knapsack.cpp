#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Recursive
ll knapsack(ll wt[], ll val[], ll w, int n, int si) {
	if (si == n or w == 0) {
		return 0;
	}
	if (w >= wt[si]) {
		return max(val[si] + knapsack(wt, val, w - val[si], n, si + 1), knapsack(wt, val, w, n, si + 1));
	}
	return knapsack(wt, val, w, n, si + 1);
}

//Memoization
//Here in the question there are two variating parameter (n & w).
//Therefore we created a 2d dp.
ll dp[1002][1002];

ll knapsack_memo(ll wt[], ll val[], ll w, int n, int si) {
	if (si == n or w == 0) {
		return 0;
	}
	if (dp[si][w] != -1) {
		return dp[si][w];
	}
	if (w >= wt[si]) {
		return dp[si][w] = max(val[si] + knapsack_memo(wt, val, w - val[si], n, si + 1), knapsack_memo(wt, val, w, n, si + 1));
	}
	return dp[si][w] = knapsack_memo(wt, val, w, n, si + 1);
}

ll knapsack_pure_dp(ll wt[], ll val[], ll w, int n, int si) {
	ll dp1[n + 1][w + 1];
	memset(dp, -1, sizeof(dp));
	//If the number of items left becomes zero then we cannot pick anything
	for (int i = 0; i <= w; i++) {
		dp[0][i] = 0;
	}
	//If the knapsack is fully ocuupied (i.e,it is left with zero space)
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 0;
	}
	//fill the remaining items
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) { //j signifies the weight
			if (j >= wt[i - 1]) {
				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[n][w];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



	return 0;
}