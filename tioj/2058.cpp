#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void solve() {
    int n, m; cin>>n>>m;
    int st, ed; cin>>st>>ed;
    st++, ed++;
    vector<vector< pii > > g(n+1);
    while(m--) {
        int u, v, w;
        cin>>u>>v>>w;
        g[++u].pb({++v,w});
    }
    p_q < pii,vector< pii >,greater< pii > > pq;
    pq.push({0,st});
    vector< vector<int> > d(n+1,vector<int>(2,3e18));
    while(!pq.empty()) {
        int u = pq.top().second, dis = pq.top().first;
        pq.pop();
        if (dis < d[u][0]) {
            d[u][1] = d[u][0];
            d[u][0] = dis;
        } else if (dis < d[u][1] && dis != d[u][0]) {
            d[u][1] = dis;
        } else continue;
        for (auto [v,w] : g[u]) {
            pq.push({w+dis,v});
        }
    }
    //cout<<d[ed][1]<<' '<<d[ed][0]<<endl;
    cout<<d[ed][1]-d[ed][0]<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) solve();
    return 0;
}
