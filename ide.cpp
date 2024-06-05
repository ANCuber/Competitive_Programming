#include <bits/stdc++.h>
using namespace std;


struct MAX_SEG{
    vector<int> a; 
    void init(int _n) {
        a.assign(_n<<2,0);
    }
    void mdf(int l, int r, int p, int t, int x) {
        if (l == r) {
            a[p] = x;
            return;
        }
        int mid = ((l+r)>>1);
        if (t <= mid) mdf(l,mid,p<<1,t,x);
        else mdf(mid+1,r,p<<1|1,t,x);
        a[p] = max(a[p<<1],a[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        int mid = ((l+r)>>1);
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return max(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

signed main() {
    int n, q; cin>>n>>q;
    seg.init(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x;
        seg.mdf(1,n,1,i,x);
    }
    while(q--) {
        int l, r; cin>>l>>r;
        cout<<seg.query(1,n,1,l,r)<<'\n';
    }
    return 0;
}
