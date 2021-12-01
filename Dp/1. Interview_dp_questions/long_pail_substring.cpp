#include <bits/stdc++.h>
using namespace std;
#define ll long long

int dp[1000][1000];
int longest_apilendromic_substring(string str, int s, int e) {
	if (s > e) {
		return 0;
	}
	if (s == e) {
		return 1;
	}
	if (dp[s][e] != -1) {
		return dp[s][e];
	}
	if (str[s] == str[e]) {
		//in case you cannot create a substring from s to e, you need to cover the other two cases.
		return dp[s][e] = max(longest_apilendromic_substring(str, s + 1, e - 1) + 2,
		                      max(longest_apilendromic_substring(str, s + 1, e), longest_apilendromic_substring(str, s, e - 1)));
	}

	return dp[s][e] = max(longest_apilendromic_substring(str, s + 1, e), longest_apilendromic_substring(str, s, e - 1));
}

//Bottom up Approach
//t.c-o(n^2) and s.c-o(n^2)
int long_pail_substring(string str, int n) {
	bool dp1[n][n];
	memset(dp1, 0, sizeof(dp1));
	//A single character always forms a pailedrome
	int max_length = 1;
	int start = 0; //It indicates the index from which the longest pailendrome starts
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}
	//Check For a substring of length 2
	for (int i = 0; i < n - 1; i++) {
		if (str[i] == str[i + 1]) {
			dp1[i][i + 1] = true;
			max_length = 2;
			start = i;
		}
	}
	// Check for lengths greater than 2.
	// k is length of substring
	for (int k = 3; k <= n; k++) {
		// Fix the starting index
		for (int i = 0; i < (n - k + 1); i++) {
			int j = (i + k - 1);
			// checking for sub-string from ith index to
			// jth index iff str[i+1] to str[j-1] is a
			// palindrome
			if (dp1[i + 1][j - 1] and str[i] == str[j]) {
				dp[i][j] = true;

				if (k > max_length) {
					max_length = k;
					start = i;
				}
			}
		}
	}
	//Print the max_length pailengrome
	for (int i = start; i < max_length; i++) {
		cout << str[i];
	}
	cout << endl;
	//return maxlength
	return max_length;
}
//Space Optimization Methode


int main() {

	string s;
	cin >> s;
	int n = s.length();
	memset(dp, -1, sizeof(dp));
	cout << longest_apilendromic_substring(s, 0, n - 1) << endl;

	return 0;
}