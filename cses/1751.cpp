#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, int f, int d, vector<int> &g, vector<int> &vis, vector<int> &ans, vector<int> &pre) {
    vis[u] = d;
    pre[u] = f;
    if (!vis[g[u]]) {
        dfs(g[u],u,d+1,g,vis,ans,pre);
        if (!ans[u]) ans[u] = ans[g[u]]+1;
    } else if (!ans[g[u]]){
        int cur = u, tmp = d-vis[g[u]]+1;
        ans[g[u]] = tmp;
        while(cur != g[u]) {
            ans[cur] = tmp;
            cur = pre[cur];
        }
    } else {
        ans[u] = ans[g[u]]+1;
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> g(n+1), vis(n+1,0), ans(n+1,0), pre(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>g[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i,0,1,g,vis,ans,pre);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
