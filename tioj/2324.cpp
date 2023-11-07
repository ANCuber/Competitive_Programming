#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

bitset<200005> rmv;
vector<pair<int,ll> > tr[200005];
int sz[200005]; 
ll A[200005], a[200005];
int cur;
ll mn;

struct Edge{
    int u, v;
    ll w;
    bool operator<(Edge y) {
        return w < y.w;
    }
};

vector<Edge> e;

int get_size(int u, int f) {
    sz[u] = 1;
    for (auto [v,w] : tr[u]) {
        if (rmv[v] || v == f) continue;
        sz[u] += get_size(v,u);
    }
    return sz[u];
}
 
int get_cen(int u, int f, int s) {
    for (auto [v,w] : tr[u]) {
        if (rmv[v] || v == f) continue;
        if (2*sz[v] > s) return get_cen(v,u,s);
    }
    return u;
}

void Add(int u, int f) {
    if(cur!=u) e.pb({cur,u,A[u]+A[cur]});
    for (auto [v,w] : tr[u]) {
        if (rmv[v] || v == f) continue;
        Add(v,u);
    }
}

void Cal(int u, int f, ll d) {
    A[u] = a[u]+d;
    if (A[u] < mn) {
        cur = u;
        mn = A[u];
    }
    for (auto [v,w] : tr[u]) {
        if (rmv[v] || v == f) continue;
        Cal(v,u,d+w);
    }
}

void Solve(int u) {
    int cen = get_cen(u,0,get_size(u,0));
    cur = 0, mn = 1e18;
    Cal(cen,0,0);
    Add(cur,0);
    rmv[cen] = 1;
    
    for (auto [v,w] : tr[cen]) {
        if (rmv[v]) continue;
        Solve(v);
    }
}

struct DSU{
    vector<int> f;
    void init(int _n) {
        f.resize(_n+5);
        for (int i = 1; i <_n+5; ++i) f[i] = i;
    }
    int ff(int p) {
        if (p == f[p]) return p;
        return f[p] = ff(f[p]);
    }   
    ll add(int u, int v, ll w) {
        int fu = ff(u), fv = ff(v);
        if (fu == fv) return 0;
        f[fu] = fv;
        return w;
    }
} dsu;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    rmv.reset();
    dsu.init(n);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    int u, v; ll w;
    for (int i = 1; i < n; ++i) {
        cin>>u>>v>>w;
        tr[u].pb({v,w});
        tr[v].pb({u,w});
    }
    Solve(1);
    sort(e.begin(),e.end());
    ll ans = 0;
    for (auto [u,v,w] : e) ans += dsu.add(u,v,w);
    cout<<ans<<endl;
    return 0;
}
