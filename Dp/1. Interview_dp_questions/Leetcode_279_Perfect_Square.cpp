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

	int dp[10005];

	int recur(int n) {
		if (n == 0) {
			return 0;
		}

		if (n < 0) {
			return (1e5);
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		int mn = INT_MAX;

		for (int i = 1; i * i <= n; i++) {
			int rec_res = 1 + recur(n - (i * i));
			mn = min(mn, rec_res);
		}

		return dp[n] = mn;
	}

	int numSquares(int n) {

		ms(dp, -1);

		return recur(n);
	}
};