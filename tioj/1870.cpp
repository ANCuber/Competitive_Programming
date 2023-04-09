#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1);

struct SEG{
    vector<int> a;
    vector<bool> tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            
        }
    }
    void mdf(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) {
            tg[p] != tg[p];
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr);
        else {
            mdf(l,mid,p<<1,ql,qr);
            mdf(mid+1,r,p<<1|1,ql,qr);
        }
        
    }
    void query(int l, int r, int p, int ql, int qr) {
        
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    int q; cin>>q;
    int c, l, r, x;
    while(q--) {
        cin>>c>>l>>r;
        if (i == 1) {
            
        } else {
            cin>>x;
        }
    }
    
    return 0;
}
