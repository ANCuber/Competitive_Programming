#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct DINIC{
    struct Edge{
        int to;
        ll cap;
        int rev;
    };
    vector<vector<Edge> > g;
    vector<int> lev, nx;
    void init(int _n) {
        g.assign(_n+5,vector<Edge>());
        lev.assign(_n+5,0);
        nx.assign(_n+5,0);
    }
    void add_edge(int u, int v, ll c) {
        g[u].pb({v,c,int(g[v].size())});
        g[v].pb({u,0,int(g[u].size()-1)});
    }
    bool bfs(int s, int t) {
        fill(lev.begin(),lev.end(),0);
        queue<int> q;
        q.push(s);
        lev[s] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto [to,cap,rev] : g[cur]) {
                if (cap > 0 && !lev[to]) {
                    lev[to] = lev[cur]+1;
                    q.push(to);
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
            ll f;
            while((f = dfs(s,t,1e18)) > 0) {
                ans += f;
            }
        }
        return ans;
    }
} din;

const int mxn = 500, med = 1501, medout = 1502, tar = 1503, src = 0, mon = 1000;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    din.init(1505);
    for (int i = 1; i <= m; ++i) {
        din.add_edge(i+mon,tar,1);
    }
    din.add_edge(med,medout,k);
    for (int i = 1; i <= n; ++i) {
        int t; cin>>t;
        din.add_edge(src,i,1e18);
        din.add_edge(i,i+mxn,1);
        din.add_edge(i,med,1);
        din.add_edge(medout,i+mxn,1);
        for (int j = 1; j <= t; ++j) {
            int x; cin>>x;
            din.add_edge(i+mxn,x+mon,1);
        }
    }
    cout<<din.flow(src,tar)<<endl;
    return 0;
}
