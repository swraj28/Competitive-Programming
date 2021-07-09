//find out the number of numbers between 1 and n
//which are divisible by any of the prime numbers less than 20
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	ll prime[] = {2, 3, 5, 7, 11, 13, 17, 19}; //size 8

	// To Find:-(2 u 3 u 5 u 7 u 11 u 13 u 17 u 19) //union

	while (t--) {
		ll n;
		cin >> n;

		ll subsets = (1 << 8) - 1; //Total Subsets (Excluding The Null Set)
		ll ans = 0;

		//Iterate over the subsets
		for (ll i = 1; i <= subsets; i++) {
			ll deno = (ll)1;
			ll set_bits = __builtin_popcount(i);

			//Iterate over all the bit position
			for (ll j = 0; j <= 7; j++) {
				//check if the particular bit is set or not,then multiply with prime[j].
				if (i & (1 << j)) { //mask
					deno *= prime[j];
				}
			}

			if (set_bits & 1) {
				ans += n / deno;
			} else {
				ans -= n / deno;
			}
		}

		cout << ans << endl;
	}

	return 0;
}