#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> d(n+1,0), dp(n+1,0);
    dp[1] = 1;
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        d[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!d[i]) q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            d[v]--;
            dp[v] += dp[u];
            dp[v] %= mod;
            if (!d[v]) {
                q.push(v);
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
