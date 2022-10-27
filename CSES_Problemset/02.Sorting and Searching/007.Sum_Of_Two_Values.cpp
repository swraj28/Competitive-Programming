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

	int n, x;
	cin >> n >> x;

	mk(arr, n, int);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.pb(mp(arr[i], i));
	}

	sort(arr, arr + n);

	sort(all(v));

	for (int i = 0; i < n; i++) {
		int a = v[i].ff;
		int b = (x - a);
		if (b > 0) {
			int idx = lower_bound(arr + i + 1, arr + n, b) - arr;
			if (idx < n and v[idx].ff == b) {
				cout << v[i].ss + 1 << " " << v[idx].ss + 1 << endl;
				return 0;
			}
		} else {
			break;
		}
	}

	cout << "IMPOSSIBLE" << endl;

	return 0;
}