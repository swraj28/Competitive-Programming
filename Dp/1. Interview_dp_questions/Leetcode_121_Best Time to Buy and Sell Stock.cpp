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

// 1.Simple Iterative Solution

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		if (prices.size() == 0) {
			return 0;
		}

		int curr_stock = prices[0];

		int max_profit = 0;

		for (int i = 1; i < prices.size(); i++) {

			if (prices[i] < curr_stock) {
				curr_stock = prices[i];

			} else if (prices[i] > curr_stock) {

				int curr_profit = prices[i] - curr_stock;
				max_profit = max(max_profit, curr_profit);
			}
		}

		return max_profit;
	}
};