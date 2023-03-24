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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
    
    return 0;
}
