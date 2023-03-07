#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

void dfs(int u, int f, vector<vector<int> > &g, vector<int> &dep) {
    dep[u] = dep[f]+1;
    for (auto v : g[u]) {
        if (v != f) dfs(v,u,g,dep);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<vector<int> > anc(n+1,vector<int>(__lg(n)+5,0)), g(n+1);
    vector<int> dep(n+1,0);
    for (int i = 2; i <= n; ++i) {
        int e; cin>>e;
        anc[i][0] = e;
        g[e].pb(i);
    }
    dfs(1,0,g,dep);
    for (int i = 1; i <= __lg(n)+1; ++i) {
        for (int j = 1; j <= n; ++j) {
            anc[j][i] = anc[anc[j][i-1]][i-1];
        }
    }
    while(q--) {
        int a, b; cin>>a>>b;
        if (dep[a] > dep[b]) swap(a,b);
        int k = dep[b]-dep[a], base = 0;
        while(k) {
            if (k&1) b = anc[b][base];
            base++;
            k >>= 1;
        }
        for (int i = __lg(n)+1; i >= 0; --i) {
            if (anc[a][i] != anc[b][i]) {
                a = anc[a][i];
                b = anc[b][i];
            }
        }
        if (a != b) a = anc[a][0];
        cout<<a<<endl;
        
    }
    
    return 0;
}
