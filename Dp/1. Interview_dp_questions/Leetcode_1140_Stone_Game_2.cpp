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

/*

    Since I as a player playing the game for Alice, Now as per question BoB may or may not take any stone in his turn .

    Since Alice has to maximize her sum therefore alice will pick at every step.

    During Bob turn he will pick in such a way that left piles will yield minimum value to Alice.
*/

class Solution {
public:

	int dp[105][105];

	int recur(vector<int> &piles, vector<int> &sm, int n, int si, int m) {
		if (si >= n) {
			return 0;
		}

		int diff = (n - si);

		if (m >= diff) {
			return sm[si];
		}

		if (dp[si][m] != -1) {
			return dp[si][m];
		}

		int mn = INT_MAX;

		for (int x = 1; x <= (2 * m); x++) {  // Bob Turn:--> Bob is playing Optimally therefore Alice is going to get minimum
			mn = min({mn, recur(piles, sm, n, si + x, max(m, x))});
		}

		return dp[si][m] = (sm[si] - mn);
	}

	int stoneGameII(vector<int>& piles) {

		int n = piles.size();

		if (n == 1) {
			return piles[0];
		}

		vector<int> sm(n, 0);

		int x = 0;

		for (int i = n - 1; i >= 0; i--) {
			x += piles[i];
			sm[i] = x;
		}

		ms(dp, -1);

		return recur(piles, sm, n, 0, 1);
	}
};