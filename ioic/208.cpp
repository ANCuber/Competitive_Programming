#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll
#define mid ((l+r)>>1)

struct SEG{
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] += tg[p]*(c+1);
            if (c) {
                tg[p<<1] += tg[p];
                tg[p<<1|1] += tg[p];
            }
            tg[p] = 0;
        }
    }
    void add(int l, int r, int p, int ql, int qr, int v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] += v;
            return;
        }
        if (qr <= mid) add(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) add(mid+1,r,p<<1|1,ql,qr,v);
        else {
            add(l,mid,p<<1,ql,qr,v);
            add(mid+1,r,p<<1|1,ql,qr,v);
        }
        a[p] = tg[p<<1]*(mid+1-l)+tg[p<<1|1]*(r-mid)+a[p<<1]+a[p<<1|1];
    }
    int sum(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p]+tg[p]*(r-l+1);
        if (qr <= mid) return sum(l,mid,p<<1,ql,qr);
        else if (ql > mid) return sum(mid+1,r,p<<1|1,ql,qr);
        else return sum(l,mid,p<<1,ql,qr)+sum(mid+1,r,p<<1|1,ql,qr);
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    seg.init(n);
    for (int i = 1; i <= n; ++i) {
        int a; cin>>a;
        seg.add(1,n,1,i,i,a);
    }
    while(q--) {
        int c, l, r, d;
        cin>>c>>l>>r;
        if (c == 1) {
            cin>>d;
            seg.add(1,n,1,l,r,d);
        } else {
            cout<<seg.sum(1,n,1,l,r)<<endl;
        }
    }
    
    return 0;
}
