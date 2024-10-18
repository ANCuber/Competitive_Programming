#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Edge{
    int u, v, w, id;
    bool operator<(Edge y) {
        return w < y.w;
    }
};

int n, m;

struct DSU{
    vector<int> f;
    void init(int _n){
        f.assign(_n+5,0);
        for (int i = 1; i <= _n; ++i) f[i] = i;
    }
    int ff(int p) {
        if (p == f[p]) return p;
        return f[p] = ff(f[p]);
    }
    int add(int u, int v) {
        int fu = ff(u), fv = ff(v);
        if (fu == fv) return 0;
        f[fu] = fv;
        return 1;
    }
} dsu;

ll mnans = 0;

vector<vector<pair<int,int> > > MST(vector<Edge> &e, vector<int> &used) {
    vector<vector<pair<int,int> > > g(n+2);
    dsu.init(n);
    int i = 0;
    for (auto &[u,v,w,id] : e) {
        if (dsu.add(u,v)) {
            g[u].pb({v,w});
            g[v].pb({u,w});
            used[i] = 1;
            mnans += w;
        }
        i++;
    }
    return g;
}

void dfs(int f, int u, vector<vector<pair<int,int> > > &g, vector<vector<int> > &anc, vector<vector<int> > &sm, vector<int> &dep, int d) {
    dep[u] = d;
    for (auto [v,w] : g[u]) {
        if (v == f) continue;
        anc[0][v] = u;
        sm[0][v] = w;
        dfs(u,v,g,anc,sm,dep,d+1);
    }
}

int LCA(int u, int v, vector<vector<int> > &anc, vector<int> &dep, vector<vector<int> > &sm) {
    int mn = 0;
    if (dep[u] > dep[v]) swap(u,v);
    for (int i = __lg(n); i >= 0; --i) {
        if (dep[anc[i][v]] < dep[u]) continue;
        mn = max(mn,sm[i][v]);
        v = anc[i][v];
    }
    if (u == v) return mn;
    for (int i = __lg(n); i >= 0; --i) {
        if (anc[i][v] == anc[i][u]) continue;
        mn = max({mn,sm[i][u],sm[i][v]});
        v = anc[i][v], u = anc[i][u];
    }
    return max({mn,sm[0][u],sm[0][v]});
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    vector<Edge> e(m);
    for (int i = 0; i < m; ++i) {
        cin>>e[i].u>>e[i].v>>e[i].w;
        e[i].id = i;
    }
    sort(e.begin(),e.end());
    vector<int> used(m,0), dep(n+2);
    vector<vector<pair<int,int> > > g(n+2);
    g = MST(e,used);
    vector<vector<int> > anc(__lg(n)+5,vector<int>(n+2)), sm(__lg(n)+5,vector<int>(n+2));
    dfs(0,1,g,anc,sm,dep,1);
    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[i][j] = anc[i-1][anc[i-1][j]];
            sm[i][j] = max(sm[i-1][j],sm[i-1][anc[i-1][j]]);
        }
    }
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        if (used[i]) {
            ans[e[i].id] = mnans;
            continue;
        }
        ans[e[i].id] = mnans-LCA(e[i].u,e[i].v,anc,dep,sm)+e[i].w;
    }
    for (int i = 0; i < m; ++i) {
        cout<<ans[i]<<'\n';
    }
    return 0;
}
