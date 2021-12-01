/*
Prateek went to purchase fruits mainly apples, mangoes and oranges. There are N different fruit sellers in a line. Each fruit seller sells all three fruit items, but at different prices. Prateek, obsessed by his nature to spend optimally, decided not to purchase same fruit from adjacent shops. Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop. Prateek wishes to spend minimum money buying fruits using this strategy. Help Prateek determine the minimum money he will spend. If he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;). All the best!

Input Format
First line indicates number of test cases T. Each test case in its first line contains N denoting the number of fruit sellers in Fruit Market. Then each of next N lines contains three space separated integers denoting cost of apples, mangoes and oranges per kg with that particular fruit seller.

Constraints
1 ≤ T ≤ 10 1 ≤ N ≤ 10^5 Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4

Output Format
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Sample Input
1
3
1 50 50
50 50 50
1 50 50
Sample Output
52
Explanation
There are two ways, each one gives 52 as minimum cost. One way is buy apples from first shop, mangoes from second shop and apples from third shop or he can buy apples from first shop, oranges from second shop and apples from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52

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
vector<vector<int>> v;

// last-->(-1)->no fruit selected; last-->(0)->apple; last-->(1)->oranges;last-->(2)->mangoes;

int dp[100005][3];

int recur(int si, int last) {  // This function will return minimum price spent by prateek bhaiya
	if (si >= n) {
		return 0;
	}

	if (last != -1 and dp[si][last] != -1) {
		return dp[si][last];
	}

	int ans = INT_MAX;

	for (int i = 0; i < 3; i++) {
		if (i == last) {
			continue;
		}

		int rec_res = v[si][i] + recur(si + 1, i);

		ans = min(ans, rec_res);
	}

	return dp[si][last] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		v.clear();

		for (int i = 0; i < n; i++) {
			int a, o, m;
			cin >> a >> o >> m;
			v.pb({a, o, m});
		}

		ms(dp, -1);

		cout << recur(0, -1) << endl;
	}

	return 0;
}
