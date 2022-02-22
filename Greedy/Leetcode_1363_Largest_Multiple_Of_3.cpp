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
	string largestMultipleOfThree(vector<int>& digits) {

		int n = digits.size();
		int sm = 0;

		bool f1 = false;

		for (int i = 0; i < n; i++) {
			sm += digits[i];
			if (digits[i] == 0) {
				f1 = true;
			}
		}

		if (sm <= 2) {
			if (f1) {
				return "0";
			}

			return "";
		}

		if (sm % 3 == 0) {
			string ans = "";
			for (auto digit : digits) {
				ans += (digit + '0');
			}

			sort(all(ans), greater<char>());

			return ans;
		}

		unordered_map<int, int> m;

		for (auto digit : digits) {
			m[digit]++;
		}

		int extra_to_be_subtracted = (sm % 3);

		if (extra_to_be_subtracted == 1) {
			bool f = false;
			for (int i = 1; i <= 9; i++) {
				if (i % 3 == 1) {
					if (m[i] > 0) {
						m[i] -= 1;
						f = true;
						break;
					}
				}
			}
			if (f == false) {
				int cnt = 2;

				for (int i = 1; i <= 9; i++) {
					if (cnt == 0) {
						break;
					}

					if (i % 3 == 2) {
						if (m[i] > 0) {
							int x = min(m[i], cnt);
							cnt -= x;
							m[i] -= x;
						}
					}
				}

				if (cnt > 0) {
					return "";
				}
			}
		} else if (extra_to_be_subtracted == 2) {
			bool f = false;

			for (int i = 1; i <= 9; i++) {
				if (i % 3 == 2) {
					if (m[i] > 0) {
						f = true;
						m[i] -= 1;
						break;
					}
				}
			}
			if (f == false) {
				int cnt = 2;

				for (int i = 1; i <= 9; i++) {
					if (cnt == 0) {
						break;
					}

					if (i % 3 == 1) {
						if (m[i] > 0) {
							int x = min(m[i], cnt);
							cnt -= x;
							m[i] -= x;
						}
					}
				}

				if (cnt > 0) {
					return "";
				}

			}
		}

		string ans = "";

		for (int i = 0; i <= 9; i++) {
			int x = m[i];

			while (x > 0) {
				ans += (i + '0');
				x -= 1;
			}
		}

		sort(all(ans), greater<char>());

		return ans;
	}
};