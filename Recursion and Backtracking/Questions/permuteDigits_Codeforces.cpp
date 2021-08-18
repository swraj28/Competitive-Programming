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

multiset<int> m;
vector<int> v;

list<int> ans;

int recur(int si) {

	if (si >= v.size()) {
		return 1; // We got the lexicographically highest permutaion.
	}

	int dig = v[si];

	if (m.find(dig) == m.end()) {
		if (m.lower_bound(dig) != m.begin()) {
			auto itr = m.lower_bound(dig);
			itr--;
			int val = (*itr);
			ans.push_back(val);
			m.erase(itr);
			while (m.size() > 0) {
				auto itr1 = m.end();
				itr1--;
				ans.pb(*itr1);
				m.erase(itr1);
			}
			return 1;
		} else {
			return 0;  // We cannot place that particualr digit at that position in the sequence.(Backtrack)
		}
	} else {
		//	if the digit is present in the set then by placing that digit at that position we have to find that whether we obtain lexicographically
		// highest permutaion less than or eual to b.
		m.erase(m.find(dig));
		if (recur(si + 1)) { //Ask recursion to place remaining digits.If possible then palce that digit
			ans.push_front(dig);
			return 1;
		} else {
			// We cannot place the digit at that position.
			// It means we have to place digit with smaller value at that position.
			m.insert(dig);
			if (m.lower_bound(dig) != m.begin()) {
				auto itr = m.lower_bound(dig);
				itr--;
				int val = (*itr);
				ans.push_back(val);
				m.erase(itr);

				while (m.size() > 0) {
					auto itr1 = m.end();
					itr1--;
					ans.pb(*itr1);
					m.erase(itr1);
				}
				return 1;
			} else {
				return 0;  // // We cannot place that particualr digit at that position in the sequence.(Backtrack)
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ull a, b;
	cin >> a >> b;

	string s = to_string(a);
	string t = to_string(b);

	if (t.length() > s.length()) {
		sort(all(s), greater<char>());
		cout << s << endl;
		return 0;
	}

	for (int i = 0; i < s.length(); i++) {
		m.insert(s[i] - '0');
	}

	for (int i = 0; i < t.length(); i++) {
		v.pb(t[i] - '0');
	}

	if (recur(0)) {
		for (auto i : ans) {
			cout << i;
		}
		cout << endl;
	}


	return 0;
}