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

	ll count_of_products(vector<int>& nums1, vector<int>& nums2, ll val) {

		ll n = nums1.size(), m = nums2.size();

		ll count = 0;

		for (ll i = 0; i < n; i++) {

			ll x = nums1[i];

			if (x >= 0) {

				ll st = 0, end = m;

				while (st < end) {

					ll mid = (st + (end - st) / 2);

					ll temp_product = (x * (ll) nums2[mid]);

					if (temp_product < val) {
						st = mid + 1;
					} else {
						end = mid;
					}
				}
				count += st;
			} else {

				ll st = 0, end = m;

				while (st < end) {

					ll mid = (st + (end - st) / 2);

					ll temp_product = (x * (ll) nums2[mid]);

					if (temp_product >= val) {
						st = mid + 1;
					} else {
						end = mid;
					}
				}

				count += (m - st);
			}
		}

		return count;
	}

	long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

		ll st = (-1e10), end = (1e10);

		while (st <= end) {

			ll mid = (st + (end - st) / 2);

			ll count = count_of_products(nums1, nums2, mid);

			if (count < k) {
				st = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		return end;
	}
};