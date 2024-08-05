#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n;
vector<int> fff(200005,0);

void dfs(int f, int u, int dep, vector<vector<int> > &g, vector<vector<int> > &anc,vector<int> &d) {
    anc[u][0] = f;
    d[u] = dep;
    int cld = 0;
    for (auto v : g[u]) {
        if (v == f) continue;
        cld++;
        dfs(u,v,dep+1,g,anc,d);
    }
    if (!cld) fff[u] = 1;
}

int LCA(int u, int v, vector<vector<int> > &anc, vector<int> &d) {
    if (d[u] > d[v]) swap(u,v);
    for (int i = __lg(n); i >= 0; --i) {
        if (d[anc[v][i]] < d[u]) continue;
        v = anc[v][i];
    }
    if (u == v) return u;
    for (int i = __lg(n); i >= 0; --i) {
        if (anc[v][i] == anc[u][i]) continue;
        u = anc[u][i];
        v = anc[v][i];
    }
    return anc[u][0];
}

int nw = 0;

void dfs2(int f, int u, vector<vector<int> > &g, vector<int> &tg, vector<int> &cnt) {
    nw += tg[u];
    cnt[u] = nw;
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs2(u,v,g,tg,cnt);
    }
    nw -= tg[u];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    vector<vector<int> > g(n+2), anc(n+2,vector<int>(__lg(n)+5));
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> d(n+2,0), tg(n+2,0);
    dfs(0,1,1,g,anc,d);
    for (int i = 1; i <= __lg(n); ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    
    int cond = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x;
        if (!x) continue;
        cond++;
        int lca = LCA(i,x,anc,d);
        //cout<<i<<' '<<x<<"->"<<lca<<endl; 
        int tmp = i;
        for (int j = __lg(n); j >= 0; --j) {
            if (d[anc[tmp][j]] <= d[x]) continue;
            tmp = anc[tmp][j];
        }
        if (x != lca) {
            tg[x]++;
        } else {
            tg[tmp]--;
            //cout<<"TMP:"<<tmp<<endl;
            tg[1]++;
        }
    }
    vector<int> cnt(n+2,0), ans;
    dfs2(0,1,g,tg,cnt);
    for (int i = 1;i  <= n; ++i) {
        if (cnt[i] == cond && fff[i]) ans.pb(i);
    }
    cout<<ans.size()<<'\n';
    for (int i =0 ; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    cout<<'\n';
    return 0;
}
