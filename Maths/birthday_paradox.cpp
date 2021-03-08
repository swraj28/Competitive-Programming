// Birthday Paradox Problem
//We are assuming a non-leap year
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	float x = 1.0; //Prob of 2 People having diff Birthday
	int people = 0;

	int num = 365;
	int deno = 365;

	float p;
	cin >> p; // Threshold Probability

	// Corner Case
	if (p == 1.0) {
		cout << 366 << endl;
		return 0;
	}

	//This loop will fail on the corner case as the float is unable to handle very small numbers.

	while (x > 1 - p) {// loop terminates when x is less than threshold

		x = x * (num) / deno;
		num--;
		people++;

		cout << "People " << people << " and x " << x << endl;
	}

	return 0;
}