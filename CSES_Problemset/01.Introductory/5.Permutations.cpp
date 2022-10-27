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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	} else if (n < 4) {
		cout << "NO SOLUTION" << endl;
	} else {
		if (n == 4) {
			cout << 2 << " " << 4 << " " << 1 << " " << 3 << endl;
			return 0;
		}
		if (n & 1) {
			for (int i = 1; i <= n; i += 2) {
				cout << i << " ";
			}
			for (int i = 2; i < n; i += 2) {
				cout << i << " ";
			}
			cout << endl;
		} else {
			for (int i = 1; i < n; i += 2) {
				cout << i << " ";
			}
			for (int i = 2; i <= n; i += 2) {
				cout << i << " ";
			}
			cout << endl;
		}
	}

	return 0;
}