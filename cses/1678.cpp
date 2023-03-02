#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int flag = 0;

vector<int> in, vis;
vector<vector<int> > g;
stack<int> stk;

void dfs(int u, int f) {
    if (flag) return;
    in[u] = 1;
    vis[u] = f;
    for (auto v : g[u]) {
        if (in[v]) {
            int cur = u;
            vector<int> ans;
            while(cur != v) {
                ans.pb(cur);
                cur = vis[cur];
            }
            ans.pb(v); ans.pb(u);
            cout<<ans.size()<<endl;
            for (int i = ans.size()-1; i >= 0; --i) {
                cout<<ans[i];
                if (i) cout<<' ';
            }
            cout<<endl;
            flag = 1;
            in[u] = 0;
            return;
        } else if (!vis[v]) {
            dfs(v,u);
        }
    }
    in[u] = 0;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vis.assign(n+1,0); in.assign(n+1,0); 
    g.assign(n+1,vector<int>());
    while(m--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i,1e9);
    }
    if (!flag) cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
