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

// Top Down:-

int dp[100005];

bool recur(int n, int a, int b) {

	if (n == 1) {
		return true;
	}

	if (n <= 0) {
		return false;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	bool x = 1, y = 1, z = 1;

	if ((n - a) >= 0) {
		x = recur(n - a, a, b);
	}

	if ((n - b) >= 0) {
		y = recur(n - b, a, b);
	}

	if ((n - 1) >= 0) {
		z = recur(n - 1, a, b);
	}

	int val = (x & y & z);

	if (val) {
		return dp[n] = false;
	}

	return dp[n] = true;
}

int coinGameWinner(int n, int a, int b) {

	ms(dp, -1);

	return recur(n, a, b);

	//*********************************** Bottom Up*******************************//

	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {

		bool x = 1, y = 1, z = 1;

		if ((i - a) >= 0) {
			x = dp[i - a];
		}

		if ((i - b) >= 0) {
			y = dp[i - b];
		}

		if ((i - 1) >= 0) {
			z = dp[i - 1];
		}

		dp[i] = !(x & y & z);
	}

	for (int i = 0; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;

	return dp[n];
}

