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

	bool dp1[2005][2005] = {};

	bool checkPartitioning(string s) {

		int n = s.length();


		//************ To check for Pailendrome***************************************************


		for (int i = 0; i < n; i++) { // A single character will always be a pailendrome (sz=1).
			dp1[i][i] = 1;
		}

		for (int sze = 2; sze <= n; sze++) {

			for (int i = 0; i <= (n - sze); i++) {

				int start = i, end = (i + sze - 1);

				if (sze == 2) {
					if (s[start] == s[end]) {
						dp1[start][end] = 1;
					}
				} else {
					if ((s[start] == s[end]) and (dp1[start + 1][end - 1])) {
						dp1[start][end] = 1;
					}
				}
			}
		}

		//*******************************************************************************************

		bool f = false;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if ((j + 1) < n) {
					if (dp1[0][i] == 1 and dp1[i + 1][j] == 1 and dp1[j + 1][n - 1] == 1) {
						f = true;
						break;
					}
				}
			}
		}

		return f;
	}
};