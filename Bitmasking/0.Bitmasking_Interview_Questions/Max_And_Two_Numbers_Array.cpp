#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define bct(x) __builtin_popcountll(x)
#define all(v) (v).begin(),(v).end()
#define ms(arr, v) memset(arr, v, sizeof(arr))

class Solution {
public:
	int maxAND (int arr[], int N) {
		if (N == 1) {
			return 0;
		}

		int mx = 0;

		for (int i = 30; i >= 0; i--) {

			int new_mx = (mx | (1 << i));

			int cnt = 0;

			for (int i = 0; i < N; i++) {

				if ((new_mx & arr[i]) == new_mx) {
					cnt++;
				}
			}

			if (cnt >= 2) {
				mx = new_mx;
			}
		}

		return mx;
	}
};