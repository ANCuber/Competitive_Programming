#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

vector<int> seg;
vector<int> h;
int n;

void init(int l, int r, int p) {
    if (l == r) {
        seg[p] = h[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,p<<1);
    init(mid+1,r,p<<1|1);
    seg[p] = min(seg[p<<1],seg[p<<1|1]);
}

int query(int ql, int qr, int l, int r, int p) {
    if (ql <= l && r <= qr) return seg[p];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,p<<1);
    else if (ql > mid) return query(ql,qr,mid+1,r,p<<1|1);
    else return min(query(ql,qr,l,mid,p<<1),query(ql,qr,mid+1,r,p<<1|1));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    seg.resize(n<<2);
    h.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>h[i];
    }
    init(1,n,1);
    int l, r;
    for (int i = 1; i <= n; ++i) {
        cin>>l>>r;
        cout<<query(l,r,1,n,1)+1<<endl;
    }
    return 0;
}
