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

ll n;
vector<pair<ll, ll>> t(4 * MAXN); // why do we create the tree size as (4* MAXN)?? -> Look at notes for explanation.

// Total node:- n->Child Nodes and (n-1)->Internal Nodes --> (2*n)-1 Nodes

// Total Complexity to build the tree-> o(2*n-1) or o(n)

void build(ll a[], ll v, ll tl, ll tr) {

	if (tl == tr) {
		t[v].ff = a[tl];
		t[v].ss = 1;
		return;
	}

	ll tm = (tl + tr) / 2;

	build(a, v * 2, tl, tm);
	build(a, v * 2 + 1, tm + 1, tr);

	// t[v] = min(t[v * 2] , t[v * 2 + 1]);

	ll val1 = t[v * 2].ff;
	ll val2 = t[v * 2 + 1].ff;

	if (val1 == val2) {
		t[v].ff = val1;
		t[v].ss = (t[v * 2].ss + (ll) t[v * 2 + 1].ss);
	} else if (val1 < val2) {
		t[v].ff = val1;
		t[v].ss = t[v * 2].ss;
	} else {
		t[v].ff = val2;
		t[v].ss = t[v * 2 + 1].ss;
	}
}

pair<ll, ll> Query(ll v, ll tl, ll tr, ll l, ll r) {

	if (l > r) {
		return {1e9, 0};
	}

	if (l == tl && r == tr) { // Leaf node which is within the range.
		return {t[v].ff, t[v].ss};
	}

	ll tm = (tl + tr) / 2;

	// return min(Query(v * 2, tl, tm, l, min(r, tm)) , (ll) Query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));

	auto ans1 = Query(v * 2, tl, tm, l, min(r, tm));
	auto ans2 =  Query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);

	if ((ans1.ff) == (ans2.ff)) {
		return {ans1.ff, (ans1.ss + (ll) ans2.ss)};
	} else if ((ans1.ff) < (ans2.ff)) {
		return {ans1.ff, ans1.ss};
	}

	return {ans2.ff, ans2.ss};
}

void update(ll v, ll tl, ll tr, ll pos, ll new_val) {

	if (tl == tr) {
		t[v].ff = new_val; // Changing the value in the tree at the leaf node.
		t[v].ss = 1;
		return;
	}

	ll tm = (tl + tr) / 2;

	if (pos <= tm) {
		update(v * 2, tl, tm, pos, new_val);
	} else {
		update(v * 2 + 1, tm + 1, tr, pos, new_val);
	}

	//Backtracking:-

	// t[v] = min(t[v * 2] , t[v * 2 + 1]);

	ll val1 = t[v * 2].ff;
	ll val2 = t[v * 2 + 1].ff;

	if (val1 == val2) {
		t[v].ff = val1;
		t[v].ss = (t[v * 2].ss + (ll) t[v * 2 + 1].ss);
	} else if (val1 < val2) {
		t[v].ff = val1;
		t[v].ss = t[v * 2].ss;
	} else {
		t[v].ff = val2;
		t[v].ss = t[v * 2 + 1].ss;
	}

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

	// for (int i = 1; i < 15; i++) {
	// 	cout << t[i] << " ";
	// }
	// cout << endl;

	while (q--) {

		ll x;
		cin >> x;
		if (x == 1) {
			ll i, v;
			cin >> i >> v;

			update(1, 0, n - 1, i, v);
		} else {
			ll l, r;
			cin >> l >> r;

			auto ans = Query(1, 0, n - 1, l, r - 1);

			cout << ans.ff << " " << ans.ss << endl;
		}
	}


	return 0;
}