#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, vector<int> &v, vector<vector<int> > &g) {
    v[u] = 1;
    for (auto& i: g[u]) if (!v[i]) dfs(i,v,g);
}

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    scanf("%d%d",&n,&m);
    vector<vector<int> > g(n+1);
    vector<int> v(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cnt = -1;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) {
            ans.pb(i);
            dfs(i,v,g);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    for (int i = 1; i < ans.size(); ++i) printf("%d %d\n",ans[i-1],ans[i]);
    return 0;
}
