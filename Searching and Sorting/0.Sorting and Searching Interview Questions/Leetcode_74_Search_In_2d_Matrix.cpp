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

// Hint :- Don't treat it as a sorted matrix, just treat it as a sorted list . So we can apply binary search in o(logn);

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {

		int n = matrix.size(), m = matrix[0].size();

		int st = 0, end = (n * m) - 1;

		while (st <= end) {

			int mid = (st + (end - st) / 2);

			int row = (mid / m);
			int col = (mid % m);

			if (matrix[row][col] == target) {
				return true;
			}

			if (matrix[row][col] < target) {
				st = mid + 1;
			} else {
				end = mid - 1;
			}
		}

		return false;
	}
};