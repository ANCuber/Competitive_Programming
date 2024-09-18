#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> cur;
vector<pii> ans;
set<pii> edge;

void dfs(int u, vector<vector<int> > &g) {
    for (;cur[u] < g[u].size(); cur[u]++) {
        int v = g[u][cur[u]];
        if (edge.count({u,v})) continue; 
        edge.insert({u,v});
        dfs(v,g);
        ans.pb({u,v});
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M; cin>>N>>M;    
    vector<vector<int> > g(N+2);
    vector<int> out(N+2,0), in(N+2,0);
    cur.assign(N+2,0);
    for (int i = 1; i <= M; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        out[u]++, in[v]++;
    }
    int flag = 0, cnt = 1;
    for (int i = 1; i <= N; ++i) {
        if (i != 1 && i != N && out[i] != in[i]) flag = 1;
        if ((out[i]+in[i]) >= 6) cnt = 2;
    }
    if (flag || out[1]-in[1] != 1 || out[N]-in[N] != -1) {
        cout<<0<<endl;
        return 0;
    }
    //g[N].pb(1);
    out[N]++, in[1]++;
    if (out[N]+in[N] >= 4 && in[1]+out[1] >= 4) cnt = 2;
    if ((out[1]+in[1]) >= 6 || (out[N]+in[N]) >= 6) cnt = 2;
    dfs(1,g);
    cout<<1<<endl;//the number
    for (int i = ans.size()-1; i >= 0; --i) cout<<ans[i].first<<' '<<ans[i].second<<endl;
    return 0;
}
