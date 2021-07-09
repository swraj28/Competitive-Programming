#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int n = 10000000;
bitset <10000005> arr; // It will occupy only one bit

vector<int> primes;

void bit_set_prime_sieve() { //o(nlog(log(n))) s.c-(n bits)

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
			// cout<<i<<" ";
			primes.push_back(i);
		}
	}
}

bool large_prime_check(ll no) {  //no<=(10^16)->max size of array can be (10^8).

	if (no <= n) {
		return arr[no] == 1 ? true : false;
	}

	for (ll i = 0; primes[i] * (ll)primes[i] <= no; i++) {
		if (no % primes[i] == 0) {
			return false;
		}
	}
	return true;
}


int main() {

	bit_set_prime_sieve();

	ll x;
	cin >> x;

	if (large_prime_check(x)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
