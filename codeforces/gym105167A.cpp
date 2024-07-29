#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

int n, q;
const int M = 998244353;

void dfs(int u,vector<vector<int> > &g,vector<int> &dep,int d,vector<vector<int> > &anc,vector<vector<int> > &m) {
    dep[u] = d;
    for (auto v : g[u]) {
        if (dep[v]) continue;
        anc[v][0] = u;
        m[v][0] = (int)(g[u].size()-1);
        dfs(v,g,dep,d+1,anc,m);
    }
}

int LCA(int u, int v, vector<vector<int> > &anc, vector<int> &dep) {
    if (dep[u] > dep[v]) swap(u,v);
    for (int i = __lg(n)+1; i >= 0; --i) {
        if (dep[anc[v][i]] < dep[u]) continue;
        v = anc[v][i];
    }
    if (u == v) return u;
    
    for (int i = __lg(n)+1; i >= 0; --i) {
        if (anc[u][i] == anc[v][i]) continue;
        u = anc[u][i], v = anc[v][i];
    }
    return anc[u][0];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>q;
    vector<vector<int> > g(n+2), anc(n+2,vector<int>(__lg(n)+3,0)), m(n+2,vector<int>(__lg(n)+3,0));
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dep(n+2);
    dfs(1,g,dep,1,anc,m);
    for (int i = 1; i <= __lg(n)+1; ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
            m[j][i] = m[anc[j][i-1]][i-1]*m[j][i-1]%M;
        }
    }
    while(q--) {
        int a, b; cin>>a>>b;
        int ra = a;
        if (dep[a] > dep[b]) swap(a,b);
        int lca = LCA(a,b,anc,dep);
        int cans = 1;
        for (int i = __lg(n)+1; i >= 0; --i) {
            if (dep[anc[b][i]] <= dep[lca]) continue;
            cans = cans*m[b][i]%M;
            b = anc[b][i];
        }
        //cout<<"LCA:"<<lca<<endl;
        //cout<<"Cur ans:"<<cans<<endl;
        if (a == lca) {
            cout<<cans*(int)(g[ra].size())%M<<'\n';
        } else {
            for (int i = __lg(n)+1; i >= 0; --i) {
                if (dep[anc[a][i]] <= dep[lca]) continue;
                cans = cans*m[a][i]%M;
                a = anc[a][i];
            }
            cout<<cans*(int)(g[ra].size())%M*(int)(g[lca].size()-1)%M<<'\n';
        }
    }
    return 0;
}
