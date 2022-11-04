#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

vector<ll> arr(200005,0), ps(200005,0);

struct Node {
    ll mx, tag;
};

struct SEGTREE {
    vector<Node> s;
    int sz;
    void setup(int l, int r, int p) {
        if (l == r) {
            s[p].mx = ps[l];
            return;
        }
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1); 
        s[p].mx = max(s[p<<1].mx,s[p<<1|1].mx);
    }
    void init(int _n) {
        sz = _n;
        s.assign(_n<<2,{0ll,0ll});
        setup(1,_n,1);
    }
    void push(int c, int p) {
        if (!s[p].tag) return;
        s[p].mx += s[p].tag;
        if (c) {
            s[p<<1].tag += s[p].tag;
            s[p<<1|1].tag += s[p].tag;
        }
        s[p].tag = 0;
    }
    void chg(int l, int r, int p, int ql, int qr, ll v) {
        push(r-l,p);
        if (ql <= l && r <= qr) {
            s[p].tag += v;
            return;
        }
        if (qr <= mid) chg(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) chg(mid+1,r,p<<1|1,ql,qr,v);
        else {
            chg(l,mid,p<<1,ql,qr,v);
            chg(mid+1,r,p<<1|1,ql,qr,v);
        }
        s[p].mx = max(s[p<<1].mx+s[p<<1].tag,s[p<<1|1].mx+s[p<<1|1].tag);
    }
    ll query(int l, int r, int p, int ql, int qr) {
        push(r-l,p);
        if (ql <= l && r <= qr) return s[p].mx;
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return max(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q, cmd; 
    ll a, b;
    cin>>n>>q;  
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        ps[i] = ps[i-1]+arr[i];
    }
    seg.init(n);
    while(q--) {
        cin>>cmd>>a>>b;
        if (cmd == 1) {
            seg.chg(1,n,1,a,n,b-arr[a]);
            arr[a] = b;
        } else {
            if (a>1) cout<<max(0ll,seg.query(1,n,1,a,b)-seg.query(1,n,1,a-1,a-1))<<endl;
            else cout<<max(0ll,seg.query(1,n,1,a,b))<<endl;
        }
    }
    return 0;
}
