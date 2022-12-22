#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int fd = 0;
int st = 0;

void dfs(int u, int f, vector<int> &p, vector<vector<int> > &g) {
    if (fd) return;
    p[u] = f;
    for (auto v : g[u]) {
        if (v == f || fd) continue;
        if (!p[v]) {
            dfs(v,u,p,g);
        } else {
            fd = 1;
            p[v] = u;
            st = u;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> p(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!p[i]) dfs(i,n+i,p,g);
    }
    if (st) {
        int cur = st;
        vector<int> ans;
        do {
            ans.pb(cur);
            cur = p[cur];
        } while(cur != st);
        ans.pb(cur);
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); ++i) {
            if(i) cout<<' ';
            cout<<ans[i];
        }
    } else {
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}
