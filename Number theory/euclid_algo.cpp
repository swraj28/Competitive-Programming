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

//gcd(a,b)=a,if b=0;otherwise gcd(a,b)=gcd(b,a%b)
//Recursive
ll gcd(ll a, ll b) { //t.c-o(log(min(a,b)))
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
//Iterative
ll gcd_itr(ll a, ll b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
//Properties:-
//gcd(2*a,2*b)=2*gcd(a,b)
//gcd(2*a,b)=gcd(a,b),if b is odd only
//gcd(a,b)=gcd(a,b-a),if both a,b are odd.

//Extended Euclids Algorithm
int Gcd(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = Gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

//Linear Diophantine Eqn:-
//Finding One Solution:-(a*x+b*y=c)
bool find_any_sol(int a, int b, int c, int &x, int &y, int &g) {
	g = Gcd(abs(a), abs(b), x, y);
	if (c % g) {
		return false;
	}
	x *= c / g;
	y *= c / g;
	if (a < 0)x = -x;
	if (b < 0)y = -y;
	return true;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// int a, b;
	// cin >> a >> b;
	// int x = 0, y = 0;
	// cout << Gcd(a, b, x, y) << endl;
	// cout << x << " " << y << endl;

	int a, b, c;
	cin >> a >> b >> c;
	int x = 0, y = 0, g = 0;
	if (find_any_sol(a, b, c, x, y, g)) {
		cout << x << " " << y << endl;
	} else {
		cout << "No soln" << endl;
	}

	return 0;
}