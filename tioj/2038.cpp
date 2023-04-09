#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct DSU{
    vector<int> sz, a;
    int mxsz = 1;
    void init(int _n) {
        a.assign(_n+2,0);
        sz.assign(_n+2,1);
        for (int i = 1; i <= _n; ++i) a[i] = i;
    }
    int find(int p) {
        if (p == a[p]) return p;
        return a[p] = find(a[p]);
    }
    bool add(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return 0;
        a[fu] = fv;
        sz[fv] += sz[fu];
        mxsz = max(mxsz,sz[fv]);
        return 1;
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2);
    vector<vector<pii> > adding(n+2);
    vector<int> dg(n+2,0),  del(n+2,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
        dg[u]++, dg[v]++;
    }
    set<pii> s;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!del[j] && dg[j] <= i) {
                del[j] = 1;
                q.push(j);
            }
        }
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto v : g[cur]) {
                dg[v]--;
                adding[i].pb({cur,v});
                if (!del[v] && dg[v] <= i) {
                    del[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    dsu.init(n);
    fill(dg.begin(),dg.end(),0);
    int ans = 0;
    for (int i = n; i > 0; --i) {
        if (!adding[i].size()) continue;
        for (auto [u,v] : adding[i]) {
            dsu.add(u,v);
            dg[u]++, dg[v]++;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}
