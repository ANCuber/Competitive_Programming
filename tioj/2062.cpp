#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int flag = 0;

void dfs(int u, vector<vector<int> > &g, vector<int> &vis, int c) {
    vis[u] = c;
    for (auto v : g[u]) {
        if (!vis[v]) {
            dfs(v,g,vis,3-c);
        } else if (vis[v] == c) {
            flag = 1;
        }
    }
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> vis(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i,g,vis,1);
    }
    if (flag) {
        cout<<-1<<endl;
    } else {
        vector<int> s, t;
        for (int i = 1; i <= n; ++i) {
            if (vis[i] == 1) s.pb(i);
            else t.pb(i);
        }
        cout<<s.size()<<' '<<t.size()<<endl;
        for (int i = 0; i < s.size(); ++i) {
            if (i) cout<<' ';
            cout<<s[i];
        }
        cout<<endl;
        for (int i = 0; i < t.size(); ++i) {
            if (i) cout<<' ';
            cout<<t[i];
        }
        cout<<endl;
    }
    
    return 0;
}
