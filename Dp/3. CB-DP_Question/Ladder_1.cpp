/*
Let's define a new game of snakes and ladders. There is only one dimension of n cells. Each cell either contains a snake or ladder.
One can simply take a jump of not more than k cells. A person cannot step on a snake. However, s/he can jump over a snake.
Alice is excited to play this game and is asking you to calculate the number of ways to finish the game.
Game starts at 1st cell and ends at the nth cell. It is guaranteed that there is a ladder at the 1st cell.
Since the number can be large, output the answer modulo (109+7).

Input Format
First line contains 2 integers N and K, denoting the number of cells and the maximum possible jump respectively.
The next line contains N integers, x1, x2,…., xN, where xi is either 0 or 1.
xi=0 denotes that there is a ladder in ith cell, xi=1 denotes that there is a snake in ith cell.

Constraints
1<=N<=10^4 1<=K<=10^4 0<=xi<=1

Output Format
Output a single integer denoting the number of ways to finish the game modulo (109+7).

Sample Input
5 2
0 0 0 1 0
Sample Output
2

Explanation
There are 2 ways to reach the 5th cell - [1,2,3,5] and [1,3,5].

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

int n, k;
vector<int> v;

int dp[10005];

int recur(int si) {
	if (si >= (n - 1)) {
		return 1;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	int ans = 0;

	for (int i = 1; i <= k; i++) {
		if (v[i + si] == 0) {
			int rec_res = recur(si + i) % mod;
			ans = (ans + rec_res) % mod;
		}
	}

	return dp[si] = (ans % mod);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.pb(x);
	}

	ms(dp, -1);

	cout << recur(0) << endl;

	return 0;
}