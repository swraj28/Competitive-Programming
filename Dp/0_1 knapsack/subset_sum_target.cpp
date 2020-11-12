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