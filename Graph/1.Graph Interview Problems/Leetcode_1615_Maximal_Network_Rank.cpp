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
	int maximalNetworkRank(int n, vector<vector<int>>& roads) {

		// This Submission ->O(n^2)

		vector<int> cnt(n);

		int m = roads.size();

		vector<vector<int>> gr(n, vector<int>(n, 0));

		for (int i = 0; i < m; i++) {
			cnt[roads[i][0]]++;
			cnt[roads[i][1]]++;

			gr[roads[i][0]][roads[i][1]] = 1;
			gr[roads[i][1]][roads[i][0]] = 1;
		}

		int mx = INT_MIN;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int val = (cnt[i] + cnt[j]) - gr[i][j];

				mx = max(mx, val);
			}
		}

		return mx;
	}
};