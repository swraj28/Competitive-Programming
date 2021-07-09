#include<bits/stdc++.h>
using namespace std;
#define ll long long

void filter_chars(int n, char a[]) {

	int j = 0;

	while (n > 0) {
		int last_bit = (n & 1);
		if (last_bit) {
			cout << a[j];
		}
		j++;
		n = n >> 1;
	}
	cout << endl;
}

void print_subsets(char a[]) {

	int n = strlen(a);
	for (int i = 0; i < (1 << n); i++) {
		filter_chars(i, a);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char a[100];
	cin >> a;
	print_subsets(a);

	return 0;
}