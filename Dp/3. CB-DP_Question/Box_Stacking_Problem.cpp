/*
Given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l.
Create a stack of boxes which is as tall as possible.
However, you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box.
Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box.
Your task is to write a program to find the maximum Height by any possible arrangements of the boxes.

Input Format
The first line contains an integer T denoting the no of test cases.
For every test case:
First line contains an integer N denoting the total no of boxes available.
Second line contains 3*N space separated values denoting the height, width and length of the N boxes.
Constraints
1 <= T <= 100 1 <= N <= 100 1 <= l,w,h <= 1000000

Output Format
For every test case, print the maximum height possible with the given boxes.

Sample Input
2
4
4 6 7 1 2 3 4 5 6 10 12 32
3
1 2 3 4 5 6 3 4 1
Sample Output
60
15

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

class box {
public:
	ll l;
	ll w;
	ll h;
};

ll n;
vector<box> v;

bool comapre(const box &b1, const box &b2) {

	return (b1.l * b1.w) > (b2.l * b2.w);  // Comaprision Based On Area
}

ll dp[603];

ll x;

ll recur(ll si, ll last_idx) {
	if (si >= x) {
		return 0;
	}

	if (dp[si] != -1) {
		return dp[si];
	}

	ll mx_ht = 0;

	for (ll i = si; i < x; i++) {

		if ((last_idx == -1) or ((v[last_idx].l > v[i].l) and (v[last_idx].w > v[i].w))) {

			mx_ht = max({mx_ht, recur(i + 1, i) + v[i].h});
		}
	}

	return dp[si] = mx_ht;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll t;
	cin >> t;
	while (t--) {

		cin >> n;

		vector<box> v1;

		for (ll i = 0; i < n; i++) {
			ll l, w, h;
			cin >> l >> w >> h;
			v1.pb({l, w, h});
		}

		v.clear();

		for (ll i = 0; i < n; i++) {
			ll l = v1[i].l;
			ll w = v1[i].w;
			ll h = v1[i].h;

			v.pb({l, w, h});
			v.pb({w, l, h});
			v.pb({l, h, w});
			v.pb({h, l, w});
			v.pb({h, w, l});
			v.pb({w, h, l});
		}


		sort(all(v), &comapre);  // Every box presence 3 times

		// for (auto i : v) {
		// 	cout << i.l << " " << i.w << " " << i.h << endl;
		// }

		ms(dp, -1);

		x = v.size();

		// cout << n << endl;

		cout << recur(0, -1) << endl;
	}


	return 0;
}