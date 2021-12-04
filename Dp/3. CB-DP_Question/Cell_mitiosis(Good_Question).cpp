/*

There's a scientist named Brook who is interested in budding of cells. He has one container which initially contains only a single cell.
Now Brook wants n number of cells in his container. So he can change the number of cells in container in 3 different ways -:

1.Double the number of cells present in the container.
2.Increase the number of cells in the container by 1.
3.Decrease the number of cells in the container by 1.

Now, all the above operations have different costs associated with them x,y,z respectively for above operations.
Help brook in finding the minimum cost to generate n cells in the container starting from one cell .

Input Format
Each test case contains 2 lines. First lines contains an integer n Second lines contains 3 space separated integers x, y, and z

Constraints
1<=n<=10^5 1<=x<=y<=z<=10^5

Output Format
Output an integer denoting the minimum cost incurred to create n cells

Sample Input
5
2 1 3
Sample Output
4
Explanation
Initial number of cell is 1. Applying 2nd operations four times will give 5 cells in the container ,
and its total cost will be 1x4 = 4. One other way to do is - first adding a single cell with operation 2nd ,then doubling the cells ,
and then again adding one more cell , with cost = 1+2+1 =4.
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

	vector<ll> v;

	for (ll i = 0; i < 3; i++) {
		ll x;
		cin >> x;
		v.pb(x);
	}

	ll dp[n + 1] = {};

	// if i is even then the third operation (i.e.,decrement) will not be used. Since it is going to add extra to the value only

	// if i odd then we cannot reach i from i/2. Therefore operation will not be considered

	for (ll i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + v[0], dp[i - 1] + v[1]);
		} else {
			dp[i] = min(dp[i - 1] + v[1], dp[(i + 1) / 2] + v[0] + v[2]);
		}
	}

	cout << dp[n] << endl;

	return 0;
}