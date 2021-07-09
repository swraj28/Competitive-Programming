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

//For a given number n which is non-prime there must be atleast one divisor of n less than or equal to sqrt(n).
// Reason:- Divisors always occur in pairs.

void prime_sieve(int n) { //o(nlog(log(n)))

	bool arr[n + 1];
	memset(arr, true, sizeof(arr));
	arr[0] = arr[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= n; j += i) {
				arr[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}

//Optimized Prime Seive:-(escape all the even numbers)

void prime_sieve_1(int n) { //t.c:-o(n(log(logn))),s.c:-o(n/2 bytes)

	bool arr[n / 2];

	memset(arr, true, sizeof(arr));
	for (int i = 3; i * i < n; i += 2) {
		if (arr[i / 2]) {
			for (int j = i * i; j < n; j += i * 2) {
				arr[j / 2] = false;
			}
		}
	}

	cout << 2 << " ";

	for (int i = 3; i < n; i += 2) {
		if (arr[i / 2]) {
			cout << i << " ";
		}
	}
	cout << endl;
}

//Bitset prime sieve:-

void bit_set_prime_sieve() { //o(nlog(log(n))) s.c-(n bits)

	const int n = 10000000;
	bitset <10000005> arr; // It will occupy only one bit

	arr.set();
	arr[0] = arr[1] = 0;

	for (ll i = 2; i * i <= n; i++) {
		if (arr[i]) {
			for (ll j = i * i; j <= n; j += i) {
				arr[j] = 0;
			}
		}
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	prime_sieve(n);
	prime_sieve_1(n);
	bit_set_prime_sieve();

	return 0;
}