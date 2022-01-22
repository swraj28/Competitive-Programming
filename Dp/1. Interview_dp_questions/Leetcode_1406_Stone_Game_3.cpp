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


// Similar to Stone Game 2:-

class Solution {
public:

	int dp[50009];

	int recur(vector<int> &piles, vector<int> &sm, int n, int si) {
		if (si >= n) {
			return 0;
		}

		if (dp[si] != -1) {
			return dp[si];
		}

		int mn = INT_MAX;

		for (int x = 1; x <= 3; x++) {  // Bob Turn:--> Bob is playing Optimally therefore Alice is going to get minimum
			mn = min({mn, recur(piles, sm, n, si + x)});
		}

		return dp[si] = (sm[si] - mn);
	}

	string stoneGameIII(vector<int>& stoneValue) {

		int n = stoneValue.size();

		vector<int> sm(n, 0);

		int x = 0;

		for (int i = n - 1; i >= 0; i--) {
			x += stoneValue[i];
			sm[i] = x;
		}

		ms(dp, -1);

		int alice_cnt = recur(stoneValue, sm, n, 0);

		int bob_cnt = x - (alice_cnt);

		if (alice_cnt == bob_cnt) {
			return "Tie";
		} else if (alice_cnt < bob_cnt) {
			return "Bob";
		}

		return "Alice";
	}
};