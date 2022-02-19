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
	int search(vector<int>& nums, int target) {

		int n = nums.size();

		if (n == 1) {
			if (nums[0] == target) {
				return 0;
			}

			return -1;
		}

		int st = 0, end = n;

		while (st < end) {

			int mid = (st + (end - st) / 2);

			if (target <= nums[mid]) {
				if (target >= nums[st] && target <= nums[mid]) {
					end = mid;
				} else {
					st = mid;
				}
			} else {
				if (target > nums[mid] && target <= nums[end]) {
					st = mid + 1;
				} else {
					end = mid - 1;
				}
			}
		}

		return (nums[st] == target) ? st : -1;
	}
};