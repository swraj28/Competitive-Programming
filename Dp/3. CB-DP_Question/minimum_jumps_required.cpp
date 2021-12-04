/*
You are provided an array of integers where each element represents the max number of steps you can take to move ahead.
You need to check that how many minimum steps required to reach at the end of the array.

Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).

Input Format
First line contains integer t which is number of test case. For each test case,
it contains an integers n which the size of array A[]. Next line contains n space separated integers.

Constraints
1<=t<=50
1<=n<=1000
0<=A[i]<=100

Output Format
Print the minimum number of jumps.

Sample Input
1
11
1 3 5 8 9 2 6 7 6 8 9
Sample Output
3
Explanation
1-> 3 (you can pick 5 or 8 or 9 , pick either 8 or 9) -> 8 -> 9

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

ll n;
vector<ll> v;

ll dp[1005];

ll recur(ll si) { // This Functions returns minimum number of move required to reach to end
	if (si >= n - 1) {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	ll ans = INT_MAX;
	ll x = v[si];

	for (ll i = 1; i <= x; i++) {
		ll rec_res = recur(si + i);
		ans = min(ans, rec_res + 1);
	}

	return dp[si] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {
		cin >> n;

		v.clear();

		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			v.pb(x);
		}

		ms(dp, -1);

		cout << recur(0) << endl;
	}

	return 0;
}