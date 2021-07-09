#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

#define MAX 100001

void Segmented_sieve(ll l, ll r) {

	//Seive Upto (sqrt(r))
	bool arr[MAX];

	for (int i = 0; i < MAX; i++) {
		arr[i] = true;
	}

	arr[0] = arr[1] = false;

	for (int i = 2; i * i < MAX ; i++) {
		if (arr[i]) {
			for (int j = i * i; j < MAX; j += i) {
				arr[j] = false;
			}
		}
	}

	vector<ll> primes;
	primes.pb(2);
	for (int i = 3; i < MAX; i += 2) {
		if (arr[i]) {
			primes.pb(i);
		}
	}

	// (n<=10^8)
	bool is_prime[r - l + 1];

	for (int i = 0; i <= (r - l); i++) {
		is_prime[i] = true;
	}

	for (ll i = 0; primes[i] * (ll)primes[i] <= r; i++) {

		int cur_prime = primes[i];

		//Minimum value less than or equal to l which is a multiple of primes[i].
		ll base = (l / (cur_prime)) * (cur_prime);//this formulae is used to find a number less than or equal to the given number(l) which is a multiple of cur_prime.

		if (base < cur_prime) {
			base += cur_prime;
		}

		for (ll j = base; j <= r; j += cur_prime) {
			is_prime[j - l] = false;
		}

		// There may be a case when base is prime
		// Example:- l=2,cur_prime=3.
		if (base == cur_prime) {
			is_prime[base - l] = true;
		}
	}

	// for (ll i = l; i <= r; i++) {
	// 	if (is_prime[i - l]) {
	// 		cout << i << endl;
	// 	}
	// }

	for (int i = 0; i <= (r - l); i++) {
		if (is_prime[i] == true) {
			if (i + l == 1) {
				continue;
			}

			cout << (i + l) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		ll l, r;
		cin >> l >> r;

		Segmented_sieve(l, r);
		cout << endl;
	}

	return 0;
}