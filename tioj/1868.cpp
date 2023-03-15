#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int nmx = 3e5+5;
int n, k;
int ord = 0, cnt = 0;
stack<int,vector<int> > stk;
vector<int> dfn(nmx,0), low(nmx,0), in(nmx,0), scc(nmx,0), sz(nmx,0);

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
        cnt++;
        while(stk.top() != u) {
            scc[stk.top()] = cnt;
            in[stk.top()] = 0;
            if (stk.top() != n+1) sz[cnt]++;
            stk.pop();
        }
        scc[stk.top()] = cnt;
        in[stk.top()] = 0;
        if (stk.top() != n+1) sz[cnt]++;
        stk.pop();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>k;
    vector<vector<int> > g(n+2);
    vector<int> h(n+2);
    h[0] = h[n+1] = 1e9;
    for (int i = 1; i <= n; ++i) cin>>h[i];
    string s; cin>>s;
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'T') g[i].pb(n+1);
        if (h[i] >= h[i-1]) g[i].pb(i-1);
        if (h[i] >= h[i+1]) g[i].pb(i+1);
        g[n+1].pb(i);
    }
    for (int i = 1; i <= n+1; ++i) if (!dfn[i]) Tarjan(i,g);
    set<pii> st;
    vector<int> dg(cnt+2,0);
    vector<vector<int> > nw(cnt+2);
    for (int u = 1; u <= n+1; ++u) {
        for (auto v : g[u]) {
            if (scc[u] != scc[v] && !st.count({scc[u],scc[v]})) {
                nw[scc[u]].pb(scc[v]);
                dg[scc[v]]++;
                st.insert({scc[u],scc[v]});
            }
        }
    }
    vector<int> ans(cnt+2,0), is(cnt+2,0);
    is[scc[k]] = 1;
    queue<int> q;
    for (int i = 1; i <= cnt; ++i) {
        if(!dg[i]) {
            q.push(i);
            ans[i] = sz[i];
        }
    }
    int mx = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        mx = max(mx,ans[u]*is[u]);
        for (auto v : nw[u]) {
            is[v] |= is[u];
            ans[v] = max(ans[v],is[u]*ans[u]);
            dg[v]--;
            if (!dg[v]) {
                q.push(v);
                ans[v] += sz[v];
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
