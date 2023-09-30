#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2);
    vector<int> dg(n+2,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[v].pb(u);
        dg[u]++;
    }
    
    queue<int> q;
    vector<bitset<50005> > dp(n+2);
    for (int i = 1; i <= n; ++i) {
        dp[i].reset();
        dp[i][i] = 1;
    }
    
    for (int i = 1; i <= n; ++i) if (!dg[i]) q.push(i);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto v : g[cur]) {
            dp[v] |= dp[cur];
            dg[v]--;
            if (!dg[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<dp[i].count();
    }
    cout<<endl;
    return 0;
}
