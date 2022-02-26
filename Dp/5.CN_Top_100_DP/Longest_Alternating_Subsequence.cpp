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

int recur(vector<int> &arr, int n, int si, int prev) {
	if (si >= n - 1) {
		return 0;
	}

	int mx = 0;

	for (int i = si + 1; i < n; i++) {
		if (prev == 0) {
			if (arr[i] > arr[si]) {
				mx = max({mx, 2 + recur(arr, n, i, 1)});
			} else if (arr[i] < arr[si]) {
				mx = max({mx, 2 + recur(arr, n, i, 2)});
			}
		} else if (prev == 1) {
			if (arr[i] < arr[si]) {
				mx = max({mx, 1 + recur(arr, n, i, 2)});
			}
		}

		if (arr[i] > arr[si]) {
			mx = max({mx, 1 + recur(arr, n, i, 1)});
		}
	}

	return mx;
}

int AlternatingaMaxLength(vector<int>&nums) {

	int n = nums.size();

	if (n <= 1) {
		return 0;
	}

	int ans = recur(nums, n, 0, 0);

	return ans;
}