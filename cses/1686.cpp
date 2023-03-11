#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int ord = 0, comp = 0;
stack< int,vector<int> > stk;
vector<int> w, in, scc, dfn, low, sz;

void Tarjan(int u, vector<vector<int> > &g) {
    stk.push(u);
    in[u] = 1;
    dfn[u] = low[u] = ++ord;
    for (auto v : g[u]) {
        if (!dfn[v]) {
            Tarjan(v,g);
            low[u] = min(low[u],low[v]);
        } else if (in[v]) {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        comp++;
        while(stk.top() != u) {
            scc[stk.top()] = comp;
            sz[comp] += w[stk.top()];
            in[stk.top()] = 0;
            stk.pop();
        }
        scc[stk.top()] = comp;
        sz[comp] += w[stk.top()];
        in[stk.top()] = 0;
        stk.pop();

    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+1);
    w.assign(n+1,0), in.assign(n+1,0), scc.assign(n+1,0), dfn.assign(n+1,0), low.assign(n+1,0), sz.assign(n+1,0);
    for (int i = 1; i <= n; ++i) cin>>w[i];
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
    }
    for (int i = 1; i <= n; ++i) if (!dfn[i]) Tarjan(i,g);
    vector<vector<int> > nw(comp+1);
    vector<int> dg(comp+1,0), cnt(comp+1,0);
    set< pii > s;
    for (int u = 1; u <= n; ++u) {
        for (auto v : g[u]) {
            if (scc[u] == scc[v] || s.count({scc[u],scc[v]})) continue;
            nw[scc[u]].pb(scc[v]);
            s.insert({scc[u],scc[v]});
            dg[scc[v]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= comp; ++i) {
        if (!dg[i]) {
            q.push(i);
            cnt[i] = sz[i];
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : nw[u]) {
            dg[v]--;
            cnt[v] = max(cnt[v],cnt[u]);
            if (!dg[v]) {
                cnt[v] += sz[v];
                q.push(v);
            }
        }
    }
    cout<<*max_element(cnt.begin(),cnt.end())<<endl;
    return 0;
}
