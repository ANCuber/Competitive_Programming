#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define mid ((l+r)>>1)

int arr[200005];

inline int sum(int a, int d, int n) {
    return n*(a+(a+d*(n-1)))/2;
}

struct SEG{
    vector<int> a, tg, d;
    void setup(int l, int r, int p) {
        if (l == r) {
            a[p] = arr[l];
            return;
        }
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1); 
        a[p] = a[p<<1]+a[p<<1|1];
    }
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
        d.assign(_n<<2,0);
        setup(1,_n,1);
    }
    void push(int p, int c, int k) {
        if (tg[p]) {
            a[p] += sum(tg[p],d[p],c+1);
            if (c) {
                tg[p<<1] += tg[p];
                d[p<<1] += d[p];
                tg[p<<1|1] += (tg[p]+k*(d[p]));
                d[p<<1|1] += d[p];
            }
            d[p] = tg[p] = 0;
        }
    }
    void mdf(int l, int r, int p, int ql, int qr) {
        push(p,r-l,mid+1-l);
        if (ql <= l && r <= qr) {
            tg[p] += (l-ql+1);
            d[p]++;
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr);
        else {
            mdf(l,mid,p<<1,ql,qr);
            mdf(mid+1,r,p<<1|1,ql,qr);
        }
        a[p] = a[p<<1]+a[p<<1|1]+sum(tg[p<<1],d[p<<1],mid+1-l)+sum(tg[p<<1|1],d[p<<1|1],r-mid);
    }
    int query(int l, int r, int p, int ql, int qr) {
        push(p,r-l,mid+1-l);
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return query(l,mid,p<<1,ql,qr)+query(mid+1,r,p<<1|1,ql,qr);
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    seg.init(n);
    while(q--) {
        int cmd, a, b;
        cin>>cmd>>a>>b;
        if (cmd == 1) {
            seg.mdf(1,n,1,a,b);
        } else {
            //for(int i = 1; i <= n; ++i) cout<<seg.query(1,n,1,i,i)<<' '; cout<<endl;
            cout<<seg.query(1,n,1,a,b)<<endl;
            /*int cur = 0;
            for (int i = a; i <= b; ++i) cur += seg.query(1,n,1,i,i);
            cout<<cur<<endl;*/
        }
    }
    return 0;
}
