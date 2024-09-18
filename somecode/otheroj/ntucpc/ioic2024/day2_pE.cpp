#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct SEG{
    vector<int> a, tp, tg, plc;
    void init(int _n) {
        a.assign(_n<<2,0);
        tp.assign(_n<<2,0);
        tg.assign(_n<<2,0);
        plc.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (plc[p]) {
            if (c) {
                tg[p<<1] += tp[p<<1]^tp[p];
                tp[p<<1] = tp[p];
                tg[p<<1|1] += tp[p<<1|1]^tp[p];
                tp[p<<1] = tp[p];
            }
        }
    }
    void mdf(int l, int r, int p, int ql, int qr, int x) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            plc[p] = 1;
            tp[p] = x;
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr,x);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr,x);
        else {
            mdf(l,mid,p<<1,ql,qr,x);
            mdf(mid+1,r,p<<1|1,ql,qr,x);
        }
    }
    int query(int l, int r, int p, int x) {
        push();
        if (l == r) return a[p];
    }

} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;
    while(Q--) {
        int cmd; cin>>cmd;
        if (cmd == 1) {
            int l, r, x; cin>>l>>r>>x;
            
        } else {
            int p; cin>>p;
            
        }
    }
    return 0;
}
