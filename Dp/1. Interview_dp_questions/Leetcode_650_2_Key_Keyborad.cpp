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

	int dp[1005][1005];

	int recur(int st, int n, int copy) {
		if (st == n) {
			return 0;
		}

		if (st > n) {
			return (1e3);
		}

		if (copy == 0) {
			return 1 + recur(st, n, st);
		}

		if (copy == st) {
			return 1 + recur(st + copy, n, copy);
		}

		if (dp[st][copy] != -1) {
			return dp[st][copy];
		}

		//(start>copy)

		return dp[st][copy] = min({1 + recur(st + copy, n, copy), 1 + recur(st, n, st)});
	}

	int minSteps(int n) {

		if (n == 1) {
			return 0;
		}

		if (n == 2 or n == 3) {
			return n;
		}

		ms(dp, -1);

		return recur(1, n, 0);
	}
};