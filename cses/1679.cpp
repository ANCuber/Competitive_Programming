#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> d(n+1,0);
    while(m--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        d[b]++;
    }
    queue<int> q;
    vector<int> ans, vis(n+1,0);
    for (int i = 1; i <= n; ++i) if(!d[i]) q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        ans.pb(cur);
        vis[cur] = 1;
        for (auto v : g[cur]) {
            d[v]--;
            if (!d[v]) q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i]) {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) ans.pb(i);
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    return 0;
}
