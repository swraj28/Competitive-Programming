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

// We can even solve this quesetion in O(1) by analysing the pattern.Otherwise Recursive and Dynamic Programming Solution will also work.

class Solution {
public:

	//Turn->0 (Alice)
	//Turn->1 (Bob)

	bool recur(int n, int turn) {

		if (n <= 1) {
			if (turn == 0) {
				return false;
			}

			return true;
		}

		for (int i = 1; i * i < n; i++) {
			if (n % i == 0) {

				if (i != (n / i) and (i != 1)) {

					bool rec_res = recur(n - i, turn ^ 1) or recur(n - (n / i), turn ^ 1);

					if (rec_res) {
						return true;
					}
				}

				return recur(n - i, turn ^ 1);
			}
		}

		return false;
	}

	bool divisorGame(int n) {

		return recur(n, 0);
	}
};