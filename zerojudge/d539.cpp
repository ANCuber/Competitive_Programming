#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector <int> arr;

void built(int l, int r, int node,vector<int> &st) {
    if (l == r) {
        st[node] = arr[l];
        return;
    }
    int mid = (r+l)/2;
    built(l,mid,node<<1,st);
    built(mid+1,r,(node<<1)+1,st);
    st[node] = max(st[node<<1],st[(node<<1)+1]);
    return;
}

int query(int l, int r, int ql, int qr,int node, vector<int> &st) {
    if (ql <= l && r <= qr) return st[node];
    int mid = (l+r)/2;
    if (mid >= qr) return query(l,mid,ql,qr,node<<1,st);
    else if (ql > mid) return query(mid+1,r,ql,qr,(node<<1)+1,st);
    return max(query(l,mid,ql,qr,node<<1,st),query(mid+1,r,ql,qr,(node<<1)+1,st));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector <int> st(n<<2);
    arr.resize(n+1);
    for (int i = 1;i <= n; ++i) {
        cin>>arr[i];
    }
    built(1,n,1,st);
    int m; cin>>m;
    while(m--) {
        int a, b; cin>>a>>b;
        int l = min(a,b);
        int r = max(a,b);
        cout<<query(1,n,l,r,1,st)<<endl;
    }
    return 0;
}