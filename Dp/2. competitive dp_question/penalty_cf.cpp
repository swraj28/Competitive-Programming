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

int recur(string s, int si, int a, int b, int rem_a, int rem_b) { // This function returns total number of penalty shoot outs.We have to return min no of penalty shootouts
	if (si == 10) {
		return 0;
	}

	if ((a + rem_a) < b) {
		return 0;
	}
	if ((b + rem_b) < a) {
		return 0;
	}

	if (s[si] == '1') {
		if (si % 2 == 0) { //Team A turn
			return 1 + recur(s, si + 1, a + 1, b, rem_a - 1, rem_b);
		} else {  //Tean B turn
			return 1 + recur(s, si + 1, a, b + 1, rem_a, rem_b - 1);
		}
	} else if (s[si] == '0') {
		if (si % 2 == 0) { //Team A turn
			return 1 + recur(s, si + 1, a, b, rem_a - 1, rem_b);
		} else {  //Tean B turn
			return 1 + recur(s, si + 1, a, b, rem_a, rem_b - 1);
		}
	} else {
		if (si % 2 == 0) {
			return 1 + min(recur(s, si + 1, a + 1, b, rem_a - 1, rem_b), recur(s, si + 1, a, b, rem_a - 1, rem_b));
		} else {
			return 1 + min(recur(s, si + 1, a, b + 1, rem_a, rem_b - 1), recur(s, si + 1, a, b, rem_a, rem_b - 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		cout << recur(s, 0, 0, 0, 5, 5) << endl;
	}

	return 0;
}#include<bits/stdc++.h>
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

int recur(string s, int si, int a, int b, int rem_a, int rem_b) { // This function returns total number of penalty shoot outs.We have to return min no of penalty shootouts
	if (si == 10) {
		return 0;
	}

	if ((a + rem_a) < b) {
		return 0;
	}
	if ((b + rem_b) < a) {
		return 0;
	}

	if (s[si] == '1') {
		if (si % 2 == 0) { //Team A turn
			return 1 + recur(s, si + 1, a + 1, b, rem_a - 1, rem_b);
		} else {  //Tean B turn
			return 1 + recur(s, si + 1, a, b + 1, rem_a, rem_b - 1);
		}
	} else if (s[si] == '0') {
		if (si % 2 == 0) { //Team A turn
			return 1 + recur(s, si + 1, a, b, rem_a - 1, rem_b);
		} else {  //Tean B turn
			return 1 + recur(s, si + 1, a, b, rem_a, rem_b - 1);
		}
	} else {
		if (si % 2 == 0) {
			return 1 + min(recur(s, si + 1, a + 1, b, rem_a - 1, rem_b), recur(s, si + 1, a, b, rem_a - 1, rem_b));
		} else {
			return 1 + min(recur(s, si + 1, a, b + 1, rem_a, rem_b - 1), recur(s, si + 1, a, b, rem_a, rem_b - 1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		cout << recur(s, 0, 0, 0, 5, 5) << endl;
	}

	return 0;
}