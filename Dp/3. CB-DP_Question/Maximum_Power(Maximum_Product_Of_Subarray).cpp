/*
Alice is fighting with an alien to save this planet. As alien is very powerful he needs some power to overcome him.
Power points are represented in the form of an array containing both positive and negative powers but the problem is he can get power equal to the product of the subarray he selects.
Help him to decide maximum power he can get.

Input Format
First line contains an integral value denoting the size of array 'n' and then next line represents the array elements.

Constraints
1<=n<=100000 Product of all numbers will fit in long long int.

Output Format
Single integer denoting the maximum power.

Sample Input
8
10 1 2 -13 0 7 -18 2
Sample Output
20

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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	mk(arr, n, ll);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll dp[n + 1][2] = {};

	// dp[i][0]->max +ve product we can get till ith index
	// dp[i][1]->max -ve product we can get till ith index

	dp[0][0] = 0;
	dp[0][1] = 0;

	ll ans = 0;

	for (ll i = 0; i < n; i++) {
		if (arr[i] == 0) {
			dp[i + 1][0] = 0;
			dp[i + 1][1] = 0;
		} else if (arr[i] > 0) {
			dp[i + 1][0] = max(arr[i], dp[i][0] * arr[i]);
			dp[i + 1][1] = dp[i][1] * arr[i];
		} else {
			dp[i + 1][0] = dp[i][1] * arr[i];
			dp[i + 1][1] = min({arr[i], dp[i][0]*arr[i]});
		}

		ans = max(ans, dp[i + 1][0]);
	}

	cout << ans << endl;

	return 0;
}