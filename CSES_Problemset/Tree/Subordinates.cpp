#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626
const int mod = 1000000007;
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

// This Question teaches us about how to compute the subtree sum using dfs.

int n;
vector<int> adj[200001];

vector<int> ans(200001, 0);

void dfs(int src, int par) {

	int sub = 0;

	for (auto nbr : adj[src]) {
		if (nbr != par) {
			dfs(nbr, src);

			sub += (1 + ans[nbr]);
		}
	}

	ans[src] = sub;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}