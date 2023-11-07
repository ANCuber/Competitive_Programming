#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int ca, n;

pii dfs1(int u, int f, vector<vector<int> > &g, vector<int> &a, vector<int> &sz) {
    sz[u] = 1;
    pii ret = {0,a[u]};//cost, val
    for (auto v : g[u]) {
        if (v == f) continue;
        pii cur = dfs1(v,u,g,a,sz);
        ret.first += cur.first+(cur.second^a[u])*sz[v];
        sz[u] += sz[v];
    }
    return ret;
}

void dfs2(int u, int f, int cur, vector<vector<int> > &g, vector<int> &a, vector<int> & sz, vector<int> &ans) {
    ans[u] = cur;
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs2(v,u,cur+(a[u]^a[v])*(n-sz[v])-(a[u]^a[v])*sz[v],g,a,sz,ans);
    }
} 

void Run() {
    cin>>n;
    vector<int> a(n+2), sz(n+2), ans(n+2);
    vector<vector<int> > g(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ca = dfs1(1,0,g,a,sz).first;
    dfs2(1,0,ca,g,a,sz,ans);
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
