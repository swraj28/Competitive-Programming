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

// Definition for a Node.

class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

// 1. BFS:- (We will only push that element in the queue whose clone is not created).

class Solution {
public:

	Node* cloneGraph(Node* node) {

		if (node == nullptr) {
			return nullptr;
		}

		Node* n = new Node(node->val, {});

		unordered_map<Node*, Node*> copies;

		queue<Node*> q;
		q.push(node);

		copies[node] = n;

		while (!q.empty()) {

			Node* cur = q.front();
			q.pop();

			for (auto nbr : cur->neighbors) {

				if (copies.find(nbr) == copies.end()) {

					Node* n1 = new Node(nbr->val, {});

					copies[nbr] = n1;
					q.push(nbr);
				}

				copies[cur]->neighbors.pb(copies[nbr]);
			}
		}

		return n;
	}
};

// 2. DFS:- (We will Intiate recursion call from that node only whose copies are not created)

class Solution {
public:

	void dfs(Node* node, Node* &n, unordered_map<Node*, Node*>& copies) {

		for (auto nbr : node->neighbors) {

			if (copies.find(nbr) == copies.end()) {
				Node* n1 = new Node(nbr->val, {});

				copies[nbr] = n1;

				dfs(nbr, n1, copies);
			}

			copies[node]->neighbors.pb(copies[nbr]);
		}
	}

	Node* cloneGraph(Node* node) {

		if (node == nullptr) {
			return nullptr;
		}

		Node* n = new Node(node->val, {});

		unordered_map<Node*, Node*> copies;

		copies[node] = n;

		dfs(node, n, copies);

		return n;
	}
};