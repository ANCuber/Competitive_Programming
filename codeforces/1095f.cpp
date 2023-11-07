#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back 

struct Edge{
    int u, v, w;
    bool operator<(Edge y) {
        return w < y.w;
    }
};

int dsu[200005];

int ff(int p) {
    if (p == dsu[p]) return p;
    return dsu[p] = ff(dsu[p]);
}

int add(int u, int v, int w) {
    int fv = ff(v), fu = ff(u);
    if (fv == fu) return 0;
    dsu[fv] = fu;
    return w;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<int> a(n+1,0);
    int mn = 1e18, id;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        if (mn > a[i]) {
            mn = a[i];
            id = i;
        }
    }
    vector<Edge> e;
    for (int i = 1; i <= n; ++i) {
        if (i == id) continue;
        e.pb({i,id,a[i]+a[id]});
    }
    while(m--) {
        int u, v, w; cin>>u>>v>>w;
        e.pb({u,v,w});
    }
    sort(e.begin(),e.end());
    for (int i = 1; i <= n; ++i) dsu[i] = i;
    int ans = 0;
    for (auto [u,v,w] : e) ans += add(u,v,w);
    cout<<ans<<endl;
    return 0;
}
