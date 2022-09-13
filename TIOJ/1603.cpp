#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Nd {
    ll maxn;
    ll minn;
};

vector < ll > h;
vector <Nd> seg; 

void init(int l, int r, int p) {
    if (l == r) {
        seg[p].maxn = h[l];
        seg[p].minn = h[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,p<<1);
    init(mid+1,r,p<<1|1);
    seg[p].maxn = max(seg[p<<1].maxn,seg[p<<1|1].maxn);
    seg[p].minn = min(seg[p<<1].minn,seg[p<<1|1].minn);
    return;
}

Nd query(int ql, int qr, int l, int r, int p) {
    if (ql <= l && r <= qr) return seg[p];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,p<<1);
    else if (ql > mid) return query(ql,qr,mid+1,r,p<<1|1);
    else {
        Nd ret, ls, rs;
        ls = query(ql,qr,l,mid,p<<1);
        rs = query(ql,qr,mid+1,r,p<<1|1);
        ret.maxn = max(ls.maxn,rs.maxn);
        ret.minn = min(ls.minn,rs.minn);
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    h.resize(n+1);
    seg.resize(n<<2);
    for (int i = 1; i <= n; ++i) {
        cin>>h[i];
    }
    init(1,n,1);
    int ql, qr;
    while(m--) {
        cin>>ql>>qr;
        Nd cur = query(ql,qr,1,n,1);
        cout<<cur.maxn-cur.minn<<endl;
    }
    return 0;
}
