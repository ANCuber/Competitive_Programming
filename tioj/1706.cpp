#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, a, b, d;

struct Edge{
    int to, c, p;
};

int dij(int s, int t, int k, vector<vector<Edge> > &g) {
    vector<int> d(n+2,1e18), vis(n+2,0);
    d[s] = 0;
    p_q <pii,vector<pii>,greater<pii> > pq;
    pq.push({0,s});
    while(!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();
        if (vis[cur]) continue;
        vis[cur] = 1;
        for (auto [v,c,p] : g[cur]) {
            if (d[v] > d[cur]+c+p*k) {
                d[v] = d[cur]+c+p*k;
                pq.push({d[v],v});
            }
        }
    }
    return d[t];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m>>a>>b>>d;    
    int u, v, c1, p1, c2, p2;
    vector<vector<Edge> > g(n+2);
    while(m--) {
        cin>>u>>v>>c1>>p1>>c2>>p2;
        g[u].pb({v,c1,p1});
        g[v].pb({u,c2,p2});
    }
    cout<<min(dij(a,b,0,g)+dij(b,a,0,g),dij(a,b,d-1,g)+dij(b,a,d-1,g))<<endl;
    return 0;
}
