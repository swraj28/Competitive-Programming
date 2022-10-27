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

// Brute Force:-

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;

	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		v.pb({a, b});
	}

	sort(all(v));

	set<ll> s;

	ll mx = 1;

	s.insert(v[0].ss);

	for (int i = 1; i < n; i++) {

		ll l = v[i].ff;

		while (s.size() > 0 and (*s.begin()) < l) {
			s.erase(s.begin());
		}

		s.insert(v[i].ss);

		ll x = s.size();

		mx = max(mx, x);
	}

	ll x = s.size();

	mx = max(mx, x);

	cout << mx << endl;

	return 0;
}

// Optimized:-

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	vector<pair<ll, ll>> v;

	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;

		v.pb({a, 0}); // 0--> Arrival Time
		v.pb({b, 1}); // 1--> Departure Time
	}

	sort(all(v));

	// for (ll i = 0; i < 2 * n; i++) {
	// 	cout << v[i].ff << " " << v[i].ss << endl;
	// }
	// cout << endl;

	ll mx = 0;

	ll cnt = 0;

	for (ll i = 0; i < 2 * n; i++) {

		if (v[i].ss == 0) {
			cnt++;
		} else {
			mx = max(mx, cnt);
			cnt--;
		}
	}

	mx = max(mx, cnt);

	cout << mx << endl;

	return 0;
}