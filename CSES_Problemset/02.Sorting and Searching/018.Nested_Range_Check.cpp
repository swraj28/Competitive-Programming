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
#define pii pair<int,int>
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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;

	vector<pair<ll, ll>> v1, v2;

	map<pair<ll, ll>, ll> m;

	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;

		v1.pb({l, r});
		v2.pb({r, l});

		m[ {l, r}] = i;
	}

	vector<int> ans1(n, 0), ans2(n, 0);

	sort(all(v1), [](pair<ll, ll> &p1, pair<ll, ll> &p2) {
		if (p1.ff == p2.ff) {
			return p1.ss > p2.ss;
		}

		return p1.ff < p2.ff;
	});

	set<ll> s;

	for (ll i = 0; i < n; i++) {

		ll l = v1[i].ff, r = v1[i].ss;

		auto itr = s.lower_bound(r);

		if (itr == s.end()) {
			ans2[m[ {l, r}]] = 0;
		} else {
			ans2[m[ {l, r}]] = 1;
		}

		s.insert(r);
	}

	s.clear();

	sort(all(v2), [](pair<ll, ll> &p1, pair<ll, ll> &p2) {
		if (p1.ff == p2.ff) {
			return p1.ss > p2.ss;
		}

		return p1.ff < p2.ff;
	});

	for (ll i = 0; i < n; i++) {

		ll l = v2[i].ss, r = v2[i].ff;

		auto itr = s.lower_bound(l);

		if (itr == s.end()) {
			ans1[m[ {l, r}]] = 0;
		} else {
			ans1[m[ {l, r}]] = 1;
		}

		s.insert(l);
	}

	for (int i = 0; i < n; i++) {
		cout << ans1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << ans2[i] << " ";
	}
	cout << endl;

	return 0;
}