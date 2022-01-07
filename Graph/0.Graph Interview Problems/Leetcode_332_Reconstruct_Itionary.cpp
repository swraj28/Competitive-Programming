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
	map<string, multiset<string>> m;
	vector<string> v;

	void dfs(string src) {

		while (m[src].size() > 0) {

			auto it = m[src].begin();

			string nbr = (*it);

			m[src].erase(it);

			dfs(nbr);
		}

		v.push_back(src);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {

		int n = tickets.size();

		for (int i = 0; i < n; i++) {
			string x = tickets[i][0];
			string y = tickets[i][1];

			m[x].insert(y);
		}

		dfs("JFK");

		reverse(v.begin(), v.end());

		return v;
	}
};