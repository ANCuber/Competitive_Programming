#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long> 
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, d=0, cnt=0;
vector<vector<int> > g;
vector<int> low, dfn, scc, sz, in;
stack<int> stk;

void tarjan(int p) {
    low[p] = dfn[p] = ++d;
    stk.push(p);
    in[p] = 1;
    for (auto &v : g[p]) {
        if (!dfn[v]) {
            tarjan(v);
            low[p] = min(low[p],low[v]);
        } else if (in[v]) {
            low[p] = min(low[p],dfn[v]);
        }
    }
    if (low[p] == dfn[p]) {
        cnt++;
        while(stk.top() != p) {
            scc[stk.top()] = cnt;
            sz[cnt]++;
            in[stk.top()] = 0;
            stk.pop();
        }
        scc[stk.top()] = cnt;
        sz[cnt]++;
        in[stk.top()] = 0;
        stk.pop();
    }
}

int dfs(int p, vector<set<int> > &nw) {
    int ret = 0;
    for (auto v : nw[p]) ret = max(ret,dfs(v,nw));
    return ret+sz[p];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    g.resize(n);
    low.resize(n), scc.resize(n);
    dfn.assign(n,0), sz.assign(n+1,0), in.assign(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
    }
    for (int i = 0; i < n; ++i) if (!dfn[i]) tarjan(i);
    
    vector<int> dg(cnt+1,0), dp(cnt+1,0);
    vector<set<int> > nw(cnt+1);
    for (int i = 0; i < n; ++i) {
        for (auto &v : g[i]) {
            if (scc[i] != scc[v]) {
                int tmp = nw[scc[i]].size();
                nw[scc[i]].insert(scc[v]);
                dg[scc[v]] += (nw[scc[i]].size()-tmp);
            }
        }
    }
    queue<int> q;
    for (int i = 1;i <= cnt; ++i) if(!dg[i]) q.push(i);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto v : nw[cur]) {
            dg[v]--;
            dp[v] = max(dp[v],dp[cur]+sz[cur]);
            if (!dg[v]) {
                q.push(v);
            }
        }
    }
    int mx = 0;
    for (int i = 1; i <= cnt; ++i) {
        mx = max(mx,dp[i]+sz[i]);
    }
    cout<<mx<<endl;
    return 0;
}


