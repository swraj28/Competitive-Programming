#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Recurrence:-((n)c(k))=((n-1)c(k-1))+((n-1)c(k))

int binomial_coeff_recur(int n, int k) {

	if (k > n) {
		return 0;
	}

	if (k == 0 or k == n) {
		return 1;
	}

	return binomial_coeff_recur(n - 1, k - 1) + binomial_coeff_recur(n - 1, k);
}

int binomial_coeff_memo(int n, int k, int**dp) {

	if (k > n) {
		return 0;
	}

	if (k == 0 or k == n) {
		dp[n][k] = 1;
		return dp[n][k];
	}

	if (dp[n][k] != -1) {
		return dp[n][k];
	}

	return dp[n][k] = binomial_coeff_memo(n - 1, k - 1, dp) + binomial_coeff_memo(n - 1, k, dp);
}

int solve_memo(int n, int k) {

	int**dp;
	dp = new int*[n + 1];

	for (int i = 0; i < (n + 1); i++) {
		dp[i] = new int[k + 1];
	}

	memset(dp, -1, sizeof(dp));

	return binomial_coeff_memo(n, k, dp);
}

void binomial_coeff_pure_dp(int n, int k) {

	int dp[n + 1][k + 1];
	dp[0][0] = 1;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
}

// Space Optimizied Binomial Coefficient
// T.c:-o(n*k);S.c:-o(k)

void binomial_coeff_pure_dp_space_optimized(int n, int k) {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {}

	return 0;
}