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

const int INF = (1e7);

class Solution {
public:
	//Function to return the minimum cost to react at bottom
	//right cell from top left cell.

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	int minimumCostPath(vector<vector<int>>& grid) {

		int n = grid.size();

		if (n == 1) {
			return grid[0][0];
		}

		vector<vector<int>> dis(n, vector<int> (n, INF));

		dis[0][0] = grid[0][0];

		set<pair<int, pair<int, int>>> s;

		s.insert({grid[0][0], {0, 0}});

		while (!s.empty()) {

			auto v = s.begin()->ss;
			s.erase(s.begin());

			int x = v.ff;
			int y = v.ss;

			for (int i = 0; i < 4; i++) {

				int new_x = x + dx[i];
				int new_y = y + dy[i];

				if (new_x<0 or new_x >= n or new_y<0 or new_y >= n) {
					continue;
				}

				int len = grid[new_x][new_y];

				if ((dis[x][y] + len) < dis[new_x][new_y]) {

					auto itr = s.find({dis[new_x][new_y], {new_x, new_y}});

					if (itr != s.end()) {
						s.erase(itr);
					}

					dis[new_x][new_y] = (dis[x][y]) + len;

					s.insert({dis[new_x][new_y], {new_x, new_y}});
				}
			}
		}

		return dis[n - 1][n - 1];
	}
};