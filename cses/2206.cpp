#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct SEG{
    vector<int> a;
    int typ;
    void init(int _n, int _t) {
        a.assign(_n<<2,1e18);
        typ = _t;
    }
    void mdf(int l, int r, int p, int q, int v) {
        if (l == r) {
            a[p] = v;
            return;
        }
        if (q <= mid) mdf(l,mid,p<<1,q,v);
        else if (q > mid) mdf(mid+1,r,p<<1|1,q,v);
        if(!typ) a[p] = min(a[p<<1],a[p<<1|1]+mid+1-l);
        else a[p] = min(a[p<<1]+r-mid,a[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr, int k) {
        if (ql <= l && r <= qr) return typ?(a[p]+(k-r)):(a[p]+(l-k));
        if (qr <= mid) return query(l,mid,p<<1,ql,qr,k);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr,k);
        else return min(query(l,mid,p<<1,ql,qr,k),query(mid+1,r,p<<1|1,ql,qr,k));
    }
} seg[2];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    seg[0].init(n,0), seg[1].init(n,1);
    for (int i = 1; i <= n; ++i) {
        int p; cin>>p;
        seg[0].mdf(1,n,1,i,p);
        seg[1].mdf(1,n,1,i,p);
    }
    int c, k, x;
    while(q--) {
        cin>>c>>k;
        if (c == 1) {
            cin>>x;
            seg[0].mdf(1,n,1,k,x);
            seg[1].mdf(1,n,1,k,x);
        } else {
            cout<<min(seg[0].query(1,n,1,k,n,k),seg[1].query(1,n,1,1,k,k))<<endl;
        }
    }
    return 0;
}
