#include<bits/stdc++.h>
using namespace std;
#define ll long long

// You are given N≤20 numbers, each up to 109. Is there a subset with sum equal to given goal S?

// Recursion-(2^n)

bool subset_sum_to_target_recursion(int arr[], int n, int si, int sum) {

	if (si >= n) {

		if (sum == 0) {
			return true;
		}
		return false;
	}

	if (sum == 0) {
		return true;
	}

	if (sum >= arr[si]) {
		return subset_sum_to_target_recursion(arr, n, si + 1, sum - arr[si]) or subset_sum_to_target_recursion(arr, n, si + 1, sum);
	}

	return subset_sum_to_target_recursion(arr, n, si + 1, sum);
}


// Iterative->Bitmasking-(2^n)

void subset_sum_to_target_bitmasking(int arr[], int n, int sum) {

	for (int mask = 0; mask < (1 << n); mask++) {

		int sum_of_this_subset = 0;

		for (int i = 0; i < n; i++) {

			if (mask & (1 << i)) {
				sum_of_this_subset += arr[i];
			}
		}

		if (sum_of_this_subset == sum) {
			cout << "The subset with the given sum is present" << endl;
			return;
		}
	}

	cout << "The subset with the given sum is not present" << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum;
	cin >> sum;

	if (subset_sum_to_target_recursion(arr, n, 0, sum)) {
		cout << "The subset with the given sum is present" << endl;
	} else {
		cout << "The subset with the given sum is not present" << endl;
	}

	subset_sum_to_target_bitmasking(arr, n, sum);

	return 0;
}