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

	int n;
	cin >> n;

	mk(arr, n, ll);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll cnt = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] >= arr[i - 1]) {
			continue;
		}
		cnt += (arr[i - 1] - arr[i]);
		arr[i] = arr[i - 1];
	}

	cout << cnt << endl;

	return 0;
}