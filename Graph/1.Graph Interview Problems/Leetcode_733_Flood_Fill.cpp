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

	void dfs(int x, int y, int n, int m, vector<vector<int>>& grid, int cur_color, int newColor) {

		if (x<0 or x >= n or y<0 or y >= m) {
			return;
		}

		if (grid[x][y] != cur_color) {
			return;
		}

		grid[x][y] = newColor;


		for (int i = 0; i < 4; i++) {
			dfs(x + dx[i], y + dy[i], n, m, grid, cur_color, newColor);
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

		if (image[sr][sc] == newColor) {
			return image;
		}

		int n = image.size();
		int m = image[0].size();

		int cur_color = image[sr][sc];

		dfs(sr, sc, n, m, image, cur_color, newColor);

		return image;

		// vector<vector<int>> visited(n, vector<int>(m, 0));


	}
};