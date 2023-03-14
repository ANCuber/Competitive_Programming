#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)
#define lc (p<<1)
#define rc (p<<1|1)

struct SEG{
    vector<int> a, id;
    inline void merge(int p) {
        if (a[lc] <= a[rc]) {
            id[p] = id[lc];
            a[p] = a[lc];
        } else {
            id[p] = id[rc];
            a[p] = a[rc];
        }
    }
    void setup(int l, int r, int p, vector<int> &dg) {
        if (l == r) {
            id[p] = l;
            a[p] = dg[l];
            return;
        }
        setup(l,mid,lc,dg), setup(mid+1,r,rc,dg);
        merge(p);
    }
    void init(int _n, vector<int> &dg) {
        a.assign(_n<<2,1e9);
        id.assign(_n<<2,0);
        setup(1,_n,1,dg);
    } 
    void mdf(int l, int r, int p, int tar, int v) {
        if (l == r) {
            a[p] = v;
            return;
        }
        if (tar <= mid) mdf(l,mid,lc,tar,v);
        else mdf(mid+1,r,rc,tar,v);
        merge(p);
    }
    int debug(int l, int r, int p, int tar) {
        if (l == r) return a[p];
        if (tar <= mid) return debug(l,mid,lc,tar);
        else return debug(mid+1,r,rc,tar);
    }
} seg;

int BEF(int n, vector<vector<int> > &g, vector<int> dg) {
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx,dg[i]);
        for (auto v : g[i]) {
            dg[v]--;
        }
    }
    return mx;
}

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int> > g(n+1);
    vector<int> dg(n+1,0), vis(n+1,0);
    while(m--) {
        int u, v; cin>>u>>v;
        u++, v++;
        g[u].pb(v);
        g[v].pb(u);
        dg[u]++, dg[v]++;
    }
    cout<<BEF(n,g,dg)<<' ';
    seg.init(n,dg);
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        int u = seg.id[1];
        vis[u] = 1;
        mx = max(mx,dg[u]);
        dg[u] = 1e9;
        seg.mdf(1,n,1,u,dg[u]);
        for (auto v : g[u]) {
            if (!vis[v]) {
                seg.mdf(1,n,1,v,--dg[v]);
            }
        }
    }
    cout<<mx<<endl;
}

signed main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        solve();
    }
    return 0;
}
