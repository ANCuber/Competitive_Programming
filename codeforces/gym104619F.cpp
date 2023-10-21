#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

inline pii edge(int a, int b) {
    if (a > b) return {b,a};
    return {a,b};
}

struct DSU{
    int N;
    vector<int> prt, sz;
    void init(int _n) {
        prt.assign(_n+5,0);
        for (int i = 1; i <= _n; ++i) prt[i] = i;
        sz.assign(_n+5,1);
        N = _n;
    }
    int ff(int p) {
        if (prt[p] == p) return p;
        return ff(prt[p]);
    }
    void add(int u, int v) {
        int fu = ff(u), fv = ff(v);
        if (fu == fv) {
            
        } else {
            if (sz[fu] > sz[fv]) prt[fv] = fu;
            else prt[fu] = fv;
        }
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q; cin>>n>>m>>q;    
    dsu.init(n);
    multiset<pii> s;
    for (int i = 0; i < m; ++i) {
        int u, v; cin>>u>>v;
        s.insert(edge(u,v));
    }
    vector<int> Add(q);
    for (auto& [u,v] : Add) {
        cin>>u>>v;
        s.erase(s.find(edge(u,v)));
    }
    for (auto [u,v] : s) {
        
    }
    for (int i = q-1; i >= 0; --i) {
        
    }
    
    
    return 0;
}
