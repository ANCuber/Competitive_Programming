#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

const int maxn = 2e5;
int cnt = 0, n, q;
vector<int> v(maxn+1,0), sz(maxn+1,0), bs(maxn+1,0), dep(maxn+1,0), tp(maxn+1,0), dfn(maxn+1,0), p(maxn+1,0);

void dfs(int u,int f, vector<vector<int> > &g) {
    sz[u] = 1;
    p[u] = f;
    dep[u] = dep[f]+1;
    for (auto v : g[u]) {
        if (v == f) continue;
        dfs(v,u,g);
        sz[u] += sz[v];
        if (!bs[u] || sz[v] > sz[bs[u]]) bs[u] = v;
    }
}

void link(int u, int top, vector<vector<int> > &g) {
    tp[u] = top;
    dfn[u] = ++cnt;
    if (bs[u]) link(bs[u],top,g);
    for (auto v : g[u]) {
        if (v == p[u] || v == bs[u]) continue;
        link(v,v,g);
    }
}

struct SEG{
    vector<int> arr;
    void init(int _n) {
        arr.assign(_n<<2,0);
    }
    void upd(int l, int r, int p, int tar, int val) {
        if (l == r) {
            arr[p] = val;
            return;
        }
        if (tar <= mid) upd(l,mid,p<<1,tar,val);
        else upd(mid+1,r,p<<1|1,tar,val);
        arr[p] = max(arr[p<<1],arr[p<<1|1]);
   }
   int qry(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return arr[p];
        if (qr <= mid) return qry(l,mid,p<<1,ql,qr);
        else if (ql > mid) return qry(mid+1,r,p<<1|1,ql,qr);
        else return max(qry(l,mid,p<<1,ql,qr),qry(mid+1,r,p<<1|1,ql,qr));
   }
} seg;

int query(int a, int b, vector<vector<int> > &g) {
    int mx = -1;
    while(tp[a] != tp[b]) {
        if (dep[tp[a]] < dep[tp[b]]) swap(a,b);
        mx = max(mx,seg.qry(1,n,1,dfn[tp[a]],dfn[a]));
        a = p[tp[a]];
    }
    if (dep[a] > dep[b]) swap(a,b);
    mx = max(mx,seg.qry(1,n,1,dfn[a],dfn[b]));
    return mx;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    vector<vector<int> > g(n+1);
    for (int i = 1; i <= n; ++i) cin>>v[i];
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int cmd , a, b;
    dfs(1,0,g);
    link(1,0,g);
    seg.init(n);
    for (int i = 1; i <= n; ++i) seg.upd(1,n,1,dfn[i],v[i]);
    int flag = 0;
    while(q--) {
        cin>>cmd>>a>>b;
        if (cmd == 1) {
            seg.upd(1,n,1,dfn[a],b);
        } else {
            if (flag) cout<<' ';
            flag = 1;
            cout<<query(a,b,g);
        }
    }
    cout<<endl;
    return 0;
}
