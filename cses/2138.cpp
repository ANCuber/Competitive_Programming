#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dfs(int cur, vector<int> &ans, vector<vector<int> > &g) {
    int cnt = 0;
    for (auto i : g[cur]) {
        cnt += dfs(i,ans,g);
    }
    return ans[cur] = cnt+1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector<vector<int> > g(n+1);
    vector<int> dg(n+1,0), ans(n+1,0);
    set< pii > s;
    int u, v;
    while(m--) {
        cin>>u>>v;
        if (s.count({u,v})) continue;
        s.insert({u,v});
        g[u].pb(v);
        dg[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (!dg[i]) {
            dfs(i,ans,g);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' '; 
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
