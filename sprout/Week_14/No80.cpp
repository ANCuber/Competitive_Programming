#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <int> arr;
vector <int> sg;

int init(int l, int r, int node) {
    if (l == r) {
        sg[node] = arr[l];
        return sg[node];
    }
    int mid = (l+r)>>1;
    return sg[node] = min(init(l,mid,node<<1),init(mid+1,r,(node<<1)+1));
}

int query(int ql, int qr, int l, int r, int node) {
    if (ql <= l && r <= qr) return sg[node];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,node<<1);
    if (ql > mid) return query(ql,qr,mid+1,r,(node<<1)+1);
    return min(query(ql,qr,l,mid,node<<1),query(ql,qr,mid+1,r,(node<<1)+1));
}

void update(int l, int r, int node, int tar, int v) {
    if (l == r) {
        sg[node] = v;
        return;
    }
    int mid = (l+r)>>1;
    if (tar <= mid) update(l,mid,node<<1,tar,v);
    if (tar > mid)  update(mid+1,r,(node<<1)+1,tar,v);
    sg[node] = min(sg[node<<1],sg[(node<<1)+1]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n; cin>>t>>n;
    arr.resize(n+1);
    sg.resize(n<<2);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
    }
    init(1,n,1);
    while(t--) {
        int c, x, y;
        cin>>c>>x>>y;
        x++;
        if (c == 1) {
            y++;
            cout<<query(x,y,1,n,1)<<endl;
        } else {
            update(1,n,1,x,y);
        }
    }
    return 0;
}

/* 6 5
2 3 5 1 4
1 0 1
1 2 4
2 0 5
2 2 2
1 0 1
1 2 4
 */