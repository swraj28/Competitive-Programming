#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Memoized approach
int dp[100][100];
int l_p_sub(string str, int s, int e) {
	//Base case -1(if a single char is left)
	if (s == e) {
		return 1;
	}
	//If two characters are left and both are equal
	if (e == s + 1 and str[s] == str[e]) {
		return 2;
	}
	if (dp[s][e] != -1) {
		return dp[s][e];
	}
	// If the first and last characters match
	if (str[s] == str[e]) {
		return dp[s][e] = l_p_sub(str, s + 1, e - 1) + 2;
	}
	// If the first and last characters do not match
	return dp[s][e] = max(l_p_sub(str, s, e - 1), l_p_sub(str, s + 1, e));
}
//Pure Dp
//Do After studying MAtrix Chain Multiplication

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int n = str.length();
	memset(dp, -1, sizeof(dp));
	cout << l_p_sub(str, 0, n - 1) << endl;

	return 0;
}