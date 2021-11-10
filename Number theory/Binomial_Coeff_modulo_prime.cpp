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

//Using Fermats Little Theorem.

// Fermats Little Theorem is used to calculate (nck)%p when p>n. Otherwie we use Lucas Theorem.


//Cses Question:-Binomial Coefficient

ll power(ll a, ll b, ll m) {
	a %= m;
	ll ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans *= a;
			ans %= m;
		}
		a *= a;
		a %= m;
		b >>= 1;
	}

	return ans;
}

ll inverse(ll a, ll m) {  //(m>a):-Thats why we are not checking for the gcd(a,m).Since m is prime and (a<m).so,gcd will always be 1.

	return power(a, m - 2, m);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll fact[1000001];
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		fact[i] = (fact[i - 1] * i) % mod;
	}
	ll n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		ll ans = (fact[a] * inverse(fact[b], mod)) % mod;
		ans *= inverse(fact[a - b], mod);
		ans %= mod;
		cout << ans << "\n";
	}

	return 0;
}