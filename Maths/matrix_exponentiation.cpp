//SEQ->SPOJ
#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define mod 1000000000

ll k;
vector<ll> a, b, c;

vector<vector<ll>> multiply(vector<vector<ll>> A, vector<vector<ll>> B) {

	//Lets store the result in some marix C
	vector<vector<ll>> C(k + 1, vector<ll>(k + 1));


	//Logic to multiply matrices

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			for (int x = 1; x <= k; x++) {
				C[i][j] = (C[i][j] + (A[i][x] * B[x][j]) % mod) % mod;
			}
		}
	}

	return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll p) {

	//Base Case
	if (p == 1) {
		return A;
	}

	//Power is odd
	if (p & 1) {
		return multiply(A, power(A, p - 1));
	}

	vector<vector<ll>> X = power(A, p / 2);

	return multiply(X, X);
}

ll compute(ll n) {

	//base case
	if (n == 0) {
		return 0;
	}

	if (n <= k) {
		return b[n - 1];
	}

	// Otherwise Use Matrix Exponentiation
	vector<ll> F1(k + 1);
	//indexing From 1

	// Step 1
	for (int i = 1; i <= k; i++) {
		F1[i] = b[i - 1];
	}

	//Step-2 Transformation Matrix

	vector<vector<ll>> T(k + 1, vector<ll>(k + 1)); //1 based Indexing

	//Generalized Formulae
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i < k) {
				//fill 0s and 1s
				if (j == i + 1) {
					T[i][j] = 1;
				} else {
					T[i][j] = 0;
				}
			} else {
				T[i][j] = c[k - j];
			}
		}
	}

	//3.step

	T = power(T, n - 1);

	//4.step-Multiply Matrix With a Vector

	//Computing the nth term by mutiplying first element of the
	//vector to the first row of the matrix.
	ll res = 0;
	for (int i = 1; i <= k; i++) {
		res = ((res + T[1][i] * F1[i]) % mod) % mod;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t, n, num;
	cin >> t;
	while (t--) {
		cin >> k;

		//f0,f1,f2,f3,f(k-1) terms
		for (int i = 0; i < k; i++) {
			cin >> num;
			b.push_back(num);
		}

		//Coeff
		for (int i = 0; i < k; i++) {
			cin >> num;
			c.push_back(num);
		}

		cin >> n;

		cout << compute(n) << endl;

		b.clear();
		c.clear();

	}

	return 0;
}