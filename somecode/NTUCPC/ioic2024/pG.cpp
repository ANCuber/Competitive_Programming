#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define pb push_back

vector<int> vis(200005,0), sz(200005,1), sn(200005,0), top(200005,0), dfn(200005,0), dep(200005,0), prt(200005,0);
//vector<pii> e;
set<pii> e;
vector<vector<int> > tr(200005);
string ans[2] = {"Yes\n","No\n"};

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void mdf(int p, int x) {
        while(p <= sz) {
            a[p] += x;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

int dfs(int u, int f, vector<vector<int> > &g) {
    vis[u] = 1;
    int cnt = 0;
    int csn = 0, cmx = 0;
    for (auto v : g[u]) {
        if (!vis[v]) {
            tr[u].pb(v);//a tree edge from u to v
            prt[v] = u;
            int tmp = dfs(v,u,g);
            if (tmp > cmx) {
                cmx = tmp;
                csn = v;
            }
            sz[u] += tmp;
        } else if (v != f) {
            e.insert({min(u,v),max(u,v)});
        }
    }
    sn[u] = csn;
    return sz[u];
}


int ord = 0;
void HLD(int u, int tp, int d) {
    top[u] = tp;
    dfn[u] = ++ord;
    dep[u] = d;
    if (sn[u]) HLD(sn[u],tp,d+1);
    for (auto v : tr[u]) {
        if (v != sn[u]) HLD(v,v,d+1);
    }
}

void LCA(int u, int v) {//u != v
    while(top[u] != top[v]) {
        if (dep[u] > dep[v]) swap(u,v);
        bit.mdf(dfn[top[v]],1);
        bit.mdf(dfn[v]+1,-1);
        v = prt[top[v]];
    }
    if (dep[u] > dep[v]) swap(u,v);
    bit.mdf(dfn[u]+1,1);
    bit.mdf(dfn[v]+1,-1);
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin>>N>>M;    
    bit.init(N);
    vector<vector<int> > g(N+2);
    while(M--) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0,g);
    HLD(1,1,1);
    prt[1] = 1;
    for (auto &[u,v] : e) {
        //cout<<u<<' '<<v<<endl;
        LCA(u,v);
        //for (int i = 1; i <= N; ++i) cout<<bit.sum(dfn[i])<<' '; cout<<endl;
    }
    int flag = 0;
    for (int i = 1; i <= N; ++i) {
        if (i != 1 && bit.sum(dfn[i]) > 1) flag = 1;
    }
    cout<<ans[flag];
    return 0;
}
