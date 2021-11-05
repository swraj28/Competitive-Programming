#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fast_power(int n, int x, int start, int sum, vector<int> &v) {
	if (sum == x) {
		for (auto it : v) cout << it << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i <= pow(x, 1.0 / n); i++) {
		int y = pow(i, n);
		if (sum + y > x)
			return;
		sum += y;
		v.push_back(i);
		fast_power(n, x, i + 1, sum, v);
		sum -= y;
		v.pop_back();
	}
}
int main() {

	int x, n;
	cin >> x >> n;
	vector<int> v;
	fast_power(n, x, 1, 0, v);
}