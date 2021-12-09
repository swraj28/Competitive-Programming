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
	int findCenter(vector<vector<int>>& edges) {
		int mx = INT_MIN;

		int n = edges.size();

		for (int i = 0; i < n; i++) {
			mx = max({mx, edges[i][0], edges[i][1]});
		}

		vector<int> cnt(mx + 1, 0);

		for (int i = 0; i < n; i++) {
			cnt[edges[i][0]]++;
			cnt[edges[i][1]]++;
		}

		int ans = -1;

		for (int i = 1; i <= mx; i++) {
			if (cnt[i] == (n)) {
				ans = i;
				break;
			}
		}

		return ans;
	}
};