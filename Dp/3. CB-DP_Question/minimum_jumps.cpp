/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element.
Print the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input Format
n, size of array Ai, array elements

Constraints
1<=n<=5000 1<=Ai<=10^5

Output Format
Number of minimum jumps

Sample Input
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
3 (1-> 3 -> 8 ->9)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int dp[50001];

int minimum_jumps(int arr[], int n, int si) {
	if (si >= n) {
		return 0;
	}
	if (dp[si] != -1)return dp[si];

	int ans = INT_MAX;
	int j = arr[si];

	for (int i = 1; i <= j; i++) {
		int rec_result = minimum_jumps(arr, n, si + i);

		ans = min(ans, rec_result + 1);
	}
	dp[si] = ans;

	return ans;
}

int main() {

	int n;
	cin >> n;

	int arr[5007];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));

	cout << minimum_jumps(arr, n, 0) << endl;

	// for (int i = 0; i < n + 1; i++) {
	// 	cout << dp[i] << " ";
	// }

	return 0;
}