#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)
#define int ll

int n, Q;

struct Query{
    int r, id;
};

struct SEG{
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] = tg[p]*(c+1);
            if (c) tg[p<<1] = tg[p];
            if (c) tg[p<<1|1] = tg[p];
            tg[p] = 0;
        }
    }
    void upd(int l, int r, int p, int ql, int qr, int v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] = v;
            return;
        }
        if (qr <= mid) upd(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) upd(mid+1,r,p<<1|1,ql,qr,v);
        else {
            upd(l,mid,p<<1,ql,qr,v);
            upd(mid+1,r,p<<1|1,ql,qr,v);
        }
        a[p] = (tg[p<<1]?(tg[p<<1]*(mid-l+1)):a[p<<1]) + (tg[p<<1|1]?(tg[p<<1|1]*(r-mid)):a[p<<1|1]);
    }
    int sum(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return sum(l,mid,p<<1,ql,qr);
        else if (ql > mid) return sum(mid+1,r,p<<1|1,ql,qr);
        else  return sum(l,mid,p<<1,ql,qr)+sum(mid+1,r,p<<1|1,ql,qr);
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>Q;
    seg.init(n);
    vector<int> v(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
        v[i] += v[i-1];
    }
    vector<vector<Query> > q(n+1);
    vector<int> ans(Q+1);
    for (int i = 1; i <= Q; ++i) {
        int l, r; cin>>l>>r;
        q[l].pb({r,i});
    }
    for (int i = n; i >= 1; --i) {
        int l = i, r = n+1;
        while(r-l > 1) {
            if (seg.sum(1,n,1,mid,mid) > v[i]-v[i-1]) r = mid;
            else l = mid;
        }
        seg.upd(1,n,1,i,l,v[i]-v[i-1]);
        for (auto [R,id] : q[i]) {
            ans[id] = seg.sum(1,n,1,i,R)-(v[R]-v[i-1]);
        }
    }
    for (int i = 1; i <= Q; ++i) {
        cout<<ans[i]<<endl;
    }
    return 0;
}
