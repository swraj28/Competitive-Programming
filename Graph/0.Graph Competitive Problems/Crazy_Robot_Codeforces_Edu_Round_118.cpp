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

vector<vector<char>> mat;
vector<vector<int>> visited;
vector<vector<char>> ans;

int n, m;

int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

void dfs(int x, int y) {

	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x<0 or new_x >= n or new_y<0 or new_y >= m) {
			continue;
		}

		if ((visited[new_x][new_y] == 0) and (mat[new_x][new_y] != '#')) {
			cnt++;
		}
	}

	if (cnt <= 1) {

		ans[x][y] = '+';

		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];

			if (new_x<0 or new_x >= n or new_y<0 or new_y >= m) {
				continue;
			}

			if ((visited[new_x][new_y] == 0) and (mat[new_x][new_y] != '#')) {
				dfs(new_x, new_y);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;

		mat.assign(n, vector<char>(m, '#'));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}

		visited.assign(n, vector<int>(m, 0));

		int labx = -1, laby = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 'L') {
					labx = i, laby = j;
					break;
				}
			}
		}

		ans = mat;

		visited[labx][laby] = 1;

		for (int i = 0; i < 4; i++) {
			int x = labx + dx[i];
			int y = laby + dy[i];

			if (x<0 or x >= n or y<0 or y >= m) {
				continue;
			}

			if ((visited[x][y] == 0) and (mat[x][y] != '#')) {
				dfs(x, y);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << ans[i][j];
			}
			cout << '\n';
		}
		cout << '\n';

	}

	return 0;
}