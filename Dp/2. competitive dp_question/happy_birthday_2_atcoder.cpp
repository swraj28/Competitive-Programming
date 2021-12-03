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

#define N 205

ll arr[N];
ll n;

vector<ll> a, b;
// ll dp[N][N][N];

void is_possible(ll i, ll x, ll y) {

	if ((x == y) and (a.empty() == false) and (b.empty() == false)) {
		Yes;
		cout << a.size() << " ";
		for (auto A : a) {
			cout << A + 1 << " ";
		}
		cout << endl;
		cout << b.size() << " ";
		for (auto B : b) {
			cout << B + 1 << " ";
		}
		cout << endl;
		exit(0);
	}

	if (i == n) {
		return;
	}

	// if (dp[i][x][y]) {
	// 	return;
	// }

	a.pb(i);
	is_possible(i + 1, (x + arr[i]) % 200, y);
	a.pop_back();
	b.pb(i);
	is_possible(i + 1, x, (y + arr[i]) % 200);
	b.pop_back();

	is_possible(i + 1, x, y);

	// dp[i][x][y] = 1;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	ll i = 0;
	while (i < n) {
		cin >> arr[i];
		arr[i] %= 200;
		i++;
	}

	is_possible(0, 0, 0);

	No;

	return 0;
}