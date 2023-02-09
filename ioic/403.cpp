#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int f, int u, vector<vector<int> > &g, vector<int> &d) {
    d[u] = d[f]+1;
    cout<<u<<' '<<d[u]<<endl;
    for (auto v : g[u]) {
        if (v != f) dfs(u,v,g,d);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<vector<int> > g(n+1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> d(n+1,0);
    dfs(0,1,g,d);
    sort(d.begin(),d.end());
    cout<<d[n-1]+m
    return 0;
}
