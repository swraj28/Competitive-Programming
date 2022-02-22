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

// DFS + Backtracking :- (TLE)

class Solution {
public:

	bool recur(vector<int>& nums, int n, int si, int req, int c_sm, int k, vector<int> &visited) {

		if (k == 1) {
			return true;
		}

		if (c_sm == req) {
			return recur(nums, n, 0, req, 0, k - 1, visited);
		}

		for (int i = si; i < n; i++) {
			if (!visited[i]) {

				if ((c_sm + nums[i]) <= req) {

					visited[i] = 1;

					bool rec_res = recur(nums, n, i + 1, req, c_sm + nums[i], k, visited);

					if (rec_res == true) {
						return true;
					}

					visited[i] = 0;
				}
			}
		}

		return false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k) {

		if (k == 1) {
			return true;
		}

		int n = nums.size();

		int sm = 0;

		for (int i = 0; i < n; i++) {
			sm += nums[i];
		}

		if (sm % k) {
			return false;
		}

		int req = (sm / k);

		vector<int> visited(n, 0);

		return recur(nums, n, 0, req, 0, k, visited);
	}
};