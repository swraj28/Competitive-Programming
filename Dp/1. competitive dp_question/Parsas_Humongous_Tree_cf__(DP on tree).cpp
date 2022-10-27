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

const int N = (1e5 + 1);
vector<int> gr[N];
vector<pair<int, int>> v(N);

ll dp[N][2];

void dfs(int src, int par) {

	for (auto nbr : gr[src]) {

		if (nbr != par) {
			dfs(nbr, src);

			//bactracking
			dp[src][0] += max(abs(v[src].ff - v[nbr].ff) + dp[nbr][0], abs(v[src].ff - v[nbr].ss) + dp[nbr][1]);
			dp[src][1] += max(abs(v[src].ss - v[nbr].ff) + dp[nbr][0], abs(v[src].ss - v[nbr].ss) + dp[nbr][1]);
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

		for (int i = 1; i <= n; i++) {
			gr[i].clear();
			dp[i][0] = dp[i][1] = 0;
		}

		for (int i = 1; i <= n; i++) {
			int l, r;
			cin >> l >> r;
			v[i] = mp(l, r);
		}

		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			gr[a].pb(b);
			gr[b].pb(a);
		}

		dfs(1, 0);
		cout << max(dp[1][0], dp[1][1]) << endl;
	}

	return 0;
}