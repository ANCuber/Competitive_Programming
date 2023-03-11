#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

stack<int,vector<int> > stk;

void dfs(int u, vector<multiset<int> > &g) {
    while(!g[u].empty()) {
        int v = *g[u].begin();
        g[u].erase(g[u].begin());
        g[v].erase(g[v].find(u));
        dfs(v,g);
    }
    stk.push(u);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<int> dg(n+1,0);
    vector<multiset<int> > g(n+1);
    for (int i = 1; i <= m; ++i) {
        int u, v; cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        dg[u]++, dg[v]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (dg[i]&1) {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    dfs(1,g);
    if (stk.size() <= m) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(!stk.empty()) {
        if (stk.size() != m+1) cout<<' ';
        cout<<stk.top();
        stk.pop();
    }
    cout<<endl;
    return 0;
}
