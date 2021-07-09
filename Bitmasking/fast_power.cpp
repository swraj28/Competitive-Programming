#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fast_power_bitmask(ll a , ll n) {

	if (n == 0) {
		return 1;
	}

	ll ans = 1;
	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit == 1) {
			ans *= a;
		}
		a *= a;
		n >>= 1;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll a, n;
	cin >> a >> n;

	cout << fast_power_bitmask(a, n);

	return 0;
}