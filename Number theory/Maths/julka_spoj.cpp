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

vector<int> add(vector<int> x, vector<int> y) {

	reverse(all(x));
	reverse(all(y));

	vector<int> ans;

	int i = 0, j = 0;
	int n = x.size();
	int m = y.size();

	int carry = 0;
	while (i < n and j < m) {
		int sum = x[i] + y[j] + carry;

		ans.pb(sum % 10);
		carry = sum / 10;
		i++, j++;
	}

	while (i < n) {
		int sum = x[i] + carry;
		ans.pb(sum % 10);
		carry = sum / 10;
		i++;
	}

	while (j < m) {
		int sum = y[j] + carry;
		ans.pb(sum % 10);
		carry = sum / 10;

		j++;
	}

	while (carry) {
		ans.pb(carry % 10);
		carry /= 10;
	}

	reverse(all(ans));

	return ans;
}

vector<int> subtract(vector<int> x, vector<int> y) {

	// x>=y (Assuming that x is greater than equal to y)
	reverse(all(x));
	reverse(all(y));

	int n = x.size();
	int m = y.size();

	int i = 0, j = 0;
	vector<int> ans;

	while (i < n and j < n) {
		if (x[i] < y[j]) {
			x[i + 1] -= 1;
			ans.pb(10 + x[i] - y[j]);
		} else {
			ans.pb(x[i] - y[j]);
		}

		i++, j++;
	}

	while (i < n) {

		//e.g(1011-68)
		if (x[i] < 0) {
			x[i + 1] -= 1;
			ans.pb(10 + x[i]);
		} else {
			ans.pb(x[i]);
		}
		i++;
	}

	reverse(all(ans));

	//omit the leading zeros

	vector<int> res;
	i = 0;
	while (i < ans.size() and ans[i] == 0) {
		i++;
	}

	while (i < ans.size()) {
		res.pb(ans[i]);
		i++;
	}

	return ans;

}

vector<int> multiply(vector<int> x, vector<int> y) {

}

vector<int> divide(vector<int> x, int divisor = 2) {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		string s, d;
		cin >> s >> d;
	}

	return 0;
}