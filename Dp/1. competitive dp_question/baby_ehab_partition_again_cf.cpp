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

bool canPartitionRecursive(vector<vector<int>> &dp, const vector<int> &num, int sum,
                           int currentIndex) {
	// base check
	if (sum == 0) {
		return true;
	}

	if (num.empty() || currentIndex >= num.size()) {
		return false;
	}

	// if we have not already processed a similar problem
	if (dp[currentIndex][sum] == -1) {
		// recursive call after choosing the number at the currentIndex
		// if the number at currentIndex exceeds the sum, we shouldn't process this
		if (num[currentIndex] <= sum) {
			if (canPartitionRecursive(dp, num, sum - num[currentIndex], currentIndex + 1)) {
				dp[currentIndex][sum] = 1;
				return true;
			}
		}

		// recursive call after excluding the number at the currentIndex
		dp[currentIndex][sum] = canPartitionRecursive(dp, num, sum, currentIndex + 1) ? 1 : 0;
	}

	return dp[currentIndex][sum] == 1 ? true : false;
}

bool canPartition(const vector<int> &num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i];
	}

	// if 'sum' is a an odd number, we can't have two subsets with equal sum
	if (sum % 2 != 0) {
		return false;
	}

	vector<vector<int>> dp(num.size(), vector<int>(sum / 2 + 1, -1));

	return canPartitionRecursive(dp, num, sum / 2, 0);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	if (sum & 1) {
		cout << 0 << endl;
		return 0;
	}


	if (canPartition(v)) {
		for (int j = 0; j <= 13; j++) {

			int idx = -1;
			for (int i = 0; i < n; i++) {
				if (v[i] & 1) {
					idx = i;
					break;
				}
			}

			if (idx != -1) {
				cout << 1 << endl;
				cout << (idx + 1) << endl;
				return 0;
			}

			for (int i = 0; i < n; i++) {
				v[i] /= 2;
			}
		}
	} else {
		cout << 0 << endl;
	}


	return 0;
}