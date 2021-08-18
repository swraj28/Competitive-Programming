#include<bits/stdc++.h>
using namespace std;
#define ll long long

//1.To check whether a no is odd or even

void check(int n) {
	if (n & 1) {
		cout << "The Given Number Is Odd" << endl;
	} else {
		//(n&1==0)->even case
		cout << "The Given Number Is Even" << endl;
	}
}

//2.To Find the Ith bit of a number from LSB

void Ith_bit_LSB(int n, int i) {

	// We will create a mask and do the and
	int mask = (1 << i);
	int res = (n & mask);

	if (res > 0) {
		cout << "The Bit at the Ith Position Is " << 1 << endl;
	} else {
		cout << " The Bit at the Ith Position Is " << 0 << endl;
	}
}

//3.Set a Particular Bit (i.e, To make a particular Bit Equals to 1)

int set_bit(int n, int i) {

	int mask = (1 << i);
	int res = (n or mask);

	return res;
}

// 4. Clear a Particular Bit from Ith position from a given number.

void clear_bit(int &n, int i) {

	int mask = (1 << i);
	int actual_mask = (~mask);

	n = (n & actual_mask);
}

// 5.Upadate a particular bit by v{0,1};

void Update_bit(int &n, int i, int v) {

	//First step is to clear the bit at ith position
	clear_bit(n, i);
	int mask = (v << i);

	n = (n or mask);
}

// 6.Clear last i bits of a number from LSB
int clear_last_i_bit(int n, int i) {

	int mask = (~0);
	int actual_mask = (mask << i);

	return (n & actual_mask);
}

// 7. clear a range of bit from i to j

int clear_range_i_to_j(int n, int i, int j) {

	int mask_a = (~0) << (j + 1);
	int mask_b = (1 << i) - 1;

	int actual_mask = (mask_a | mask_b);

	return (n & actual_mask);
}

// 8. Biggest power of 2 that is a divisor of n

void biggest_power(int n) {

	if (n & 1) {
		cout << "n is not divisble by any power of 2" << endl;
		return;
	}

	int ans = 1;

	while (n > 0) {

		if (n & 1) {
			break;
		}
		ans *= 2;
		n >>= 1;
	}

	cout << ans << endl;
}

// 9. Smallest Power of 2 that is not smaller than n;

void smallest_power(int n) {

	int no_of_bits = (int)log2(n) + 1;

	cout << pow(2, no_of_bits) << endl;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);



	return 0;
}