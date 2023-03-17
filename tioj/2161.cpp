#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct TREE{
    vector<int> prt, cst, dep;
    vector<vector<pii> > g;
    void init(int _n) {
        g.resize(_n+2);
        dep.assign(_n+2,0);
        prt.assign(_n+2,0);
        cst.assign(_n+2,0);
        prt[1] = 1, cst[1] = 0;
    }
    void addedge(int u, int v, int w) {
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    void dfs(int u, int f, int d) {
        dep[u] = d;
        for (auto [v,w] : g[u]) {
            if (v != f) {
                prt[v] = u;
                cst[v] = w;
                dfs(v,u,d+1);
            }
        }
    }
    int query(int u, int v) {
        int sum = 0;
        stack<int,vector<int>> stk;
        while(u != v) {
            if (dep[u] > dep[v]) swap(u,v);
            stk.push(v);
            sum += cst[v];
            v = prt[v];
        }
        int ca = u;
        while(!stk.empty()) {
            prt[stk.top()] = ca;
            cst[stk.top()] = 0;
            stk.pop();
        }
        return sum;
    }
} tr;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    tr.init(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin>>u>>v>>w;
        tr.addedge(u,v,w);
    }
    tr.dfs(1,0,1);
    while(q--) {
        int u, v; cin>>u>>v;
        cout<<tr.query(u,v)<<endl;
    }
    return 0;
}
