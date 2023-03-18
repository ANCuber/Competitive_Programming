#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct dinic{
    struct edge{
        int to;
        ll cap;
        int rev;
    };
    vector<vector<edge> > g;
    vector<int> nx, lev;
    int n;
    void init(int _n) {
        n = _n;
        g.assign(n+5,vector<edge>());
        nx.assign(n+5,0);
        lev.assign(n+5,0);
    }
    void add(int u, int v, ll c) {
        g[u].pb({v,c,int(g[v].size())});
        g[v].pb({u,0,int(g[u].size()-1)});
    }
    bool bfs(int s, int t) {
        fill(lev.begin(),lev.end(),0);
        queue<int> q;
        lev[s] = 1;
        q.push(s);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v,c,r] : g[u]) {
                if (c > 0 && !lev[v]) {
                    lev[v] = lev[u]+1;
                    q.push(v);
                }
            }
        }
        return lev[t];
    }
    ll dfs(int u, int t, ll fw) {
        if (u == t) return fw;
        for (;nx[u] < g[u].size(); ++nx[u]) {
            auto& e = g[u][nx[u]];
            if (e.cap > 0 && lev[e.to] == lev[u]+1) {
                ll ans = dfs(e.to,t,min(fw,e.cap));
                if (ans > 0) {
                    e.cap -= ans;
                    g[e.to][e.rev].cap += ans;
                    return ans;
                }
            }
        }
        return 0;
    }
    ll flow(int s, int t) {
        ll ans = 0;
        while(bfs(s,t)) {
            fill(nx.begin(),nx.end(),0);
            ll f = 0;
            while((f = dfs(s,t,1e18)) > 0) {
                ans += f;
            }
        }
        return ans;
    }
};

