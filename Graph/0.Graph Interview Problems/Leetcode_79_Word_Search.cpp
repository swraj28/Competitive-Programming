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
	bool ans;

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	void dfs(int x, int y, int n, int m, vector<vector<char>> &board, string word, vector<vector<int>>& visited, int idx) {

		if (idx == word.length()) {
			ans = true;
			return;
		}

		if (x<0 or x >= n or y<0 or y >= m) {
			return;
		}

		if (visited[x][y]) {
			return;
		}

		if (board[x][y] != word[idx]) {
			return;
		}

		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			dfs(x + dx[i], y + dy[i], n, m, board, word, visited, idx + 1);
		}

		// Backtracking:-

		visited[x][y] = 0;
	}

	bool exist(vector<vector<char>>& board, string word) {

		int n = board.size();
		int m = board[0].size();

		vector<vector<int>> visited(10, vector<int>(10, 0));

		ans = false;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] and board[i][j] == word[0]) {
					dfs(i, j, n, m, board, word, visited, 0);
				}
			}
		}

		return ans;
	}
};