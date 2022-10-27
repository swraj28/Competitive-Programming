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
#define ms(arr, v) memset(arr, v, sizeof(arr))
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

	int t;
	cin >> t;
	while (t--) {
		ll y, x;
		cin >> y >> x;

		if (y == 1 and x == 1) {
			cout << 1 << endl;
			continue;
		}

		if (y <= x) {
			ll s = ((x - 1) * (ll)(x - 1)) + 1ll;
			ll e = (x * (ll) x);

			if (x & 1) {
				while (y > 1) {
					e--;
					y--;
				}
				cout << e << endl;
			} else {
				while (y > 1) {
					s++;
					y--;
				}
				cout << s << endl;
			}
		} else {

			ll s = ((y - 1) * (y - 1)) + 1ll;
			ll e = (y * y);

			if (y & 1) {
				while (x > 1) {
					s++;
					x--;
				}
				cout << s << endl;
			} else {
				while (x > 1) {
					e--;
					x--;
				}
				cout << e << endl;
			}
		}
	}

	return 0;
}