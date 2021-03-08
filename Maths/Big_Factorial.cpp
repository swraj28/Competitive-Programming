#include<bits/stdc++.h>
using namespace std;
#define ll long long

void multiply(int*a, int &n, int no) {

	int carry = 0;
	for (int i = 0; i < n; i++) {
		int product = (a[i] * no) + carry;
		a[i] = product % 10;
		carry = product / 10;
	}

	while (carry) {
		a[n] = carry % 10;
		carry /= 10;
		n++;
	}
	return;
}

void big_factorial(int no) {

	int*a = new int[1000];

	for (int i = 0; i < 1000; i++) {
		a[i] = 0;
	}

	a[0] = 1; //First Element Is kept 1
	int n = 1; //No of digits in the array
	for (int i = 2; i <= no; i++) {
		multiply(a, n, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		cout << a[i];
	}
	cout << endl;

	delete[] a;
	return;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	big_factorial(n);

	return 0;
}