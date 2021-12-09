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
	int minTrioDegree(int n, vector<vector<int>>& edges) {

		vector<int> cnt(n + 1);

		vector<vector<int>> v(n + 1, vector<int>(n + 1));

		int m = edges.size();

		for (int i = 0; i < m; i++) {
			int x = edges[i][0];
			int y = edges[i][1];

			cnt[x]++;
			cnt[y]++;

			v[x][y] = 1;
			v[y][x] = 1;
		}

		int ans = INT_MAX;

		for (int i = 1; i <= n; i++) {

			for (int j = i + 1; j <= n; j++) {

				for (int k = j + 1; k <= n; k++) {

					if (v[i][j] and v[j][k] and v[k][i]) {
						ans = min(ans, (cnt[i] + cnt[j] + cnt[k] - 6));
					}
				}
			}
		}

		return ans == INT_MAX ? -1 : ans;

	}
};