#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, ans = 1e18, nw;

int DP(int u, int s, vector<vector<int> > &dp, vector<vector<int> > &g, int cnt) {
    //if (cnt == n) return g[u][nw];
    if (cnt == n) return dp[u][s];
    if (dp[u][s] != 1e18) return dp[u][s];
    for (int i = 0; i < n; ++i) {
        if (i == u || (s&(1<<i)) == 0) continue;
        //cout<<(s&(1<<u))<<endl;
        dp[u][s] = min(dp[u][s],DP(i,s-(1<<u),dp,g,cnt+1)+g[u][i]);
    }
    return dp[u][s];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<vector<int> > g(n+2,vector<int>(n+2,0));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>g[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        nw = i;
        vector<vector<int> > dp(n+2,vector<int>(1<<n,1e18));
        for (int j = 0; j < n; ++j) dp[j][1<<j] = g[j][i];
        ans = min(ans,DP(i,(1<<n)-1,dp,g,1));
    }
    cout<<ans<<endl;
    return 0;
}
