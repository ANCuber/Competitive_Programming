#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m;

struct Edge{
    int u, v, t;    
    bool operator<(Edge b) {
        return t < b.t;
    }
};

struct DSU{
    vector<int> a;
    void init(int _n) {
        a.assign(_n+5,0);
        for (int i = 1; i <= _n; ++i) a[i] = i;
    }
    int find(int p) {
        if (p == a[p]) return p;
        return a[p] = find(a[p]);
    }
    int add(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return 0;
        a[fu] = fv;
        return 1;
    }
} dsu;

void FindMST(vector<vector<pii> > &g,vector<Edge> &e) {
    dsu.init(n);
    for (auto [u,v,w] : e) {
        if (dsu.add(u,v)) {
            g[u].pb({v,w});
            g[v].pb({u,w});
        }
    }
}

void dfs(int u,int d,int f,vector<vector< pii > > &g,vector<vector<int> > &anc,vector<vector<int> > &mx,vector<int> &dep) {
    dep[u] = d;
    for (auto [v,w] : g[u]) {
        if (v != f) {
            anc[v][0] = u;
            mx[v][0] = w;
            dfs(v,d+1,u,g,anc,mx,dep);
        }
    }
}

int LCA(int u, int v, vector<vector<int> > &anc, vector<int> &dep) {
    if (dep[u] > dep[v]) swap(u,v);
    int d = dep[v]-dep[u], b = 0;
    while(d) {
        if (d&1) v = anc[v][b];
        b++;
        d >>= 1;
    }
    if (u == v) return u;
    for (int i = __lg(n)+1;i >= 0; --i) {
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    }
    return anc[u][0];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<Edge> e(m);
    for (auto& [u,v,t] : e) cin>>u>>v>>t;
    sort(e.begin(),e.end());
    vector<vector<pii> > g(n+1);
    vector<vector<int> > anc(n+1,vector<int>(__lg(n)+5,0)), mx(n+1,vector<int>(__lg(n)+5,0));
    vector<int> dep(n+1,0);
    FindMST(g,e);
    for (int i = 1; i <= n; ++i) {
        if (dep[i]) continue;
        dfs(i,1,0,g,anc,mx,dep);
    }
    for (int i = 1; i <= __lg(n)+1; ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
            mx[j][i] = max(mx[j][i-1],mx[anc[j][i-1]][i-1]);
        }
    }
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        if (u == v) {
            cout<<0<<endl;
            continue;
        }
        if (dsu.find(u) != dsu.find(v)) {
            cout<<-1<<endl;
            continue;
        }
        int d = dep[LCA(u,v,anc,dep)];
        int x = dep[u]-d, y = dep[v]-d;
        int cmx = 0, b = 0;
        while(x) {
            if (x&1) {
                cmx = max(cmx,mx[u][b]);
                u = anc[u][b];
            }
            b++;
            x >>= 1;
        }
        b = 0;
        while(y) {
            if (y&1) {
                cmx = max(cmx,mx[v][b]);
                v = anc[v][b];
            }
            b++;
            y >>= 1;
        }
        cout<<cmx<<endl;
    }
    return 0;
}
