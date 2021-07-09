#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = (1e5 + 5);

//t.c-O(E+V)log(V)

vector<pair<int, int>> gr[N];
vector<int> visited(N);

struct Compare {
	bool operator()(pair<int, int> &p1, pair<int, int> &p2)const {

		return p1.second > p2.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		gr[a].push_back({b, w});
		gr[b].push_back({a, w});
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;

	int mn_cost = 0;

	pq.push({0, 0});

	while (!pq.empty()) {
		pair<int, int> p = pq.top(); //Minimum weight edge
		pq.pop();
		if (visited[p.first] == 1) {
			continue;
		}
		mn_cost += p.second;
		visited[p.first] = 1;

		for (auto nbr : gr[p.first]) {
			if (visited[nbr.first] == false) {
				pq.push(nbr);
			}
		}
	}

	cout << mn_cost << endl;

	return 0;
}

/*
7 9
0 1 12
1 2 13
0 3 18
0 4 2
1 4 9
2 5 3
3 4 22
3 6 100
4 6 15
*/