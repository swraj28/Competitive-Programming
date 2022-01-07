#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(vector<int> graph[], int src, vector<int> &visited, vector<int> &stack) {

	visited[src] = 1;

	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			dfs(graph, nbr, visited, stack);
		}
	}

	//function call is complete (i.e, going back from a node)
	stack.push_back(src);

}

void dfs_2(vector<int> graph[], int src, vector<int> &visited) {

	visited[src] = 1;
	cout << src << " ";
	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			dfs_2(graph, nbr, visited);
		}
	}

}

void solve(vector<int> graph[], vector<int> rev_graph[], int n) {

	vector<int> visited(n, 0);
	vector<int> stack;// to store the ordering

	// Step -1 need to store the vertices according to dfs finish time
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			dfs(graph, i, visited, stack);
		}
	}

	//Ordering=stack

	//step-2 reverse the graph (We have already done ehile taking input)

	// steps-3 do dfs acc to ordering given in the stack from last

	for (int i = 0; i < n; i++) { // Making visited (0) from next dfs call
		visited[i] = 0;
	}
	char component_name = 'A';
	for (int i = stack.size() - 1; i >= 0; i--) {
		int src = stack[i];
		if (!visited[src]) {
			cout << "component " << component_name << "-->";
			//There is a comp.starting from this node
			dfs_2(rev_graph, src, visited);
			cout << endl;
			component_name++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n; //no of vertices (0 to n-1)
	cin >> n;
	vector<int> graph[n];

	vector<int> rev_graph[n];//Reverse Graph

	int m; //No of edges
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;

		graph[x].push_back(y);

		rev_graph[y].push_back(x);
	}

	solve(graph, rev_graph, n);



	return 0;
}