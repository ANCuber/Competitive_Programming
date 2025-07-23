#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 5), b(m + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    vector<vector<int> > dp(2, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) dp[i & 1][j] = dp[i & 1 ^ 1][j - 1] + 1;
            else dp[i & 1][j] = dp[i & 1 ^ 1][j - 1];
            dp[i & 1][j] = max({dp[i & 1][j], dp[i & 1 ^ 1][j], dp[i & 1][j - 1]});
            
        }
    }
    cout << dp[n & 1][m] << "\n";
    vector<int> ans;
    return 0;
}
