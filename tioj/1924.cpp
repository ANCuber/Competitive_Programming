#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b, c; cin>>n;    
    int dp[2][3][10];
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 8; ++j) dp[0][i][j] = dp[1][i][j] = -1e9;
    dp[0][0][1] = dp[0][1][2] = dp[0][2][4] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) for (int k = 0; k < 8; ++k) dp[i&1][j][k] = -1e9;
        char x; cin>>x;
        if (x == 'P') a = 0, b = 1, c = 2;
        else if (x == 'E') a = 1, b = 0, c = 2;
        else a = 2, b = 0, c = 1;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 8; ++k) {
                if (j == a && (k&(1<<j))) {
                    dp[i&1][j][k] = max({dp[i&1^1][j][k],dp[i&1^1][c][k^(1<<j)],dp[i&1^1][b][k^(1<<j)]})+1;
                } else {
                    dp[i&1][j][k] = dp[i&1^1][j][k];
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j < 8; ++j) {
            ans = max(dp[n&1][i][j],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}

