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
	string findDifferentBinaryString(vector<string>& nums) {

		int n = nums.size();

		if (n == 1) {
			if (nums[0] == "1") {
				return "0";
			}

			return "1";
		}

		unordered_set<string> s;

		for (auto str : nums) {
			s.insert(str);
		}

		string x = "";

		for (int i = 0; i < n; i++) {
			x += '0';
		}

		string ans = "";

		for (int i = 0; i < (1 << n); i++) {

			string temp = x;
			int bp = 0;

			int val = i;

			while (val) {

				if (val & 1) {
					temp[bp] = '1';
				}

				val >>= 1;
				bp++;
			}

			if (s.find(temp) == s.end()) {
				ans = temp;
				break;
			}
		}

		return ans;
	}
};