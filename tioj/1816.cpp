#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define SUM (g[i][j]-g[i-k][j]-g[i][j-k]+g[i-k][j-k])

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, k;
    cin>>m>>n>>k;
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    vector<vector<int> > dp1(m+2,vector<int>(n+2,-2e18));
    vector<vector<int> > dp2(m+2,vector<int>(n+2,-2e18));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>g[i][j];
            g[i][j] += g[i][j-1];
        }
        for (int j = 1; j <= n; ++j) g[i][j] += g[i-1][j];
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j < k || i < k) continue;
            else dp1[i][j] = max({dp1[i-1][j],dp1[i][j-1],SUM});
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (j < 2*k || i < 2*k) continue;
            else dp2[i][j] = SUM+max(dp1[i-k][j],dp1[i][j-k]);
        }
        for (int j = 1; j <= n; ++j) {
            dp2[i][j] = max({dp2[i][j],dp2[i-1][j],dp2[i][j-1]});
        }
    }
    int ans = -2e18;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i < k || j < k) continue;
            dp1[i][j] = SUM+max(dp2[i-k][j],dp2[i][j-k]);
            ans = max(ans,dp1[i][j]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
