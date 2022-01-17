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

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

		int n = isWater.size(), m = isWater[0].size();

		vector<vector<int>> res(n, vector<int>(m, 0));

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isWater[i][j] == 1) {
					q.push({i, j});
				}
			}
		}

		while (!q.empty()) {

			auto s = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int x = s.ff + dx[k];
				int y = s.ss + dy[k];

				if (x<0 or x >= n or y<0 or y >= m) {
					continue;
				}

				if (isWater[x][y] == 1) {
					continue;
				}

				res[x][y] = (res[s.ff][s.ss] + 1);
				q.push({x, y});

				isWater[x][y] = 1;
			}
		}

		return res;
	}
};