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

int dp[10005];

int recur(int n, int x, int y, int z) {

	if (n == 0) {
		return 0;
	}

	if (n < x && n < y && n < z) {
		return INT_MAX;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	int a = INT_MIN, b = INT_MIN, c = INT_MIN;

	if (n - x >= 0) {
		a = 1 + recur(n - x, x, y, z);
	}

	if (n - y >= 0) {
		b = 1 + recur(n - y, x, y, z);
	}

	if (n - z >= 0) {
		c = 1 + recur(n - z, x, y, z);
	}

	return dp[n] = max({a, b, c});
}

int cutSegments(int n, int x, int y, int z) {

	if (n < x && n < y && n < z) {
		return 0;
	}

	ms(dp, -1);

	int ans = recur(n, x, y, z);

	if (ans < 0) {
		return 0;
	}

	return ans;
}