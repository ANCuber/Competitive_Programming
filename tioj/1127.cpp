#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 41;
const int m = 3;
const int mx = (1<<(m+1));

ll dp[maxn+2][m+2][(1<<(m+2))+5] = {0};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    dp[0][m][0] = 1;
    for (int i = 1; i <= maxn; ++i) {
        for (int s = 0; s < mx; ++s) dp[i][0][s<<1] += dp[i-1][m][s];
        for (int j = 1; j <= m; ++j) {
            for (int s = 0; s < mx; ++s) {
                int l = s&(1<<(j-1)), u = s&(1<<j);
                if (!l && !u) {
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s];
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s];
                } else if (!l && u) {
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s];
                } else if (l && !u) {
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s];
                }
            }
        }
    }
    int n;
    while(cin>>n) cout<<dp[n][m-1][0]<<endl;
    
    return 0;
}

