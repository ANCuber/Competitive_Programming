#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mod = 1e9+7;

void Dij(int S, vector<vector<pii> > &g, vector<int> &D, vector<int> &C) {
    D[S] = 0;
    C[S] = 1;
    bitset<100005> vis;
    vis.reset();
    p_q<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,S});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto [v,w] : g[cur]) {
            if (D[v] > D[cur]+w) {
                D[v] = D[cur]+w;
                C[v] = C[cur];
                pq.push({D[v],v});
            } else if (D[v] == D[cur]+w) {
                C[v] = (C[v]+C[cur])%mod;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q, s, t;    
    cin>>n>>m>>q>>s>>t;
    vector<int> ask(q);
    for (int i = 0; i < q; ++i) cin>>ask[i];
    vector<vector<pii> > g(n+2);
    while(m--) {
        int u, v, c; cin>>u>>v>>c;
        g[u].pb({v,c});
        g[v].pb({u,c});
    }
    vector<int> sd(n+2,1e18), sc(n+2,0), td(n+2,1e18), tc(n+2,0);
    Dij(s,g,sd,sc), Dij(t,g,td,tc);
    for (auto i : ask) cout<<sd[i]+td[i]<<' '<<sc[i]*tc[i]%mod<<endl;
    return 0;
}
