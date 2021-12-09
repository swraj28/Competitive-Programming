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
	void dfs(int src, vector<int> gr[], vector<int> &visited) {
		visited[src] = 1;

		for (auto nbr : gr[src]) {
			if (!visited[nbr]) {
				dfs(nbr, gr, visited);
			}
		}
	}

	bool canVisitAllRooms(vector<vector<int>>& rooms) {

		int n = rooms.size();
		vector<int> gr[n];
		vector<int> visited(n);

		for (int i = 0; i < n; i++) {
			for (auto room : rooms[i]) {
				gr[i].push_back(room);
			}
		}

		int src = 0;

		dfs(src, gr, visited);

		for (int i = 0; i < n; i++) {
			if (visited[i] == 0) {
				return false;
			}
		}

		return true;
	}
};