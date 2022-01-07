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

ll find_parent(ll v, vector<ll> &parent) {  // Without using the path compression technique
	if (v == parent[v]) {
		return v;
	}

	return find_parent(parent[v], parent);
}

ll get(ll v, vector<ll> &parent, vector<ll> &add) {

	if (v == parent[v]) {
		return add[v];
	}

	return add[v] + get(parent[v], parent, add);
}

void Union(ll a, ll b, vector<ll> &parent, vector<ll> &sze, vector<ll> &add) {

	a = find_parent(a, parent);
	b = find_parent(b, parent);

	if (a == b) {
		return;
	}

	if (sze[a] >= sze[b]) {
		add[b] -= add[a];
		parent[b] = a;
		sze[a] += sze[b];
	} else {
		add[a] -= add[b];
		parent[a] = b;
		sze[b] += sze[a];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n, q;
	cin >> n >> q;

	vector<ll> parent(n + 1);
	vector<ll> sze(n + 1);

	vector<ll> add(n + 1);

	for (ll i = 1; i <= n; i++) {
		parent[i] = i;
		sze[i] = 1;
	}

	while (q--) {
		string s;
		cin >> s;

		if (s == "add") {
			ll a, val;
			cin >> a >> val;

			add[find_parent(a, parent)] += val;
		} else if (s == "join") {
			ll a, b;
			cin >> a >> b;
			Union(a, b, parent, sze, add);
		} else {
			ll a;
			cin >> a;

			cout << get(a, parent, add) << endl;
		}
	}

	return 0;
}