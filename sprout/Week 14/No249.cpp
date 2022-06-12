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

inline void merge(Nd &New, Nd a, Nd b) {
    New.sum = a.sum+b.sum;
    New.maxsum = max({a.maxsum,b.maxsum,a.rmax+b.lmax});
    New.lmax = max(a.lmax,a.sum+b.lmax);
    New.rmax = max(b.rmax,b.sum+a.rmax);
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
    
}

int main() {
    int n, q; cin>>n>>q;
    arr.resize(n+1);
    seg.resize(n<<2);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    init(1,n,1);    
    while(q--) {
        int ql, qr; cin>>ql>>qr;

    }
}