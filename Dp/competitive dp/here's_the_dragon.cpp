#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll r, c, k, d;
vector<pair<ll, ll>> v;
//Max size of k and d is 300
//We have created a 3d dp as we have 3 variating parameters
ll dp[305][305][305];

ll min_step(int k, int last, int now) {
    if (k == 0) {
        return 0;
    }
    // if d gets zero before k then we cannot make any solution.return (INT_MAX);
    if (now > d) {
        return INT_MAX;
    }
    if (dp[k][last][now] != -1) {
        return dp[k][last][now];
    }
    ll t_d = abs(v[now].first - v[last].first) + abs(v[now].second - v[last].second);

    return dp[k][last][now] = min(t_d + min_step(k - 1, now, now + 1), min_step(k, last, now + 1));
}

int main() {

    cin >> r >> c >> k >> d;
    v.push_back(make_pair(0, 0));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < d; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    cout << min_step(k, 0, 1) << endl;


    return 0;
}