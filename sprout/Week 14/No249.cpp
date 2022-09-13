#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

struct Nd{
    ll lmax; 
    ll rmax;
    ll maxsum;
    ll sum;
};

vector <ll> arr;
vector <Nd> seg;
ll qans = -1e12;

inline void merge(Nd &New, Nd lt, Nd rt) {
    New.sum = lt.sum+rt.sum;
    New.maxsum = max({lt.maxsum,rt.maxsum,lt.rmax+rt.lmax});
    New.lmax = max(lt.lmax,lt.sum+rt.lmax);
    New.rmax = max(rt.rmax,rt.sum+lt.rmax);
}

void init(int l, int r, int node) {
    if (l == r) {
        seg[node].lmax = seg[node].rmax = seg[node].maxsum = seg[node].sum = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,node<<1);
    init(mid+1,r,(node<<1)|1);
    merge(seg[node],seg[node<<1],seg[(node<<1)|1]);
    return;
}

Nd query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,node<<1);
    if (ql > mid) return query(ql,qr,mid+1,r,(node<<1)|1);
    Nd lt, rt, ret;
    lt = query(ql,qr,l,mid,node<<1);
    rt = query(ql,qr,mid+1,r,(node<<1)|1);
    merge(ret,lt,rt);
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    arr.resize(n+1);
    seg.resize(n<<2);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    init(1,n,1);
    while(q--) {
        int ql, qr; cin>>ql>>qr;
        Nd cur = query(ql,qr,1,n,1);
        cur.maxsum = max(0LL,cur.maxsum);
        cout<<cur.maxsum<<endl;
    }
    return 0;
}