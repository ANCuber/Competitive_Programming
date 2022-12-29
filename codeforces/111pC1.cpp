#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, vector<vector<int> > &g, vector<int> &vis) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v,g,vis);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int V, E; cin>>V>>E;    
    vector<vector<int> > g(V+1);
    while(E--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    string ans;
    vector<int> vis(V+1,0);
    int cnt = 0;
    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            dfs(i,g,vis);
            cnt++;
        }
    }
    if (cnt == 1) ans = "No";
    else ans = "Yes";
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        cout<<ans<<endl;
    }
    return 0;
}
