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
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

		unordered_set<string> s;

		unordered_map<string, bool> visited;

		for (auto itr : wordList) {
			s.insert(itr);
			visited[itr] = false;
		}

		queue<string> q;
		q.push(beginWord);

		visited[beginWord] = true;

		int ans = 0;

		while (!q.empty()) {

			ans++;

			int sze = q.size();

			while (sze--) {
				string node = q.front();
				q.pop();

				if (node == endWord) {
					return ans;
				}

				for (int i = 0; i < node.length(); i++) {

					char ch = node[i];

					for (int j = 0; j < 26; j++) {
						char ch1 = ('a' + j);

						node[i] = ch1;

						if (s.find(node) != s.end()) {
							if (visited[node] == false) {
								visited[node] = true;
								q.push(node);
							}
						}
					}

					node[i] = ch;
				}
			}
		}

		return 0;
	}
};