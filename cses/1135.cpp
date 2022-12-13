#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

map<pii,int> mp;
vector<int> dep, prt;

int fb(int x) {
    if (x == prt[x]) return x;
    return prt[x] = fb(prt[x]);
}

void Tarjan(int u,int f,int d,vector<vector<int> > &g,vector<set<int> > &bnd){
    dep[u] = d;
    for (auto v : bnd[u]) {
        if (dep[v]) {
            mp[{u,v}] = mp[{v,u}] = fb(v);
        }
    }
    for (auto v : g[u]) {
        if (v != f) {
            Tarjan(v,u,d+1,g,bnd);
        }
    }
    prt[u] = f;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, Q; cin>>n>>Q;
    vector<vector<int> > g(n+1);
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<set<int> > bnd(n+1);
    dep.assign(n+1,0), prt.assign(n+1,0);
    for (int i = 1; i <= n; ++i) prt[i] = i;
    vector< pii > q(Q);
    for (int i = 0; i < Q; ++i) {
        int a, b; cin>>a>>b;
        q[i] = {a,b};
        bnd[a].insert(b);
        bnd[b].insert(a);
    }
    Tarjan(1,1,1,g,bnd);
    for (auto [a,b] : q) {
        int lca = mp[{a,b}];
        cout<<dep[a]+dep[b]-2*dep[lca]<<endl;
    }
    return 0;
}
