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

// Optimal Game Strategy:-

class Solution {
public:

	int dp[505][505];

	int recur(vector<int> &piles, int st, int end) {
		if (st > end) {
			return 0;
		}

		if (dp[st][end] != -1) {
			return dp[st][end];
		}

		int v1 = piles[st] + min({recur(piles, st + 2, end), recur(piles, st + 1, end - 1)});
		int v2 = piles[end] + min({recur(piles, st + 1, end - 1), recur(piles, st, end - 2)});

		return dp[st][end] = max({v1, v2});
	}

	bool stoneGame(vector<int>& piles) {

		int n = piles.size();
		int sm = 0;
		for (int i = 0; i < n; i++) {
			sm += piles[i];
		}

		ms(dp, -1);

		int alice_cnt = recur(piles, 0, n - 1);

		int bob_cnt = (sm - alice_cnt);

		return alice_cnt > bob_cnt;
	}
};