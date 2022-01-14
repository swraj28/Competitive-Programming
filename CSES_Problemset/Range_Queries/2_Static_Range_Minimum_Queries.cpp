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

const int MAXN = 2e5 + 5;

ll n, t[4 * MAXN];  // why do we create the tree size as (4* MAXN)?? -> Look at notes for explanation.

// Total node:- n->Child Nodes and (n-1)->Internal Nodes --> (2*n)-1 Nodes

// Total Complexity to build the tree-> o(2*n-1) or o(n)

void build(ll a[], ll v, ll tl, ll tr) {

	if (tl == tr) {
		t[v] = a[tl];
		return;
	}

	ll tm = (tl + tr) / 2;

	build(a, v * 2, tl, tm);
	build(a, v * 2 + 1, tm + 1, tr);

	t[v] = min(t[v * 2] , t[v * 2 + 1]);

}

ll Query(ll v, ll tl, ll tr, ll l, ll r) {

	if (l > r) {
		return (1e9);
	}

	if (l == tl && r == tr) { // Leaf node which is within the range.
		return t[v];
	}

	ll tm = (tl + tr) / 2;

	return min(Query(v * 2, tl, tm, l, min(r, tm)) , (ll) Query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {

	if (tl == tr) {
		t[v] = new_val; // Changing the value in the tree at the leaf node.
		return;
	}

	ll tm = (tl + tr) / 2;

	if (pos <= tm) {
		update(v * 2, tl, tm, pos, new_val);
	} else {
		update(v * 2 + 1, tm + 1, tr, pos, new_val);
	}

	//Backtracking:-

	t[v] = min(t[v * 2] , t[v * 2 + 1]);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll q;
	cin >> n >> q;

	mk(arr, n, ll);

	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}

	build(arr, 1, 0, n - 1);


	while (q--) {

		ll l, r;
		cin >> l >> r;

		cout << Query(1, 0, n - 1, l - 1, r - 1) << endl;
	}


	return 0;
}