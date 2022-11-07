#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

ll arr[200005];

struct Node {
    ll val, tag, res;
};

struct SEGTREE {
    vector<Node> a;
    void setup(int l, int r, int p) {
        if (l == r) {
            a[p].val = arr[l]; 
            return;
        }
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1);
        a[p].val = a[p<<1].val+a[p<<1|1].val;
    }
    void init(int _n) {
        a.assign(_n<<2,{0,0,0});
        setup(1,_n,1);
    }
    void push(int p, ll c) {
        if (a[p].res) {
            a[p].val = a[p].res*(c+1);
            if (c) {
                a[p<<1].res = a[p<<1|1].res = a[p].res;
                a[p<<1].tag = a[p<<1|1].tag = 0;
            }
            a[p].res =  0;
        }
        if (a[p].tag) {
            a[p].val += a[p].tag*(c+1);
            if (c) {
                a[p<<1].tag += a[p].tag;
                a[p<<1|1].tag += a[p].tag;
            }
            a[p].tag = 0;
        }
    }
    void merge(int p, ll lc, ll rc) {
        a[p].val = 0;
        a[p].val += (((a[p<<1].res)?(a[p<<1].res*lc):(a[p<<1].val))+a[p<<1].tag*lc);
        a[p].val += (((a[p<<1|1].res)?(a[p<<1|1].res*rc):(a[p<<1|1].val))+a[p<<1|1].tag*rc);
    }
    void add(int l, int r, int p, int ql, int qr, ll v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            a[p].tag += v;
            return;
        }
        if (qr <= mid) add(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) add(mid+1,r,p<<1|1,ql,qr,v);
        else {
            add(l,mid,p<<1,ql,qr,v);
            add(mid+1,r,p<<1|1,ql,qr,v);
        }
        merge(p,mid-l+1,r-mid);
    }
    void chg(int l, int r, int p, int ql, int qr, ll v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            a[p].res = v;
            return;
        }
        if (qr <= mid) chg(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) chg(mid+1,r,p<<1|1,ql,qr,v);
        else {
            chg(l,mid,p<<1,ql,qr,v);
            chg(mid+1,r,p<<1|1,ql,qr,v);
        }
        merge(p,mid-l+1,r-mid);
    }
    ll query(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p].val;
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
    ll cmd, l, r, k;
    while(q--) {
        cin>>cmd>>l>>r;
        if (cmd == 1) {
            cin>>k;
            seg.add(1,n,1,l,r,k);
        } else if (cmd == 2) {
            cin>>k;
            seg.chg(1,n,1,l,r,k);
        } else {
            cout<<seg.query(1,n,1,l,r)<<endl;
        }
    }
    return 0;
}
