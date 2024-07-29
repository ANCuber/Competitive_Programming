#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

map<int,ll> mp;

void dfs(int u, vector<vector<pair<int,ll> > > &g, vector<int> &m, int cnt, ll sum) {
    if (!m[u]) {
        mp[cnt] = min(mp[cnt],sum);
        return;
    }
    for (auto [v,w] : g[u]) {
        if (m[u] == v) dfs(v,g,m,cnt,sum+w);
        else dfs(v,g,m,cnt+1,sum+w);
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<vector<pair<int,ll> > > g(n+2);
    vector<int> m(n+2);
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin>>u>>v>>w;
        g[u].pb({v,w});
    }
    for (int i = 1; i <= n; ++i) cin>>m[i];
    for (int i = 0; i < n; ++i) mp[i] = 2e18;
    dfs(1,g,m,0,0);
    ll mn = mp[0];
    cout<<mn<<'\n';
    for (int i = 1; i < n; ++i) {
        mn = min(mn,mp[i]);
        cout<<mn<<'\n';
    }
    
    return 0;
}
