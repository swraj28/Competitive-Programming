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

	// 1. Brute Force :- (TLE)--> Complexity --> (No. of Ones)* O(V+E). If number of ones is close to V then the complexity will shoot up to V^2
	// and if the number of ones is close to V^2 then the complexity will shoot upto V^3.

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		int n = mat.size();
		int m = mat[0].size();

		vector<vector<int>> res(n, vector<int>(m, -1));


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					res[i][j] = 0;
				} else {
					queue<pair<int, int>> q;

					int d = 1;

					vector<vector<int>> visited(n, vector<int>(m, 0));

					q.push({i, j});
					visited[i][j] = 1;

					while (!q.empty()) {

						int sze = q.size();

						bool f = false;

						while (sze--) {

							auto s = q.front();
							q.pop();

							for (int k = 0; k < 4; k++) {
								int x = s.ff + dx[k];
								int y = s.ss + dy[k];

								if (x<0 or x >= n or y<0 or y >= m) {
									continue;
								}

								if (mat[x][y] == 0) {
									f = true;
									break;
								}

								if (!visited[x][y]) {
									q.push({x, y});
									visited[x][y] = 1;
								}
							}

							if (f) {
								break;
							}
						}

						if (f) {
							break;
						}

						d += 1;
					}

					res[i][j] = d;
				}
			}
		}

		return res;
	}
};

// Optimized :- (Using Multisource BFS)  --> Using Extra Space using the res vecotor seperately. (But we do not need seperate res array if
// we modify the original matrix .

class Solution {
public:

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		int n = mat.size();
		int m = mat[0].size();

		vector<vector<int>> res(n, vector<int>(m, 0));

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
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

				if (mat[x][y] == 0) {
					continue;
				}

				res[x][y] = mat[s.ff][s.ss] + 1;
				mat[x][y] = 0;

				q.push({x, y});
			}
		}

		return res;
	}
};

// Optimized without using extra space:-

class Solution {
public:

	int dx[4] = { -1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

		int n = mat.size();
		int m = mat[0].size();

		// vector<vector<int>> res(n, vector<int>(m, 0));

		queue<pair<int, int>> q;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 0) {
					q.push({i, j});
				} else {
					mat[i][j] = -1; // Mark all the unvisited node as -1;

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

				if (mat[x][y] != -1) {
					continue;
				}

				mat[x][y] = (mat[s.ff][s.ss] + 1);

				q.push({x, y});
			}
		}

		return mat;
	}
};
