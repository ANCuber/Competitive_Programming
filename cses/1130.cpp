#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int cnt = 0;

void dfs(int u, int f, vector<vector<int> > &g, vector<int> &vis) {
    for (auto v : g[u]) {
        if (v != f) {
            dfs(v,u,g,vis);
        }
    }
    if (!vis[u] && !vis[f]) {
        vis[u] = vis[f] = 1;
        cnt++;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<vector<int> > g(n+1);
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> vis(n+1,0);
    vis[0] = 1;
    dfs(1,0,g,vis);
    cout<<cnt<<endl;
    
    return 0;
}
