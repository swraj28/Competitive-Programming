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

// Similar to Divisor Game:

class Solution {
public:

	int dp[100005];

	bool recur(int val, vector<int> &squares) {

		if (val == 0) {
			return false;
		}

		if (dp[val] != -1) {
			return dp[val];
		}

		bool ans = false;

		for (int i = 0; i < squares.size(); i++) {
			if (val >= squares[i]) {
				bool rec_res = recur(val - squares[i], squares); // Bobs turn
				if (rec_res == false) {
					ans = true;
					break;
				}
			} else {
				break;
			}
		}

		return dp[val] = ans;
	}

	bool winnerSquareGame(int n) {

		int st = 1;
		vector<int> squares;

		while ((st * (ll)st) <= n) {

			squares.pb((st * st));
			st += 1;
		}

		ms(dp, -1);

		return recur(n, squares);
	}
};