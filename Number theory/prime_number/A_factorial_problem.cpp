#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define mk(arr,n,type)  type *arr=new type[n];

// maximum value of x such that (n!%(k^x)=0). n<=(10^8) and k<=(10^8)

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {

		ll n, k;
		cin >> n >> k;

		ll ans = INT_MAX;

		for (ll i = 2; i * i <= n; i++) { //o(sqrt(n))

			if (k % i == 0) {
				ll occur = 0;
				while (k % i == 0) {
					occur++;
					k /= i;
				}

				//find out the power of i in n!
				ll cnt = 0;
				ll p = i;
				while (p <= n) {
					cnt += (n / p);
					p *= i;
				}

				ans = min(ans, cnt / occur);
			}
		}

		//We have a prime factor left (occurance of prime factor s only once)
		if (k != 1) {

			ll cnt = 0;
			ll p = k;
			while (p <= n) {
				cnt += (n / p);
				p *= k;
			}
			ans = min(ans, cnt);
		}

		if (ans == INT_MAX) { //We are unable to find any factor of k in n!
			cout << 0 << endl;
		} else {
			cout << ans << endl;
		}
	}

	return 0;
}