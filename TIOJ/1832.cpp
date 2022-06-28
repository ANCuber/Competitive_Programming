#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector<ll> arr;
vector<ll> seg;
int ql, qr;

void init(int l, int r, int p) {
    if (l == r) {
        seg[p] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,p<<1);
    init(mid+1,r,p<<1|1);
    seg[p] = seg[p<<1]^seg[p<<1|1];
}

ll query(int l, int r, int p) {
    if (ql <= l && r <= qr) return seg[p];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(l,mid,p<<1);
    else if (ql > mid) return query(mid+1,r,p<<1|1);
    else return query(l,mid,p<<1)^query(mid+1,r,p<<1|1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    arr.resize(n+1);
    seg.resize(n<<2);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    init(1,n,1);
    while(q--) {
        cin>>ql>>qr;
        cout<<query(1,n,1)<<endl;
    }
    return 0;
}
