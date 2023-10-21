#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int unsigned ll

const int mod = 1e9+7;

int dp[1002][12][(1<<12)+5] = {0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;    
    dp[0][m][0] = 1;
    int mx = (1<<(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < mx; ++s) dp[i][0][s<<1] += dp[i-1][m][s]%mod;
        for (int j = 1; j <= m; ++j) {
            for (int s = 0; s < mx; ++s) {
                int l = (1<<(j-1))&s, u = (1<<j)&s;
                if (!l && !u) {
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s]%mod;
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s]%mod;
                } else if (!l && u) {
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s]%mod;
                } else if (l && !u) {
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s]%mod;
                }
            }
        }
    }
    cout<<dp[n][m][0]%mod<<endl;
    return 0;
}

