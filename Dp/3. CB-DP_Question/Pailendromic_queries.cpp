/*
Given a string s and m queries . Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

Input Format
First line contains n Second lines contains a string of length n. Next line contains m where m is the number of queries . Next m lines contains two integers l,r as described in the question.

Constraints
n <= 1000

m <= 100000

Output Format
for every query from l to r print "YES" if s[l…..r] is palindrome else print "NO" without quotes in a new line.

Sample Input
5
abbac
2
1 4
2 4
Sample Output
YES
NO
Explanation
s[1….4]="abba", it is a palindrome.

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
// cout << *s.find_by_order(0) << endl; // print the 0-th smallest number in s(0-based)

/*-------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/

int n;
string s;
bool dp[1005][1005];

// Top Down:-

bool recur(int l, int r) {
	if (l == r) {
		return true;
	}

	if (l == (r - 1)) {
		if (s[l] == s[r]) {
			return true;
		}
		return false;
	}

	if (s[l] != s[r]) {
		return dp[l][r] = 0;
	}

	if (dp[l][r]) {
		return dp[l][r];
	}

	return dp[l][r] = recur(l + 1, r - 1);
}

//Bottom Up:-

void Solve (string s, int n, int m) {

	bool dp1[1005][1005] = {}; // All the values are initialized with zero

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
				if ((s[start] == s[end]) and (dp[start + 1] == dp[end - 1])) {
					dp[start][end] = 1;
				}
			}
		}
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << (dp[l][r] ? "YES" : "NO") << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;

	ms(dp, 0);

	bool dp1[1005][1005] = {};

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (recur(i, j)) {
				dp1[i][j] = 1;
			}
		}
	}

	int m;
	cin >> m;

	while (m--) {
		int l, r;
		cin >> l >> r;
		l -= 1, r -= 1;

		if (dp1[l][r]) {
			YES;
		} else {
			NO;
		}
	}

	return 0;
}
