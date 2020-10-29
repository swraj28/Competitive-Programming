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
void prime_sieve_1(int n) { //t.c:-o(n(log(logn))),s.c:-o(n/2)
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
//Bitwise prime sieve:-

//since making a boolean arr[n+1] is very much costly if n is very large.
//here we will optimize the algorithm and create a boolean arr[sqrt(n)].
void space_optimized_prime_sieve(int n) {//t.c-o(nlog(log(n)));s.c-o(sqrt(n))
	int x = floor(sqrt(n));
	bool arr[x + 1];
	memset(arr, true, sizeof(arr));
	arr[0] = arr[1] = false;
	for (int i = 2; i * i <= x; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= x; j += i) {
				arr[j] = false;
			}
		}
	}
	vector<int> prime;
	for (int i = 2; i <= x; i++) {
		if (arr[i]) {
			prime.pb(i);
			cout << i << " ";
		}
	}
	int low = x + 1;
	int high = 2 * x;
	while (low < n) {
		if (high >= n) {
			high = n;
		}
		bool mark[x + 1];
		memset(mark, true, sizeof(mark));

		for (int i = 0; i < prime.size(); i++) {
			// Find the minimum number in [low..high] that is
			// a multiple of prime[i] (divisible by prime[i])
			// For example, if low is 31 and prime[i] is 3,
			// we start with 33.
			int lowlim = floor(low / prime[i]) * prime[i];
			if (lowlim < low) {
				lowlim += prime[i];
			}
			for (int j = lowlim; j < high; j += prime[i]) {
				mark[j - low] = false;
			}
		}
		for (int i = low; i < high; i++) {
			if (mark[i - low]) {
				cout << i << " ";
			}
		}
		low += x;
		high += x;
	}
}
//Segmented Sieve:-
//prime number within a range[l,r]:-(r-l+1) is very large

void Segmented_sieve(ll l, ll r) {

	//Seive Upto (sqrt(r))
	ll x = floor(sqrt(r));
	bool arr[x + 1];
	memset(arr, true, sizeof(arr));
	arr[0] = arr[1] = false;
	for (int i = 2; i * i <= x; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= x; j += i) {
				arr[j] = false;
			}
		}
	}
	vector<ll> prime;
	for (int i = 2; i <= x; i++) {
		if (arr[i]) {
			prime.pb(i);
		}
	}
	int n = r - l + 1;
	bool is_prime[n + 1];
	memset(is_prime, true, sizeof(is_prime));
	for (int i = 0; i < prime.size(); i++) {
		//Minimum value less than or equal to l which is a multiple of primes[i].
		ll base = floor(l / prime[i]) * prime[i];//this formulae is used to find a number less than or equal to l which is amultiple of primes[i].
		if (base < l) {
			base += prime[i];
		}
		//this is done because we cannot mark the corresponding value of base false
		if (base == prime[i]) {
			base += prime[i];
		}
		for (int j = base; j <= r; j += prime[i]) {
			is_prime[j - l] = false;
		}
	}
	if (l == 1) {
		is_prime[0] = false;
	}
	for (ll i = l; i <= r; i++) {
		if (is_prime[i - l]) {
			cout << i << " ";
		}
	}
}

//Prime seive in linear Time complexity if (n<=pow(10,7))


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	prime_sieve(n);
	prime_sieve_1(n);
	// space_optimized_prime_sieve(n);
	// int l, r;
	// cin >> l >> r;
	// Segmented_sieve(l, r);


	return 0;
}