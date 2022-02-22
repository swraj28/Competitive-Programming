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

// Division is nothing but repeatitive subtraction

// Brute Froce Implementation:- (Will Lead to TLE)

class Solution {
public:
	int divide(int dividend, int divisor) {

		if ((dividend == INT_MIN) && divisor == -1) {  // Handle the corner case seperately.
			return INT_MAX;
		}

		int sign = (((dividend < 0) ^ (divisor < 0)) == 0) ? +1 : -1;

		ll dividend_1 = abs(dividend);
		ll divisor_1 = abs(divisor);

		if (divisor_1 == 1) {

			ll x = INT_MAX;

			if ((dividend_1 > x) && sign == 1) {
				return INT_MAX;
			} else {
				dividend_1 *= sign;
			}

			return dividend_1;
		}

		int quotient = 0;

		while (dividend_1 >= divisor_1) {
			dividend_1 -= divisor_1;
			quotient++;
		}

		// Here whatever dividend left will be treated as remainder.

		quotient *= sign;

		return quotient;
	}
};

// Optimization:- (Bit Manipulation)

/*
		Important Point:- (a<<b)--> a*(2^b).

        Approach:- Let us devise a formulation for (58/5)

        According to Euclid's Division Algoritm--> Dividend=(Quotient*Divisor)+Remainder.

        Now (58/5)--> (11)*5+3
        		  -->58= [2^3+2^1+2^0]*5+3
        		  -->58= [(2^3)*5+(2^1)*5+(2^0)*5]+3

        		  ---> If we consider [(2^3)*5+(2^1)*5+(2^0)*5] then it is like [(5<<3)+(5<<1)+(5<<0)]

        		  --> This is something we need to implement using Bit Manipulation without using any arithmetic Operator.
*/

class Solution {
public:
	int divide(int dividend, int divisor) {

		if ((dividend == INT_MIN) && divisor == -1) {  // Handle the corner case seperately.
			return INT_MAX;
		}

		int sign = (((dividend < 0) ^ (divisor < 0)) == 0) ? +1 : -1;

		long long int a = abs(dividend);
		long long int b = abs(divisor);

		long long int quotient = 0;

		while (a >= b) {

			int q = 0;

			while (a > (b << (q + 1))) {
				q++;
			}

			quotient += (1 << q);

			a -= (b << q);
		}

		return (quotient * sign);
	}
};