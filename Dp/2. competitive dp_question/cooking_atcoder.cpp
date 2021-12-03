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

int arr[105];

int mn = (1e8);
int ans = 0;

int dp[105][100005];

void recur(int n, int si, int total, int &sum) {
	if (si >= n) {
		int x = (total - sum);
		int d = abs(x - sum);
		if (d < mn) {
			mn = d;
			ans = max(x, sum);
		}
		return;
	}

	if (dp[si][sum]) {
		return;
	}

	sum += arr[si];
	recur(n, si + 1, total, sum);
	sum -= arr[si];
	recur(n, si + 1, total, sum);

	dp[si][sum] = 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	int total = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	int sum = 0;
	recur(n, 0, total, sum);

	cout << ans << endl;

	return 0;
}