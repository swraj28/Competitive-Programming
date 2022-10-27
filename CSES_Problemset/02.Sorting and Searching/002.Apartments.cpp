#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
#define mod 1000000007
#define mod1 998244353
#define fo1(i,a,b) for(int i=a;i<=b;i++)
#define deb(x) cout<<x<<"\n";
#define deB(x,y) cout<<x<<" "<<y<<"\n";
#define Deb(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define YES cout<<"YES\n";
#define Yes cout<<"Yes\n";
#define NO cout<<"NO\n";
#define No cout<<"No\n";
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];

/*-------------------------------------------------------------------------------------------*/
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
/*--------------------------------------------------------------------------------------------*/

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n, m, k;
	cin >> n >> m >> k;

	mk(arr, n, ll);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	multiset<ll> s;

	for (ll i = 0; i < m; i++) {
		ll x;
		cin >> x;
		s.insert(x);
	}

	sort(arr, arr + n);

	// for (int i = 0; i < n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;

	// for (auto i : s) {
	// 	cout << i << " ";
	// }
	// cout << endl;

	ll cnt = 0;
	ll i = 0;
	while (!s.empty() and (i < n)) {

		ll x = arr[i] - k;
		ll y = arr[i] + k;

		auto itr = s.lower_bound(x);
		if (itr == s.end()) {
			itr--;
		}
		if ((*itr) >= x and (*itr) <= y) {
			cnt++;
			s.erase(itr);
		} else {
			auto itr1 = s.lower_bound(y);
			if (itr1 == s.end()) {
				itr1--;
			}
			if ((*itr1) >= x and (*itr1) <= y) {
				cnt++;
				s.erase(itr1);
			}
		}
		i++;
	}

	cout << cnt << endl;

	return 0;
}