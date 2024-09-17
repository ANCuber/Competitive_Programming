#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<vector<int> > dp(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) dp[i][j] = 1;
    int k; cin>>k;
    for (int i = 0; i < k; ++i) {
        int x, y; cin>>x>>y;
        dp[x][y] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (dp[i][j] == 0) continue;
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
