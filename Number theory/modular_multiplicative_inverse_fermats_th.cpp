#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll power(ll a, ll b, ll m) {
	a %= m;
	ll ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans *= a;
			ans %= m;
		}
		a *= a;
		a %= m;
		b >>= 1;
	}

	return ans;
}

// C++ program to find modular inverse of a
// under modulo m using Fermat's little theorem.
// This program works only if m is prime.


// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modulo_multiplicative_inverse(ll a, ll m) {

	if (__gcd(a, m) != 1) {
		cout << "Inverse Doesn't Exist" << endl;
		return;
	}

	// If a and m are relatively prime, then
	// modulo inverse is a^(m-2) mode m.
	cout << power(a, m - 2, m) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll a, m;
	cin >> a >> m;

	modulo_multiplicative_inverse(a, m);

	return 0;
}