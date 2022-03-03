/*
Prateek went to purchase fruits mainly apples, mangoes and oranges. There are N different fruit sellers in a line.
Each fruit seller sells all three fruit items, but at different prices.
Prateek, obsessed by his nature to spend optimally, decided not to purchase same fruit from adjacent shops.
Also, Prateek will purchase exactly one type of fruit item (only 1kg) from one shop.
Prateek wishes to spend minimum money buying fruits using this strategy. Help Prateek determine the minimum money he will spend.
If he becomes happy, he may offer you discount on your favorite course in Coding Blocks ;). All the best!

Input Format
First line indicates number of test cases T. Each test case in its first line contains N denoting the number of fruit sellers in Fruit Market.
Then each of next N lines contains three space separated integers denoting cost of apples, mangoes and oranges per kg with that particular fruit seller.

Constraints
1 ≤ T ≤ 10 1 ≤ N ≤ 10^5 Cost of each fruit(apples/mangoes/oranges) per kg does not exceed 10^4

Output Format
For each test case, output the minimum cost of shopping taking the mentioned conditions into account in a separate line.

Sample Input
1
3
1 50 50
50 50 50
1 50 50
Sample Output
52
Explanation
There are two ways, each one gives 52 as minimum cost. One way is buy apples from first shop, mangoes from second shop and apples from third shop or he can buy apples from first shop, oranges from second shop and apples from third shop.

Both ways , cost comes up to 1 + 50 + 1 = 52

*/

// Similara Question is Paint House (Leetcode).

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

class Solution {
public:
	int dp[100005][3];

	int recur(vector<vector<int>> &v, int n , int si, int last) {
		if (si >= n) {
			return 0;
		}

		if (dp[si][last] != -1) {
			return dp[si][last];
		}

		int ans = INT_MAX;

		for (int i = 0; i < 3; i++) {
			if (i == last) {
				continue;
			}

			int rec_res = v[si][i] + recur(v, n, si + 1, i);

			ans = min(ans, rec_res);
		}

		return dp[si][last] = ans;
	}

	int solve(vector<vector<int> > &A) {

		int n = A.size();

		if (n == 0) {
			return 0;
		}

		int ans = INT_MAX;

		ms(dp, -1);

		for (int i = 0; i < 3; i++) {
			ans = min({ans, recur(A, n, 1, i) + A[0][i]});
		}

		return ans;
	}

	int minCost(vector<vector<int>> &costs) {

		return solve(costs);
	}
};
