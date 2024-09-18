#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<tuple<int,int,int> > > g(n+2);
    for (int i = 1; i <= m; ++i) {
        int u, v, c, p;
        cin>>u>>v>>c>>p;
        g[u].pb({v,c,p});
        g[v].pb({u,c,p});
    }
    for (int i = 1; i <= n; ++i) {
        map<int,int> sm;
        for (auto& [v,c,p] : g[i]) sm[c] += p;
        for (auto& [v,c,p] : g[i]) p = min(p,sm[c]-p);
    }
    p_q <pii,vector<pii>,greater<pii>> pq;
    vector<int> dis(n+2,2e18), vis(n+2,0);
    dis[1] = 0;
    pq.push({0,1});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto& [v,c,p] : g[cur]) {
            if (dis[cur]+p < dis[v]) {
                dis[v] = dis[cur]+p;
                pq.push({dis[v],v});
            }
        }
    }
    if (dis[n] >= 1e18) cout<<-1<<endl;
    else cout<<dis[n]<<endl;
    return 0;
}
