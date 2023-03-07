#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<int> sz;
int n;

int Pre(int u, int f, vector<vector<int> > &g) {
    int tmp = 0;
    for (auto v : g[u]) {
        if (v != f) {
            tmp += Pre(v,u,g);
            sz[u] += sz[v];
        }
    }
    return tmp+sz[u];
}

void dfs(int tmp, int u, int f, vector<vector<int> > &g, vector<int> &ans) {
    ans[u] = tmp;
    for (auto v : g[u]) {
        if (v != f) {
            dfs(tmp-sz[v]+(n-sz[v]),v,u,g,ans);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<vector<int> > g(n+1);
    sz.assign(n+1,1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> ans(n+1,0);
    ans[1] = Pre(1,0,g)-n;
    dfs(ans[1],1,0,g,ans);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
