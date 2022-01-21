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

// With this recurrence Dynmaic Programming Solution will fail miserably. It is pretty impossible to memoize with such constraints.

// Either we need to optimize our recurrance or we should try some different approaches.

class Solution {
public:

	int recur(vector<int> &nums, int si, int n, int l_sum, int r_sum, int l_sze, int r_sze) { // This function will return mim absolute diff

		if (si >= n) {
			if ((l_sze == r_sze) and (l_sze == n / 2)) {
				return abs(l_sum - r_sum);
			}

			return (1e8);
		}

		if (l_sze < (n / 2) and r_sze < (n / 2)) {

			return min({recur(nums, si + 1, n, l_sum + nums[si], r_sum, l_sze + 1, r_sze), recur(nums, si + 1, n, l_sum, r_sum + nums[si], l_sze, r_sze + 1)});
		} else if (l_sze < (n / 2)) {
			return recur(nums, si + 1, n, l_sum + nums[si], r_sum, l_sze + 1, r_sze);
		}

		return  recur(nums, si + 1, n, l_sum, r_sum + nums[si], l_sze, r_sze + 1);
	}

	int minimumDifference(vector<int>& nums) {

		int n = nums.size();

		return recur(nums, 0, n, 0, 0, 0, 0);
	}
};