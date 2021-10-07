#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

void print_subarrays_recursion(int arr[], int n, int i, int j) {
	if (j >= n) {
		return;
	}

	if (i >= n) {
		return;
	}

	for (int k = i; k <= j; k++) {
		cout << arr[k] << " ";
	}
	cout << endl;
	print_subarrays_recursion(arr, n, i, j + 1);

	print_subarrays_recursion(arr, n, i + 1, i + 1);

	exit(0);
}

void printSubarrays(int arr[], int n) {  // o(n^3)

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			//Printing
			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}
			cout << endl;
		}
	}
}

int maxSubarraySum(int arr[], int n) { // o(n^3)

	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			int sum = 0;

			//Sum
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}

			// if (sum > maxSum) {
			// 	maxSum = sum;
			// }

			maxSum = max(maxSum, sum);
		}
	}

	return maxSum;
}

int maxSubarraySumOptimized(int arr[], int n) {  // o(n^2)
	int maxSum = INT_MIN;

	for (int i = 0; i < n; i++) {
		int currSum = arr[i];

		maxSum = max(currSum, maxSum);

		for (int j = i + 1; j < n; j++) {

			currSum += arr[j];

			maxSum = max(currSum, maxSum);
		}
	}

	return maxSum;
}

int max_subarray_sum(int arr[], int n) {  // Time:-o(n) : Space:-o(n)

	vector<int> dp(100, 0);

	dp[0] = (arr[0] > 0) ? arr[0] : 0;

	int mx_so_far = dp[0];

	for (int i = 1; i < n; i++) {

		dp[i] = dp[i - 1] + arr[i];

		if (dp[i] < 0) {
			dp[i] = 0;
		}

		mx_so_far = max({mx_so_far, dp[i]});
	}

	return mx_so_far;
}

int kadanesAlgo(int arr[], int n) {  // o(n) space:-o(1)

	int maxSum = arr[0];
	int currSum = arr[0];

	for (int i = 1; i < n; i++) {

		currSum = max(currSum + arr[i], arr[i]);

		maxSum = max(currSum, maxSum);
	}

	return maxSum;
}

int main() {

	int arr[] = {1, 3, 4, -2, 8, -98, 43, 2, -89, 6};
	int n = 10;

	// printSubarrays(arr, n);

	// cout << maxSubarraySum(arr, n) << endl;
	// cout << maxSubarraySumOptimized(arr, n) << endl;
	cout << kadanesAlgo(arr, n) << endl;

	return 0;
}