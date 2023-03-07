#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int n;

struct SEG{
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] += tg[p];
            if (c) {
                tg[p<<1] += tg[p];
                tg[p<<1|1] += tg[p];
            }
            tg[p] = 0;
        }
    }
    void mdf(int l, int r, int p, int ql, int qr, int v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] += v;
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr,v);
        else {
            mdf(l,mid,p<<1,ql,qr,v);
            mdf(mid+1,r,p<<1|1,ql,qr,v);
        }
        a[p] = max(a[p<<1]+tg[p<<1],a[p<<1|1]+tg[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return max(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

int ord = 0;
vector<int> p, sz;

int Pre(int u, int f, int d, vector<vector<int> > &g) {
    p[u] = ++ord;
    seg.mdf(1,n,1,p[u],p[u],d);
    int tmp = 1;
    for (auto v : g[u]) {
        if (v != f) {
            tmp += Pre(v,u,d+1,g);
        }
    }
    return sz[u] = tmp;
}

void solve(int u, int f, vector<vector<int> > &g, vector<int> &ans) {
    ans[u] = seg.query(1,n,1,1,n);
    for (auto v : g[u]) {
        if (v != f) {
            seg.mdf(1,n,1,1,n,1);
            seg.mdf(1,n,1,p[v],p[v]+sz[v]-1,-2);
            solve(v,u,g,ans);
        }
    }
    seg.mdf(1,n,1,1,n,-1);
    seg.mdf(1,n,1,p[u],p[u]+sz[u]-1,2);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;    
    vector<vector<int> > g(n+1);
    p.assign(n+1,0), sz.assign(n+1,0);
    seg.init(n+2);
    for (int i = 1; i < n; ++i) {
        int a, b; cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    Pre(1,0,0,g);
    vector<int> ans(n+1);
    solve(1,0,g,ans);
    for (int i = 1; i <= n; ++i) {
        if (i != 1) cout<<' ';
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}
