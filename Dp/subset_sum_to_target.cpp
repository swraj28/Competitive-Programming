#include <bits/stdc++.h>
using namespace std;

//Recursive Implementation
bool subset_sum_to_target(int arr[], int n, int si, int t_s, int s) {
	if (si == n and t_s != s) {
		return false;
	}
	if (t_s == s) {
		return true;
	}
	return subset_sum_to_target(arr, n, si + 1, t_s + arr[si], s) or subset_sum_to_target(arr, n, si + 1, t_s, s);
}

int main() {

	int n, s;
	cin >> n >> s;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (subset_sum_to_target(arr, n, 0, 0, s)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}
//Memoization
#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> dp;

bool subset_sum_target(int arr[], int n, int si, int t_s, int s) {
	if (si == n and t_s != s) {
		return false;
	}
	if (t_s == s) {
		return true;
	}

	string key = to_string(si) + "|" + to_string(t_s);

	if (dp.find(key) == dp.end()) {

		dp[key] = subset_sum_target(arr, n, si + 1, t_s + arr[si], s) or subset_sum_target(arr, n, si + 1, t_s, s);
	}
	return dp[key];
}

int main() {

	int n, s;
	cin >> n >> s;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (subset_sum_target(arr, n, 0, 0, s)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}

//Pure Dp
#include <iostream>
using namespace std;

bool subsetSum(int *arr, int n, int target) {
	bool **dp = new bool*[n + 1];
	for (int i = 0; i <= n; i++) {
		dp[i] = new bool[target + 1];
	}
	dp[0][0] = true; // If sum is zero and no element is taken ans is true
	for (int i = 1; i <= n; i++) { // If sum is zero ans is always true
		dp[i][0] = true;
	}
	for (int i = 1; i <= target; i++) { // If no element is chosen and sum is not zero ans is false
		dp[0][i] = false;
	}
	//do it for th ith item
	for (int i = 1; i <= n; i++) {
		//consider all sum from 1 to target
		for (int j = 1; j <= target; j++) {
			//Don't include the ith element if j-arr[i-1] is neagative
			if (j < arr[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			// find the subset with sum j by including or excluding the ith item
			if (j >= arr[i - 1]) {
				dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]];
			}
		}
	}
	return dp[n][target];

}

int main(int argc, char const *argv[])
{
	int n, target;
	cin >> n >> target;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (subsetSum(arr, n, target)) cout << "Yes";
	else cout << "No";
	return 0;
}