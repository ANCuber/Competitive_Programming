#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Edge{
    int u, v, w;
    bool operator<(Edge b) {
        return w < b.w;
    }
};

struct DSU{
    vector<int> a;
    void init(int _n) {
        a.assign(_n+5,0);
        for (int i = 1; i <= _n; ++i) a[i] = i;
    }
    int find(int p) {
        if (p == a[p]) return p;
        return a[p] = find(a[p]);
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<Edge> e(m);
    dsu.init(n);
    for (auto& [u,v,w] : e) cin>>u>>v>>w;
    sort(e.begin(),e.end());
    int sum = 0;
    for (auto [u,v,w] : e) {
        int i = dsu.find(u), j = dsu.find(v);
        if (i == j) continue;
        dsu.a[i] = j;
        n--;
        sum += w;
    }
    if (n == 1) cout<<sum<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    
    return 0;
}
