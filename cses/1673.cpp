#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
 
int n, m;
 
int SPFA(vector<vector< pii > > &g) {
    vector<int> d(n+1,1e18);
    d[1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto [v,w] : g[j]) {
                if (d[v] > d[j]+w) {
                    d[v] = d[j]+w;
                }
            }
        }
    }
    return d[n];
}
 
void check(vector<vector< pii > > &g, vector<int> &is) {
    vector<int> d(n+1,1e18);
    d[1] = 0;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (auto [v,w] : g[j]) {
                if (d[v] > d[j]+w) {
                    d[v] = d[j]+w;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (auto [v,w] : g[i]) {
            if (d[v] > d[i]+w) {
                is[v] = 1;
            }
        }
    }
}

bool dfs(int u, vector<int> &is, vector<vector<int> > &g, vector<int> &vis) {
    vis[u] = 1;
    int mx = 0;
    for (auto v : g[u]) {
        if (vis[v]) continue;
        mx |= dfs(v,is,g,vis);
    }
    return mx|is[u];
}

void chdfs(int u, vector<int> &vis, vector<vector< pii > > &g) {
    vis[u] = 1;
    for (auto [v,w] : g[u]) {
        if (vis[v]) continue;
        chdfs(v,vis,g);
    }
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<vector< pii > > g(n+2);
    vector<vector<int> > bg(n+2);
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        g[u].pb({v,-w});
        bg[v].pb(u);
    }
    vector<int> is(n+1,0), vis(n+1,0), cv(n+1,0);
    check(g,is);
    chdfs(1,cv,g);
    for (int i = 1; i <= n; ++i) is[i] &= cv[i];
    if (dfs(n,is,bg,vis)) cout<<-1<<endl;
    else cout<<SPFA(g)*-1<<endl;
    return 0;
}
