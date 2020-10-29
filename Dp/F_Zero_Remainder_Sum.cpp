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

long int n, m, k;
// vector<vector<long int>> v;
long int v[71][71];
long int dp[71][71][71][71];

long int solve(long int r, long int col, long int numTaken, long int rem)
{

	if (numTaken > m / 2)
		return INT_MIN;

	if (r == n)
	{
		if (rem == 0)
			return 0;
		else
			return INT_MIN;
	}

	if (col == m)
		return solve(r + 1, 0, 0, rem);

	if (dp[r][col][numTaken][rem] != -1)
		return dp[r][col][numTaken][rem];
	//This is Similar to kanpsack.
	long int ans = INT_MIN;
	ans = max(ans, solve(r, col + 1, numTaken, rem));//Discard
	ans = max(ans, v[r][col] + solve(r, col + 1, numTaken + 1, (rem + v[r][col]) % k));//Select
	return dp[r][col][numTaken][rem] = ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k;

	// v.resize(n, vector<long int>(m));

	for (long int i = 0; i < n; i++)
		for (long int j = 0; j < m; j++)
			cin >> v[i][j];

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 0, 0, 0);

	return 0;

	return 0;
}