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

//1 . Recursion + Backtracking:-

// One Optimization that we can add is that for every string we are checking wheather it is a pailendrome or not. We can optimize the
// process by using dynamic programming.

class Solution {
public:

	bool is_pailendrome(string s) {

		int n = s.length();
		int st = 0, end = (n - 1);

		while (st <= end) {
			if (s[st] != s[end]) {
				return false;
			}
			st++, end--;
		}

		return true;
	}

	vector<vector<string>> ans;

	void dfs(string s, int si, int n, vector<string> &v) {
		if (si >= n) {
			ans.pb(v);
			return;
		}

		for (int i = si; i < n; i++) {

			string x = s.substr(si, ((i - si) + 1));
			if (is_pailendrome(x)) {
				v.pb(x);
				dfs(s, i + 1, n, v);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {

		vector<string> v;

		dfs(s, 0, s.length(), v);

		return ans;
	}
};

// Optimized Approach:-

class Solution {
public:

	bool dp[20][20] = {};

	vector<vector<string>> ans;

	void dfs(string s, int si, int n, vector<string> &v) {
		if (si >= n) {
			ans.pb(v);
			return;
		}

		for (int i = si; i < n; i++) {

			if (dp[si][i] == 1) {
				string x = s.substr(si, ((i - si) + 1));
				v.pb(x);
				dfs(s, i + 1, n, v);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {

		int n = s.length();


		//************ To check for Pailendrome***************************************************


		for (int i = 0; i < n; i++) { // A single character will always be a pailendrome (sz=1).
			dp[i][i] = 1;
		}

		for (int sze = 2; sze <= n; sze++) {

			for (int i = 0; i <= (n - sze); i++) {

				int start = i, end = (i + sze - 1);

				if (sze == 2) {
					if (s[start] == s[end]) {
						dp[start][end] = 1;
					}
				} else {
					if ((s[start] == s[end]) and (dp[start + 1][end - 1])) {
						dp[start][end] = 1;
					}
				}
			}
		}

		//********************************************************************************************

		vector<string> v;

		dfs(s, 0, s.length(), v);

		return ans;
	}
};