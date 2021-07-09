#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Naive Approach -o(nlog(n))

int phi_naive(int n) {

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (__gcd(i, n) == 1) {
			ans++;
		}
	}

	return ans;
}

//Optimized Approach in o(sqrt(n)) using prime factorizaton

int phi_optimized(int n) {

	int result = n;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {

			while (n % i == 0) {
				n /= i;
			}
			result -= result / i;
		}
	}
	if (n > 1) {
		result -= result / n;
	}

	return result;
}

//Eulers Totient from 1 to n ino(nlog(log(n)))

// Similar to Sieve Of Erathothenes

void phi_1_to_n(int n) {

	vector<int> phi(n + 1);

	phi[0] = 0;
	phi[1] = 1;

	for (int i = 2; i <= n; i++) {
		phi[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i) {
				phi[j] -= phi[j] / i;
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		cout << phi[i] << " ";
	}
	cout << endl;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {}

	return 0;
}