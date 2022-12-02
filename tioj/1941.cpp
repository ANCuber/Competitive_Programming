#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int n, s, t;
pii dp0, dp1;

struct SEGTREE{
    vector<int> a;
    vector<int> id;
    int sz = _n;
    void setup(int l, int r, int p) {
        if (l == r) {
            a[p] = 0, id[p] = l;
            return;
        }
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1);
        a[p] = 0, id[p] = l;
    }
    void init(int _n) {
        a.assign(_n<<2,0);
        id.assign(_n<<2,0);
        sz = _n;
        setup(1,n,1);
    }
    void upd(int l, int r, int p, int tar, int v) {
        if (l == r) {
            a[p] = v;
            return;
        }
        if (tar <= mid) upd(l,mid,p<<1,tar,v);
        else upd(mid+1,r,p<<1|1,tar,v);
        if (a[p<<1] >= a[p<<1|1]) {
            a[p] = a[p<<1];
            id[p] = id[p<<1];
        } else {
            a[p] = a[p<<1|1];
            id[p] = id[p<<1|1];
        }
    }
    pii mxval(int l, int r, int p, int ql, int qr) {
        
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;  
    seg.init(n+2);
    for (int i = 1; i <= n; ++i) {
        cin>>s>>t;
        s++, t++;
        dp0 = seg.mxval(1,n,1,1,s-1);
        dp1 = seg.mxval(1,n,1,1,t);
        
    }
    
    return 0;
}
