#include <bits/stdc++.h>
using namespace std;
#define ll long long

//Given a set of non-negative integers, and a value sum,
//determine if there is a subset of the given set with sum equal to given sum.
bool subset_sum_target(int arr[], int n, int si, int sum) {
	if (sum == 0) {
		return true;
	}
	if (si >= n) {
		return false;
	}
	//If the element is greater than the sum then just ignore it.
	if (arr[si] > sum) {
		return subset_sum_target(arr, n, si + 1, sum);
	}
	/* else, check if sum can be obtained by any
	of the following:
	(a) including arr[si]
	(b) excluding arr[si]  */
	return subset_sum_target(arr, n, si + 1, sum - arr[si]) or subset_sum_target(arr, n, si + 1, sum);
}
//Memoization:-
bool dp[1000][1000];//Here there are two variating parameters size of array and sum.
bool subset_sum_target_memo(int arr[], int n, int si, int sum) {
	if (sum == 0) {
		return true;
	}
	if (si >= n or sum < 0) {
		return false;
	}
	if (dp[si][sum] != false) {
		return dp[si][sum];
	}

	return dp[si][sum] = subset_sum_target_memo(arr, n, si + 1, sum - arr[si]) or subset_sum_target_memo(arr, n, si + 1, sum);
}
//Pure Dp:-
// Return true if there exists a subsequence of arr[0..n) with given sum
bool subset_sum_target_Pure(int arr[], int n, int si, int sum) {

	// dp1[i][j] stores true if subset with sum j can be attained with
	// using items up to first i items
	bool dp1[n + 1][sum + 1];
	// if 0 items in the list and sum is non-zero
	for (int i = 0; i <= sum; i++) {
		dp[0][i] = false;
	}
	//If the sum is zero
	for (int i = 0; i <= n; i++) {
		dp[i][0] = true;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			// find subset with sum j by excluding or including the ith item
			if (arr[i - 1] <= j) {
				dp1[i][j] = dp1[i - 1][j - arr[i - 1]] or dp1[i - 1][j];
			} else {
				// don't include ith element if j-arr[i-1] is negative
				dp1[i][j] = dp1[i - 1][j];
			}
		}
	}
	return dp[n][sum];
}

//Printing the subset sum to target
//Recursive
void subset_sum(int arr[], int n, int si, int k, vector<int>v) {

	if (k == 0) {
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
		v.clear();
		return;
	}

	if (si >= n or k < 0) {
		return;
	}
	v.push_back(arr[si]);
	subset_sum(arr, n, si + 1, k - arr[si], v);
	v.pop_back(); //Backtracking
	subset_sum(arr, n, si + 1, k, v);
}
//Dp

int main() {

	int n, sum;
	cin >> n >> sum;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// if (subset_sum_target(arr, n, 0, sum)) {
	// 	cout << "YES" << endl;
	// } else {
	// 	cout << "NO" << endl;
	// }
	memset(dp, 0, sizeof(dp));
	if (subset_sum_target_memo(arr, n, 0, sum)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}