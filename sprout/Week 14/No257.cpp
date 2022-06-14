#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int c1 = 0, c2 = 0, c3 = 0;
    int lazt = 0;
    bool reset = 0;
};

vector <Nd> seg;

inline void Merge(Nd &ret,const Nd &a,const Nd &b) {
    ret.c1 = a.c1+b.c1;
    ret.c2 = a.c2+b.c2;
    ret.c3 = a.c3+b.c3;
}

void init(int l, int r, int node) {
    if (l == r) {
        seg[node].c1 = 1;
        return;
    }
    int mid = (l+r)/2;
    init(l,mid,node<<1);
    init(mid+1,r,(node<<1)|1);
    seg[node].c1 = seg[node<<1].c1+seg[(node<<1)|1].c1;
    return;
}

Nd turn(int ql, int qr, int l, int r, int node) {
    if (ql <= l && r <= qr) {
        swap(seg[node].c1,seg[node].c2);
        swap(seg[node].c1,seg[node].c3);
        seg[node].lazt++;
        return seg[node];
    }
    int mid = (l+r)>>1;
    if (qr <= mid) return turn(ql,qr,l,mid,node<<1);
    if (ql > mid) return turn(ql,qr,mid+1,r,(node<<1)|1);
    Merge(seg[node],turn(ql,qr,l,mid,node<<1),turn(ql,qr,mid+1,r,(node<<1)|1));
    return seg[node];
}

int reset(int ql, int qr, int l, int r, int node) {
    if (ql <= l && r <= qr) {
        
    }
}

int query(int ql, int qr, int l, int r, int node) {

}

int main() {
    int n, m; cin>>n>>m;
    seg.resize(n<<2);
    init(1,n,1);
    while(m--) {
        string cmd; cin>>cmd;
        int a, b; cin>>a,b;
        if (cmd[0] == 'T') {

        } else if (cmd[0] == 'R') {

        } else {

        }
    }
    return 0;
}