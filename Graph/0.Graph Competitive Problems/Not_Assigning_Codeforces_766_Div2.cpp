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

/*
     As Per the Question the maximum degree of a particular node cannot exceede 2 otherwise prime sum of edges of size 1 and 2
     are not possible.
     Therefore the tree can be represented as a doubly linked list.
     The output should be done in the same order in which the edges are given as input.
     (2 and 3) or (2 and 5) or (2 and 11)... are only prime paris thats themselves are prime and the resultant of them will also be a prime number.
*/

map<pair<int, int>, int> m;

void dfs(int src, vector<int> adj[], vector<int> &visited , int d) {

	visited[src] = 1;

	for (auto nbr : adj[src]) {
		if (!visited[nbr]) {
			m[ {nbr, src}] = d;
			dfs(nbr, adj, visited, d ^ 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		vector<int> adj[n + 1];

		map<pair<int, int>, int > pos;

		for (int i = 1; i <= n - 1; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);

			pos[ {u, v}] = i;
			pos[ {v, u}] = i;
		}

		queue<int> q;

		q.push(1);

		bool f = true;

		vector<int> visited2(n + 1, 0);

		while (!q.empty()) {

			int s = q.size();

			if (s == 0) {
				break;
			}

			while (s--) {
				int front = q.front();
				q.pop();

				int x = adj[front].size();

				if (x > 2) {
					f = false;
					break;
				}

				for (auto nbr : adj[front]) {
					if (!visited2[nbr]) {
						visited2[nbr] = 1;
						q.push(nbr);
					}
				}
			}

			if (f == false) {
				break;
			}
		}

		if (f == false) {
			cout << -1 << endl;
			continue;
		}

		m.clear();

		vector<int> visited(n + 1, 0);

		int src = -1;

		for (int i = 1; i <= n; i++) {
			if (adj[i].size() == 1) {
				src = i;
				break;
			}
		}

		dfs(src, adj, visited, 2);

		vector<int> ans(n + 1, 0);

		for (auto p : m) {
			int val = p.ss;
			int x = p.ff.ff, y = p.ff.ss;

			ans[pos[ {x, y}]] = val;
		}

		for (int i = 1; i <= n - 1; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}

	return 0;
}