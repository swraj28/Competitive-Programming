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

	bool dfs(int start, vector<int> &arr, vector<int> &visited, vector<int> adj[]) {

		visited[start] = 1;

		if (arr[start] == 0) {
			return true;
		}

		for (auto nbr : adj[start]) {
			if (!visited[nbr]) {

				bool ans = dfs(nbr, arr, visited, adj);

				if (ans == true) {
					return true;
				}
			}
		}

		return false;
	}

	bool canReach(vector<int>& arr, int start) {

		if (arr[start] == 0) {
			return true;
		}

		int n = arr.size();
		vector<int> adj[n];

		for (int i = 0; i < n; i++) {
			if (i + arr[i] < n) {
				adj[i].pb(i + arr[i]);
			}

			if ((i - arr[i]) >= 0) {
				adj[i].pb(i - arr[i]);
			}
		}

		vector<int> visited(n, 0);

		return dfs(start, arr, visited, adj);
	}
};