#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

int n;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    vector<vector<int> > c(n+5,vector<int>(n+5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>c[i][j];
        }
    } 
    vector<int> dp((1<<n)+5,2e18);
    dp[0] = 0;
    for (int s = 1; s < (1<<n); ++s) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(s&(1<<i)) && !(s&(1<<j))) continue;
                if ((s&(1<<i)) && (s&(1<<j))) {
                    if (i != j) dp[s] = min(dp[s^(1<<i)^(1<<j)]+min(c[i][j],c[j][i]),dp[s]);
                    else dp[s] = min(dp[s^(1<<i)]+min(c[i][j],c[j][i]),dp[s]);
                } else if (!(s&(1<<i)) && (s&(1<<j))) {
                    dp[s] = min(dp[s^(1<<j)]+min(c[i][j],c[j][i]),dp[s]);
                } else if ((s&(1<<i)) && !(s&(1<<j))) {
                    dp[s] = min(dp[s^(1<<i)]+min(c[i][j],c[j][i]),dp[s]);
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<'\n';
    return 0;
}
