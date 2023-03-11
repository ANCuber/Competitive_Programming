#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;
int n, m;

int solve(int u, int s, vector<vector<int> > &g, vector<vector<int> > &dp) {
    if (dp[u][s] >= 0) return dp[u][s];
    dp[u][s] = 0;
    for (int i = 0; i < n; ++i) {
        if (s&(1<<i) && g[i][u] && i != u) {
            dp[u][s] += solve(i,s-(1<<u),g,dp)*g[i][u]%mod;
            dp[u][s] %= mod;
        }
    }
    return dp[u][s];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector<int> > g(n+1,vector<int>(n+1,0)), dp(n+1,vector<int>((1<<n),-1));
    dp[0][1] = 1;
    while(m--) {
        int u, v; cin>>u>>v;
        u--, v--;
        g[u][v]++;
    }
    cout<<solve(n-1,(1<<n)-1,g,dp)<<endl;
    return 0;
}
