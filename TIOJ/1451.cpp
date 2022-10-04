#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back

int cnt = 0, colo = 0;
bitset <100005> v;

void dfs(int p, vector<int> &suf, vector<vector<int> > &g) {
    v[p] = 1;
    for (auto i : g[p]) if (!v[i]) dfs(i,suf,g);
    suf[++cnt] = p;
}

void scc(int p, vector<vector<int> > &bk, vector<int> &c) {
    c[p] = colo;
    for (auto i : bk[p]) if (!c[i]) scc(i,bk,c);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, ans = 0; cin>>n>>m;        
    vector<vector<int> > g(n+1), bk(n+1);
    vector<int> suf(n+1), c(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        g[u].pb(v);
        bk[v].pb(u);
    }
    v.reset();
    for (int i = 1; i <= n; ++i) if (!v[i]) dfs(i,suf,g);
    for (int i = n; i > 0; --i) {
        if (!c[suf[i]]) {
            colo++;
            scc(suf[i],bk,c);
        }
    }
    vector<vector<int> > nwg(colo+1);
    vector<int> dg(colo+1,0);
    for (int i = 1; i <= n; ++i) {
        for (auto j : g[i]) {
            if (c[i] == c[j]) continue;
            nwg[c[i]].pb(c[j]);
            dg[c[j]]++;
        }
    }
    for (int i = 1; i <= colo; ++i) if(!dg[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
