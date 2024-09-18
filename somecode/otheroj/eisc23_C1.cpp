#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

const int mod = 1e9+7;

struct Result{
    int uv, usm, vsm;
};

inline Result add(Result a, Result b) {
    return {a.uv+b.uv,a.usm+b.usm,a.vsm+b.vsm};
}


struct SEG{
    vector<int> u, v, mul, utg, vtg, usq, vsq;
    void init(int _n) {
        u.assign(_n<<2,0);
        v.assign(_n<<2,0);
        mul.assign(_n<<2,0);
        utg.assign(_n<<2,0);
        vtg.assign(_n<<2,0);
        usq.assign(_n<<2,0);
        vsq.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (vtg[p]) {
            
        }
        if (utg[p]) {
            
        }
    }
    void mdf(int l, int r, int p, int ql, int qr, int k, int t) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            if (!t) utg[p] += k;
            else vtg[p] += k;
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr,k,t);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr,k,t);
        else {
            
        }
    }
    Result query(int l, int r, int p, int ql, int qr) {
        Result ret;
        push(p,r-l);
        if (ql <= l && r <= qr) return {mul[p],usq[p],vsq[p]};
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return add(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    seg.init(n);
    char cmd;
    int l, r, x;
    while(cin>>cmd) {
        if (cmd == '?') {
            
        } else if (cmd == 'g') {
            
        } else { 
            
        }
    }
    return 0;
}
