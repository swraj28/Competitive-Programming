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

//1. Using Floyd Warshall Algorithm:-

const int INF = 1000000000;

class Solution {
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

		vector<vector<int>> adj(n, vector<int>(n, INF));

		for (auto e : edges) {
			int x = e[0], y = e[1], w = e[2];

			adj[x][y] = w;
			adj[y][x] = w;
		}

		vector<vector<int> > dist(adj);

		int V = n;

		//Phases, in kth phase we included vertices (0,1,2,...k-1) as intermediate vertices
		for (int k = 0; k < V; k++) {

			//Iterate over entire 2D Matrix
			for (int i = 0; i < V; i++) {
				for (int j = 0; j < V; j++) {

					//if vertex k is included as intermidiate vertex, and can we minimise the dist ?

					if (dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
		}

		int mn = INF;
		int city = -1;

		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i == j or dist[i][j] > distanceThreshold) {
					continue;
				}
				cnt++;
			}
			if (cnt <= mn) {
				mn = cnt;
				city = i;
			}
		}

		return city;
	}
};