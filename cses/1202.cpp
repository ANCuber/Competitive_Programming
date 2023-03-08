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
    vector<vector< pii > > g(n+1);
    while(m--) {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].pb({b,c});
    }
    vector<int> dis(n+1,1e18), cnt(n+1,0), mnf(n+1,1e18), mxf(n+1,0), vis(n+1,0);
    dis[1] = 0, cnt[1] = 1, mnf[1] = 0, mxf[1] = 0;
    p_q < pii,vector<pii>,greater<pii> > pq;
    pq.push({0,1});
    while(!pq.empty()) {
        pii cur = pq.top();
        pq.pop();
        int u = cur.second, cst = cur.first;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w] : g[u]) {
            if (cst+w < dis[v]) {
                dis[v] = cst+w;
                cnt[v] = cnt[u];
                mnf[v] = mnf[u]+1;
                mxf[v] = mxf[u]+1;
            } else if (cst+w == dis[v]) {
                cnt[v] += cnt[u];
                if (cnt[v] >= mod) cnt[v] -= mod;
                mnf[v] = min(mnf[v],mnf[u]+1);
                mxf[v] = max(mxf[v],mxf[u]+1);
            } else {
                continue;
            }
            pq.push({cst+w,v});
        }
    }
    cout<<dis[n]<<' '<<cnt[n]<<' '<<mnf[n]<<' '<<mxf[n]<<endl;
    return 0;
}
