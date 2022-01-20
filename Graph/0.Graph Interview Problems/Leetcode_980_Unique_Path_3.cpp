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

	int recur(int x, int y, int n, int m, int &cnt, vector<vector<int>>& grid) {

		if (x<0 or x >= n or y<0 or y >= m) {
			return 0;
		}

		if (grid[x][y] == -1) {
			return 0;
		}

		if (grid[x][y] == 2) {
			if (cnt == -1) {
				return 1;
			}
			return 0;
		}

		grid[x][y] = -1;
		cnt -= 1;

		int ans = 0;

		for (int i = 0; i < 4; i++) {
			ans += recur(x + dx[i], y + dy[i], n, m, cnt, grid);
		}

		grid[x][y] = 0;
		cnt += 1;

		return ans;
	}

	int uniquePathsIII(vector<vector<int>>& grid) {

		int n = grid.size(), m = grid[0].size();

		int x = -1, y = -1;

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) {
					x = i, y = j;
				} else if (grid[i][j] == 0) {
					cnt++;
				}
			}
		}

		int ans = recur(x, y, n, m, cnt, grid);

		return ans;
	}
};