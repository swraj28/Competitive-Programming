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

	// This function returns largest subset of strs such that there are at most z 0's and o 1's in the subset.

	int dp[700][105][105];

	int recur(vector<string> &v, vector<pair<int, int>> &cnt, int si, int n, int z, int o) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][z][o] != -1) {
			return dp[si][z][o];
		}

		int z_cnt = cnt[si].ff, o_cnt = cnt[si].ss;

		// for (int i = 0; i < v[si].length(); i++) {
		// 	if (v[si][i] == '1') {
		// 		o_cnt++;
		// 	} else {
		// 		z_cnt++;
		// 	}
		// }

		if (z_cnt <= z and o_cnt <= o) {
			return dp[si][z][o] = max({1 + recur(v, cnt, si + 1, n, z - z_cnt, o - o_cnt), recur(v, cnt, si + 1, n, z, o)});
		}

		return dp[si][z][o] = recur(v, cnt, si + 1, n, z, o);
	}

	int findMaxForm(vector<string>& strs, int m, int n) {

		int len = strs.size();

		vector<pair<int, int>> cnt;

		int z_cnt = 0, o_cnt = 0;

		for (int i = 0; i < len; i++) {
			string s = strs[i];
			for (auto ch : s) {
				if (ch == '1') {
					o_cnt++;
				} else {
					z_cnt++;
				}
			}

			cnt.pb({z_cnt, o_cnt});

			z_cnt = 0, o_cnt = 0;
		}

		ms(dp, -1);

		return recur(strs, cnt, 0, len, m, n);
	}
};