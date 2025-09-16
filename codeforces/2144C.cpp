#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 998244353;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 3), b(n + 3);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    vector<vector<ll> > dp(2, vector<ll> (n + 3, 0));
    dp[0][1] = dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] >= a[i - 1] && b[i] >= b[i - 1]) {
            dp[0][i] += dp[0][i - 1];
            dp[1][i] += dp[1][i - 1];
        }
        if (a[i] >= b[i - 1] && b[i] >= a[i - 1]) {
            dp[0][i] += dp[1][i - 1];
            dp[1][i] += dp[0][i - 1];
        }
        dp[0][i] %= M, dp[1][i] %= M;
    }
    cout << (dp[0][n] + dp[1][n]) % M << "\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}
