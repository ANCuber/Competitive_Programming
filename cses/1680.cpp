#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, vector<int> &pre, vector<int> &ans) {
    if (u != 1) dfs(pre[u],pre,ans);
    ans.pb(u);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    vector<int> d(n+1,0), pre(n+1,0), mx(n+1,0), tmp(n+1,0), frm(n+1,0);
    while(m--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        d[b]++;
    }
    queue<int> q;
    frm[1] = mx[1] = pre[1] = 1;
    for (int i = 1; i <= n; ++i) if (!d[i]) q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n) break;
        for (auto v : g[cur]) {
            d[v]--;
            if (mx[v] < mx[cur]+1 && frm[cur]) {
                mx[v] = mx[cur]+1;
                tmp[v] = cur;
                frm[v] = 1;
            }
            if (!d[v]) {
                q.push(v);
                pre[v] = tmp[v];
            }
        }
    }
    if (pre[n] && frm[n]) {
        vector<int> ans;
        dfs(n,pre,ans);
        cout<<ans.size()<<endl;
        for (int i = 0; i < ans.size(); ++i) {
            if (i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
