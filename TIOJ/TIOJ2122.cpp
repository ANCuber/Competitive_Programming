#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int hp;
    int x;
};

vector<int> arr;
vector<Nd> seg;

void merge(Nd &tar,const Nd &lt,const Nd &rt) {
    if (lt.x == rt.x) {
        tar.x = lt.x;
        tar.hp = lt.hp+rt.hp;
        return;
    }
    if (lt.hp >= rt.hp) {//hes
        tar.x = lt.x;
        tar.hp = lt.hp-rt.hp;
    } else {
        tar.x = rt.x;
        tar.hp = rt.hp-lt.hp;
    }
    return;
}

void init(int l, int r, int node) {
    if (l == r) {
        seg[node].hp = 1;
        seg[node].x = arr[l];
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
    Nd ret;
    merge(ret,query(ql,qr,l,mid,node<<1),query(ql,qr,mid+1,r,(node<<1)|1));
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin>>n>>q;
    arr.resize(n+1);
    seg.resize(n<<2);
    vector<vector<int> > p(100005);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        p[arr[i]].emplace_back(i);
    }
    init(1,n,1);
    int ql, qr;
    while(q--) {
        cin>>ql>>qr;
        Nd cur = query(ql,qr,1,n,1);
        auto al = lower_bound(p[cur.x].begin(),p[cur.x].end(),ql);
        auto ar = upper_bound(p[cur.x].begin(),p[cur.x].end(),qr);
        cout<<ar-al<<endl;
    }
    return 0;
}