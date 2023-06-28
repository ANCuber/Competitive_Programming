#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, int f, vector<int> &cnt, vector<vector<int> > &g) {
    int tmp = 0;
    for (auto v : g[u]) {
        if (v != f) {
            dfs(v,u,cnt,g);
            cnt[u] += cnt[v];
            tmp++;
        }
    }
    if (!tmp) cnt[u] = 1;
}

void Run() {
    int n, q; cin>>n;
    vector<vector<int> > g(n+1);
    vector<int> cnt(n+1,0);
    for (int i = 0; i < n-1; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0,cnt,g);
    cin>>q;
    while(q--) {
        int a, b; cin>>a>>b;
        cout<<cnt[a]*cnt[b]<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}
