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

// Similar to Stone Game -4 (Leetcode)

class Solution {
public:

	int dp[1005];

	bool recur(int n) {

		if (n <= 1) {
			return false;
		}

		if (dp[n] != -1) {
			return dp[n];
		}

		bool ans = false;

		for (int i = 1; i * i < n; i++) {
			if (n % i == 0) {

				if (i != (n / i) and (i != 1)) {

					bool rec_res = recur(n - i) and recur(n - (n / i));

					if (rec_res == false) {
						ans = true;
						break;
					}
				} else {
					bool rec_res = recur(n - i);

					if (rec_res == false) {
						ans = true;
						break;
					}
				}
			}
		}

		return dp[n] = ans;
	}

	bool divisorGame(int n) {

		ms(dp, -1);

		return recur(n);
	}
};