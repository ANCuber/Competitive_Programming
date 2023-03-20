#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int mxn = 1e6+5;
int cnt = 0, ord = 0;

stack<int,vector<int> > stk;
vector<int> dfn(mxn,0), low(mxn,0), in(mxn,0), scc(mxn,0);

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
        ++cnt;
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
    while(m--) {
        int u, v;
        cin>>u>>v;
        g[v].pb(u);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i,g);
    cout<<cnt<<endl;
    for (int i = 1; i <= n; ++i) {
        if (i-1) cout<<' ';
        cout<<scc[i];
    }
    cout<<endl;
    return 0;
}
