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


// 1.Using Set:-

// 2. Using Trie:-

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {

		int n = nums.size();

		if (n == 1) {
			return 0;
		}

		int mx = 0, mask = 0;

		unordered_set<int> s;

		for (int i = 30; i >= 0; i--) {

			mask |= (1 << i);  // 10000.., 1100000.., 11100000..., 1111000...

			for (int i = 0; i < n; i++) {
				s.insert((mask & nums[i]));
			}

			int new_mx = (mx | (1 << i));

			for (auto prefix : s) {

				if (s.count((prefix ^ new_mx))) {
					mx = new_mx;
					break;
				}
			}

			s.clear();
		}

		return mx;
	}
};