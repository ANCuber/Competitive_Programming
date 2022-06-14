#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n;

struct Nd{
    int val;
    int id;
};

vector<int> arr;
vector<Nd> seg;

void Merge(Nd &ret,const Nd &a,const Nd &b) {
    if (a.val > b.val) {
        ret.id = b.id;
        ret.val = b.val;
    } else {
        ret.id = a.id;
        ret.val = a.val;
    }
}

void init(int l, int r, int node) {
    if (l == r) {
        seg[node].val = arr[l];
        seg[node].id = l;
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,node<<1);
    init(mid+1,r,(node<<1)|1);
    Merge(seg[node],seg[node<<1],seg[(node<<1)|1]);
}

Nd query(int ql, int qr,int l,int r, int node) {
    if (ql <= l && r <= qr) return seg[node];
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,node<<1);
    if (ql > mid) return query(ql,qr,mid+1,r,(node<<1)|1);
    Nd ret;
    Merge(ret,query(ql,qr,l,mid,node<<1),query(ql,qr,mid+1,r,(node<<1)|1));
    return ret;
}

void output(int l, int r) {
    if (l != 1 || r != n) cout<<' ';
    if (l == r) cout<<arr[l];
    else {
        Nd cur = query(l,r,1,n,1);
        cout<<cur.val;
        if(cur.id-1 >= l) output(l,cur.id-1);
        if(cur.id+1 <= r) output(cur.id+1,r);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n && n) {
        arr.assign(n+1,0);
        seg.resize(n<<2);
        for (int i = 1; i <= n; ++i) {
            cin>>arr[i];
        }
        init(1,n,1);
        output(1,n);
        cout<<endl;
    }
    return 0;
}