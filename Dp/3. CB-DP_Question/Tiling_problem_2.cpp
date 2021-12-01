/*
Problem Name: Tilling Problem - II
Problem Constraints: 1 <= T<= 1000
1 <= N,M <= 100000
Problem Description:
Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size  1 x m . A tile can either be placed horizontally or vertically.

Input Format: First line of input contains an integer T denoting the number of test cases. Then T test cases follow.The first line of each test case contains two integers N and M.
Sample Input: 2
2 3
4 4
Output Format: Print answer for every test case in a new line modulo 10^9+7.
Sample Output:
1
2
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

const int N = (1e5 + 1);

ll dp[N];

ll tiling(ll n, ll m) {
	if (n == 0) {
		return 0;
	}
	if (n < m) {
		return 1;
	}

	if (n == m) {
		return 2;
	}

	if (dp[n] != -1) {
		return dp[n];
	}

	ll ans;
	ans = (tiling(n - 1, m) + tiling(n - m, m)) % mod; // visulaize it like fibonacci numbers.

	return dp[n] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		ms(dp, -1);

		cout << tiling(n, m) << endl;
	}

	return 0;
}