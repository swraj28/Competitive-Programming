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
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ncr(numRows, vector<int>(numRows));

        ncr[0][0] = 1;

        for (int n = 1; n < numRows; n++) {
            ncr[n][0] = 1;
            for (int r = 1; r < n; r++) {
                ncr[n][r] = ncr[n - 1][r - 1] + ncr[n - 1][r];
            }
            ncr[n][n] = 1;
        }

        vector<vector<int>> ans;

        vector<int> v;

        for (int i = 0; i < numRows; i++) {
            v.clear();
            for (int j = 0; j <= i; j++) {
                v.push_back(ncr[i][j]);
            }
            ans.push_back(v);
        }

        return ans;
    }
};