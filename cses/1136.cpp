#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
const int MXN = 2e5+5;

vector<int> wsn(MXN,0), dep(MXN,0), sz(MXN,1), tp(MXN), dfn(MXN,0), prt(MXN,0);
int ord = 0;

struct BIT{
    vector<int> a;
    int s;
    void init(int _n) {
        a.assign(_n+5,0);
        s = _n;
    }
    void mdf(int p, int v) {
        while(p <= s) {
           a[p] += v;
           p += p&-p;
        }
    }
    int val(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

void dfs(int u, int f, int d, vector<vector<int> > &g) {
    dep[u] = d;
    prt[u] = f;
    int mx = 0, cs = 0;
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs(v,u,d+1,g);
        sz[u] += sz[v];
        if (mx < sz[v]) {
            mx = sz[v];
            cs = v;
        }
    }
    wsn[u] = cs;
}

void dec(int u, int f, int ctp ,vector<vector<int> > &g) {
    tp[u] = ctp;
    dfn[u] = ++ord;
    if (wsn[u]) dec(wsn[u],u,ctp,g);
    for (auto v : g[u]) {
        if (v == f || v == wsn[u]) continue;
        dec(v,u,v,g);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    bit.init(n+2);
    vector<vector<int> > g(n+2);
    iota(tp.begin(),tp.end(),0);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,1,1,g);
    dec(1,1,1,g);
    
    while(m--) {
        int x, y; cin>>x>>y;
        int tx = x, ty = y;
        
        while(tp[x] != tp[y]) {
            if (dep[tp[x]] > dep[tp[y]]) swap(x,y);
            y = prt[tp[y]];
        }
        if (dep[x] > dep[y]) swap(x,y);//LCA = x;
        
        while(1) {
            if (tp[tx] == tp[x]) {
                bit.mdf(dfn[x],1);
                bit.mdf(dfn[tx]+1,-1);
                break;
            } else {
                bit.mdf(dfn[tp[tx]],1);
                bit.mdf(dfn[tx]+1,-1);
                tx = prt[tp[tx]];
            }
        }
        while(1) {
            if (tp[ty] == tp[x]) {
                bit.mdf(dfn[x],1);
                bit.mdf(dfn[ty]+1,-1);
                break;
            } else {
                bit.mdf(dfn[tp[ty]],1);
                bit.mdf(dfn[ty]+1,-1);
                ty = prt[tp[ty]];
            }
        }
        bit.mdf(dfn[x],-1);
        bit.mdf(dfn[x]+1,1);
    }
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<bit.val(dfn[i]);
    }
    cout<<endl;
    return 0;
}
