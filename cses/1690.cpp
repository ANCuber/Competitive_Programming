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
    if (!(s&1)) return 0;
    if (dp[u][s] >= 0) return dp[u][s];
    dp[u][s] = 0;
    for (auto v : g[u]) {
        if (s&(1<<v) && v != u) {
            dp[u][s] += solve(v,s-(1<<u),g,dp);
            dp[u][s] %= mod;
        }
    }
    return dp[u][s];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    scanf("%lld%lld",&n,&m);
    vector<vector<int> > g(n+1), dp(n+1,vector<int>((1<<n),-1));
    dp[0][1] = 1;
    while(m--) {
        int u, v;
        scanf("%lld%lld",&u,&v);
        u--, v--;
        g[v].pb(u);
    }
    printf("%lld\n",solve(n-1,(1<<n)-1,g,dp));
    return 0;
}
