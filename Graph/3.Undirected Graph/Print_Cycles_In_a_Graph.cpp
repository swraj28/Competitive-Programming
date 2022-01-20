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

10 13
1 2
2 3
2 4
4 5
5 6
6 7
7 4
3 1
7 8
8 9
9 7
8 10
10 6

*/

const int N = 1e5 + 1;

vector<int> gr[N];

int vis[N], Par[N];

bool cycle = false;

void dfs(int cur, int par) {

	// visited and in call stack
	vis[cur] = 1;
	Par[cur] = par;

	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs(x, cur);
		} else if (x != par && vis[x] == 1) {

			// backedge

			cycle = true;

			int u = cur, v = x;

			while (u != v) {
				cout << u << " ";
				u = Par[u];
			}
			cout << u << endl;
		}
	}

	// visited and not in call stack
	vis[cur] = 2;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			dfs(i, 0);
		}
	}

	if (cycle) {
		cout << "Yes cycle found";
	} else {
		cout << "Not found";
	}

	return 0;
}