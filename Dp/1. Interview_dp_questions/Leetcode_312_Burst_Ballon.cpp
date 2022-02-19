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

class Solution {
public:

	int recur(vector<int> &nums, int st, int end) {

		if (st > end) {
			return 0;
		}

		if (st == end) {
			return nums[st];
		}

		int ans = INT_MIN;

		for (int i = st; i <= end; i++) {

			int temp = nums[i];

			if ((i + 1) <= end) {
				temp *= nums[i + 1];
			}

			if ((i - 1) >= st) {
				temp *= nums[i - 1];
			}

			temp += recur(nums, st, i - 1) + recur(nums, i + 1, end);

			ans = max({ans, temp});
		}

		return ans;
	}

	int maxCoins(vector<int>& nums) {

		int n = nums.size();

		return recur(nums, 0, n - 1);
	}
};