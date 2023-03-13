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
    int u, v, w;
    bool operator<(Edge b) {
        return w < b.w;
    }
};

struct DSU{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+2,0);
        for (int i = 1; i <= _n; ++i) a[i] = i;
    }
    int find(int p) {
        if (a[p] == p) return p;
        return a[p] = find(a[p]);
    }
    bool add(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return 0;
        a[fu] = fv;
        sz--;
        return 1;
    }
} dsu;

int FindMST(vector<vector<pii> > &g, vector<Edge> &nt) {
    vector<Edge> e(m);
    for (auto& [u,v,w] : e) cin>>u>>v>>w;
    sort(e.begin(),e.end());
    int ans = 0;
    dsu.init(m);
    for (auto [u,v,w] : e) {
        if (dsu.add(u,v)) {
            g[u].pb({v,w});
            g[v].pb({u,w});
            ans += w;
        } else if (u != v) {
            nt.pb({u,v,w});
        }
    }
    return ans;
}

void dfs(int u,int f,int d,vector<vector<pii> > &g,vector<vector<int> > &anc,vector<int> &dep,
vector<vector<int> > &mx) {
    anc[u][0] = f;
    dep[u] = d; 
    for (auto [v,w] : g[u]) {
        if (v != f) {
            mx[v][0] = w;
            dfs(v,u,d+1,g,anc,dep,mx);
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
    for (int i = __lg(n)+1; i >= 0; --i) {
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
    vector<vector<pii> > g(n+1);
    vector<Edge> nt;
    int fst = FindMST(g,nt);
    if (dsu.sz > 1) {
        cout<<-1<<' '<<-1<<endl;
        return 0;
    }
    vector<vector<int> > anc(n+1,vector<int>(__lg(n)+3,0)), mx(n+1,vector<int>(__lg(n)+3,0));
    vector<int> dep(n+1);
    dfs(1,0,1,g,anc,dep,mx);
    for (int i = 1; i <= __lg(n)+1; ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
            mx[j][i] = max(mx[j][i-1],mx[anc[j][i-1]][i-1]);
        }
    }
    int ans = 1e18;
    for (auto [u,v,w] : nt) {
        int da = dep[LCA(u,v,anc,dep)];
        int du = dep[u]-da, dv = dep[v]-da;
        int mxu = 0, mxv = 0, b = 0;
        while(du) {
            if (du&1) {
                mxu = max(mxu,mx[u][b]);
                u = anc[u][b];
            }
            b++;
            du >>= 1;
        }
        b = 0;
        while(dv) {
            if (dv&1) {
                mxv = max(mxv,mx[v][b]);
                v = anc[v][b];
            }
            b++;
            dv >>= 1;
        }
        mxu = max(mxu,mxv);
        ans = min(ans,fst-mxu+w);
    }
    if (ans == 1e18) {
        cout<<fst<<' '<<-1<<endl;
    } else {
        cout<<fst<<' '<<ans<<endl;
    }
    return 0;
}
