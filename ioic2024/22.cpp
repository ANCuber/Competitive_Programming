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
    struct Node{
        int val, top, bot, cnt;
    };
    vector<Node> a;
    void init(int _n) {
        a.assign(_n<<2,{0,0,0,0});
    }
    void push(int p, int c) {
        if (c && a[p].cnt) {
            if (!a[p<<1].cnt) {
                a[p<<1] = a[p];
            } else {
                a[p<<1].val += (a[p<<1].top^a[p].bot)+a[p].val;
                a[p<<1].top = a[p].top;
            }
            if (!a[p<<1|1].cnt) {
                a[p<<1|1] = a[p];
            } else {
                a[p<<1|1].val += (a[p<<1|1].top^a[p].bot)+a[p].val;
                a[p<<1|1].top = a[p].top;
            }
            a[p<<1].cnt += a[p].cnt;
            a[p<<1|1].cnt += a[p].cnt;
            a[p].val = a[p].cnt = a[p].top = a[p].bot = 0;
        }
    }
    void mdf(int l, int r, int p, int ql, int qr, int x) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            //cout<<"Add:"<<l<<' '<<r<<' '<<x<<endl;
            if (!a[p].cnt) {
                a[p].bot = a[p].top = x;
            } else {
                a[p].val += a[p].top^x;
                a[p].top = x;
            }
            a[p].cnt++;
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
        push(p,r-l);
        if (l == r) return a[p].val;
        if (x <= mid) return query(l,mid,p<<1,x);
        else return query(mid+1,r,p<<1|1,x);
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, Q; cin>>N>>Q;    
    seg.init(N);
    while(Q--) {
        int c, l, r, x; cin>>c;
        if (c == 1) {
            cin>>l>>r>>x;
            seg.mdf(1,N,1,l,r,x);
        } else {
            cin>>x;
            cout<<seg.query(1,N,1,x)<<endl;
        }
    }
    return 0;
}
