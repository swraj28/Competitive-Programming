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

/*
     To Perform DFS on Tree we actually do not require any visited array.We can simply store parent of any node to perform the DFS.

     As in the adjacency list representation of a tree for every node we store its child and parent in the adj list representation.

*/

const int N = 1e5;

vector<int> gr[N];
int Par[N];

void dfs(int cur, int par) {
	Par[cur] = par;
	for (auto x : gr[cur]) {
		if (x != par) {
			// x is child node
			dfs(x, cur);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(10, 0);

	int x = 6;
	// print all ancestors of 5

	while (x) {
		cout << x << '\n';
		x = Par[x];
	}

	return 0;
}