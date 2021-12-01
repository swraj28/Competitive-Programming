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
#define mk(arr,n,type)  type *arr=new type[n];

const int MAXN = 1e5 + 5;

int n, t[4 * MAXN];  // why do we create the tree size as (4* MAXN)?? -> Look at notes for explanation.

// Total node:- n->Child Nodes and (n-1)->Internal Nodes --> (2*n)-1 Nodes

// Total Complexity to build the tree-> o(2*n-1) or o(n)

void build(int a[], int v, int tl, int tr) {

	if (tl == tr) {
		t[v] = a[tl];
		return;
	}

	int tm = (tl + tr) / 2;

	build(a, v * 2, tl, tm);
	build(a, v * 2 + 1, tm + 1, tr);

	// Backtracking:-

	t[v] = t[v * 2] + t[v * 2 + 1];

}

int Query(int v, int tl, int tr, int l, int r) {  //o(log(n))

	if (l > r) {
		return 0;
	}

	if (l == tl && r == tr) { // Leaf node which is within the range.
		return t[v];
	}

	int tm = (tl + tr) / 2;

	return Query(v * 2, tl, tm, l, min(r, tm)) + Query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {  //o(log(n))

	if (tl == tr) {
		t[v] = new_val; // Changing the value in the tree at the leaf node.
		return;
	}

	int tm = (tl + tr) / 2;

	if (pos <= tm) {
		update(v * 2, tl, tm, pos, new_val);
	} else {
		update(v * 2 + 1, tm + 1, tr, pos, new_val);
	}

	//Backtracking:-

	t[v] = t[v * 2] + t[v * 2 + 1];

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	mk(arr, n, int);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(arr, 1, 0, n - 1);

	for (int i = 1; i < 18; i++) {
		cout << t[i] << endl;
	}

	cout << "************" << endl;

	update(1, 0, n - 1, 1, 3);

	for (int i = 1; i < 18; i++) {
		cout << t[i] << endl;
	}

	cout << "***************" << endl;


	cout << Query(1, 0, n - 1, 7, 8) << endl;


	return 0;
}