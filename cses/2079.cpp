#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cen = 0, n;

int Size(int u, vector<vector<int> > &g, vector<int> &sz, vector<int> &vis) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (!vis[v]) {
            sz[u] += Size(v,g,sz,vis);
        }
    }
    return sz[u];
}

void dfs(int u, int f, int c, vector<vector<int> > &g, vector<int> &sz) {
    if (cen) return;
    int sum = 0, mx = c;
    for (auto v : g[u]) {
        if (v != f) {
            mx = max(mx,sz[v]);
            sum += sz[v];
        }
    }
    if (mx <= n/2) cen = u;
    for (auto v : g[u]) {
        if (v != f) {
            dfs(v,u,c+sum+1-sz[v],g,sz);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<vector<int> > g(n+1);
    vector<int> sz(n+1,1), vis(n+1,0);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    Size(1,g,sz,vis);
    dfs(1,0,0,g,sz);
    cout<<cen<<endl;
    return 0;
}
