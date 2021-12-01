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

class Solution {
public:

	// Top down Dp:-

	int dp[1000][1000];

	int recur(vector<int>& days, int n, int si, int validity, vector<int>& costs) { // This Function returns min_cost ticket

		if (si >= (n - 1)) {

			if (validity >= days[si]) {
				return 0;
			}

			return min({costs[0], costs[1], costs[2]});
		}

		if (validity >= days[si]) {
			return recur(days, n, si + 1, validity, costs);
		}

		if (dp[si][validity] != -1) {
			return dp[si][validity];
		}


		return dp[si][validity] = min({
			costs[0] + recur(days, n, si + 1, days[si] + 0, costs),
			costs[1] + recur(days, n, si + 1, days[si] + 6, costs),
			costs[2] + recur(days, n, si + 1, days[si] + 29, costs)
		});

	}

	int mincostTickets(vector<int>& days, vector<int>& costs) {

		int n = days.size();

		memset(dp, -1, sizeof(dp));

		return recur(days, n, 0, 0, costs);

		//**************************************************//

		//Bottom-Up:-

		int dp[366];

		memset(dp, 0, sizeof(dp));

		for (auto i : days) {
			dp[i] = costs[0];
		}

		int n = days.size();

		for (int i = 1; i <= days[n - 1]; i++) {

			if (!dp[i]) {
				dp[i] = dp[i - 1];
			} else {
				dp[i] = dp[i - 1] + costs[0];

				int j = max(0, i - 7);

				dp[i] = min(dp[i], dp[j] + costs[1]);

				j = max(0, i - 30);

				dp[i] = min(dp[i], dp[j] + costs[2]);
			}
		}

		return dp[days[n - 1]];
	}
};