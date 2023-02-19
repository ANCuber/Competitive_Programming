#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

pii dfs(int cur, int f, vector<vector< pii > > &g, vector<int> &w) {
    int bk = w[cur], dis = 0, fd;
    for (auto [i,c] : g[cur]) {
        if (i != f) {
            pii ret = dfs(i,cur,g,w);
            dis += ret.first;
            bk += ret.second;
        } else {
            fd = c;
        }
    }
    return {abs(bk)*fd+dis,bk};
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector<int> w(n+1);
    vector<vector< pii > > g(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>w[i];
        w[i] -= k;
    }
    int u, v, d;
    for (int i = 1; i < n; ++i) {
        cin>>u>>v>>d;
        g[u].pb({v,d});
        g[v].pb({u,d});
    }
    g[1].pb({0,0});
    cout<<dfs(1,0,g,w).first<<endl;
    return 0;
}
