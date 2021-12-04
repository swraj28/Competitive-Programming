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

	int n, k;
	cin >> n >> k;
	mk(arr, n, int);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	while (k--) {
		int x;
		cin >> x;
		int i = 0, j = n - 1;
		bool flag = false;
		while (i <= j) {
			int m = i + (j - i) / 2;
			if (arr[m] == x) {
				flag = true;
				break;
			}
			if (arr[m] > x) {
				j = m - 1;
			} else {
				i = m + 1;
			}
		}
		if (flag) {
			YES;
		} else {
			NO;
		}
	}

	return 0;
}