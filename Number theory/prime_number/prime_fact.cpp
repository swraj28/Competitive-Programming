#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

//Naive
void prime_fact_naive(int n) { //o(n)

	vector<int> factors;

	for (int i = 2; i <= n; i++) {

		while (n % i == 0) {
			factors.pb(i);
			n /= i;
		}
	}

	for (auto i : factors) {
		cout << i << " ";
	}
	cout << endl;
}

//Optimized
void prime_fact_optimized(int n) { //o(sqrt(n))

	vector<int> factors;

	for (int i = 2; i * i <= n; i++) {

		while (n % i == 0) {
			factors.pb(i);
			n /= i;
		}
	}

	if (n != 1) {
		factors.pb(n);
	}

	for (auto i : factors) {
		cout << i << " ";
	}
	cout << endl;
}

//Using Sieve-This methode is preferred when we require to perform queries.
void prime_fact_sieve(int n) {

	bool arr[1000001];// (10^6)
	memset(arr, true, sizeof(arr));

	arr[0] = arr[1] = false;

	for (int i = 2; i * i <= 1000000; i++) {
		if (arr[i]) {
			for (int j = i * i; j <= 1000000; j += i) {
				arr[j] = false;
			}
		}
	}

	vector<int> primes;
	primes.pb(2);

	for (int i = 3; i <= 1000000; i += 2) {
		if (arr[i]) {
			primes.pb(i);
		}
	}

	vector<int> factors;

	ll p = primes[0];
	int i = 0;
	while (p * p <= n) {

		while (n % p == 0) {
			factors.pb(p);
			n /= p;
		}

		i += 1;
		p = primes[i];
	}

	if (n != 1) {
		factors.pb(n);
	}

	for (auto i : factors) {
		cout << i << " ";
	}
	cout << endl;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	prime_fact_naive(n);
	cout << endl;
	prime_fact_optimized(n);
	cout << endl;
	prime_fact_sieve(n);

	return 0;
}