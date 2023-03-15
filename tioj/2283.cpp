#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, c;

void Dij(vector<vector<pii> > &g) {
    vector<int> vis(n+c+2,0), d(n+c+2,1e18);
    d[1] = 0;
    p_q <pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w] : g[u]) {
            if (d[v] > d[u]+w) {
                d[v] = d[u]+w;
                pq.push({d[v],v});
            }
        }
    }
    int ans = *max_element(d.begin()+1,d.begin()+n+1);
    if (ans == 1e18) cout<<-1<<endl;
    else cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m; 
    c = n+1;
    vector<vector<pii> > g(n+m+5);
    while(m--) {
        int k, w; cin>>k>>w;
        for (int i = 1; i <= k; ++i) {
            int u; cin>>u;
            g[u].pb({c,(w/2)});
            g[c].pb({u,((w+1)/2)});
        }
        c++;
    }
    Dij(g);
    return 0;
}
