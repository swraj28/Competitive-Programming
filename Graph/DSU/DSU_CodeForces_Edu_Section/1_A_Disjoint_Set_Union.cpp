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
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/

const int nax = 1e5 + 10;
int par[nax], sz[nax];

int fp(int v) {
	if ( v == par[v] ) return v;
	return par[v] = fp(par[v]);
}

void Union(int a, int b) {
	a = fp(a);
	b = fp(b);

	if (a != b) {
		if (sz[a] > sz[b]) {
			par[b] = a;
			sz[a] += sz[b];
			sz[b] = 0;
		} else {
			par[a] = b;
			sz[b] += sz[a];
			sz[a] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		par[i] = i;
		sz[i] = 1;
	}

	while (m--) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s == "union") {
			Union(a, b);
		} else {
			a = fp(a);
			b = fp(b);

			if (a == b) {
				YES;
			} else {
				NO;
			}
		}
	}

	return 0;
}