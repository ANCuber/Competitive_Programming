#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, d=0, cnt=0;
bitset<10005> v;
vector<int> stk, scc, in, dfn, low, sz;

void tarjan(int cur, vector<vector<int> > &g) {
    dfn[cur] = low[cur] = ++d;
    stk.pb(cur);
    v[cur] = in[cur] = 1;
    for (auto i : g[cur]) {
        if (!v[i]) {
            tarjan(i,g);
            low[cur] = min(low[cur],low[i]);
        } else if (in[i]) {
            low[cur] = min(low[cur],dfn[i]);
        }
    }
    if (low[cur] == dfn[cur]) {
        cnt++;
        while(stk.back() != cur) {
            sz[cnt]++;
            scc[stk.back()] = cnt;
            in[stk.back()] = 0;
            stk.pop_back();
        }
        sz[cnt]++;
        scc[stk.back()] = cnt;
        in[stk.back()] = 0;
        stk.pop_back();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        d = cnt = 0;
        vector<vector<int> > g(n+1);
        v.reset(); stk.clear();
        in.assign(n+1,0), dfn.assign(n+1,0), low.assign(n+1,0), scc.assign(n+1,0), sz.assign(n+1,0); 
        while(m--) {
            int a, b; cin>>a>>b;
            g[a].pb(b);
        }
        for (int i = 1; i <= n; ++i) if (!v[i]) tarjan(i,g);
        vector<set<int> > nw(cnt+1);
        vector<int> dg(cnt+1,0), dp(cnt+1,0);
        for (int i = 1; i <= n; ++i) {
            for (auto j : g[i]) {
                if (scc[i] != scc[j]) {
                    int tmp = nw[scc[i]].size();
                    nw[scc[i]].insert(scc[j]);
                    dg[scc[j]] += (nw[scc[i]].size()-tmp);
                }
            }
        }
        queue<int> q;
        for (int i = 1; i <= cnt; ++i) if(!dg[i]) q.push(i);
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto i : nw[cur]) {
                dg[i]--;
                dp[i] = max(dp[i],dp[cur]+sz[cur]);
                if (!dg[i]) {
                    q.push(i);
                }
            }
        }
        int mx = 0;
        for (int i = 1; i <= cnt; ++i) {
            mx = max(mx,dp[i]+sz[i]);
        }
        cout<<mx<<endl;
    }
    return 0;
}
