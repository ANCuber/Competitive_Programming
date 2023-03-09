#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

stack<int,vector<int> > stk;
vector<int> in, scc, dfn, low;
int cnt = 0, ord = 0;

void Tarjan(int u, vector<vector<int> > &g) {
    dfn[u] = low[u] = ++ord;
    in[u] = 1;
    stk.push(u);
    for (auto v : g[u]) {
        if (!dfn[v]) {
            Tarjan(v,g);
            low[u] = min(low[u],low[v]);
        } else if (in[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        cnt++;
        while(stk.top() != u) {
            scc[stk.top()] = cnt;
            in[stk.top()] = 0;
            stk.pop();
        }
        scc[u] = cnt;
        in[u] = 0;
        stk.pop();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    in.assign(n+1,0), scc.assign(n+1,0), dfn.assign(n+1,0), low.assign(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) Tarjan(i,g);
    }
    cout<<cnt<<endl;
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<scc[i];
    }
    cout<<endl;
    return 0;
}
