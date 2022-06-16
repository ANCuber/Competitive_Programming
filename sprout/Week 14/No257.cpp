#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int c1 = 0, c2 = 0, c3 = 0;
    int lazt = 0;
    bool rs = 0;
};

vector <Nd> seg;

Nd operator+(const Nd &a, const Nd &b) {
    Nd ret;
    ret.c1 = a.c1+b.c1;
    ret.c2 = a.c2+b.c2;
    ret.c3 = a.c3+b.c3;
    return ret;
}

void swp(Nd &ret, int tag) {
    tag %= 3;
    while(tag--) {
        swap(ret.c1,ret.c2);
        swap(ret.c1,ret.c3);
    }
}

void Merge(Nd &ret,Nd a,Nd b) {
    Nd tmp;
    if (a.rs) {
        a.c1 = a.c1+a.c2+a.c3;
        a.c2 = a.c3 = 0;
    }
    swp(a,a.lazt);
    tmp = a;
    
    if (b.rs) {
        b.c1 = b.c1+b.c2+b.c3;
        b.c2 = b.c3 = 0;
    }
    swp(b,b.lazt);
    tmp = tmp+b;

    ret = tmp;
}

void init(int l, int r, int node) {//complete
    if (l == r) {
        seg[node].c1 = 1;
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,node<<1);
    init(mid+1,r,node<<1|1);
    seg[node].c1 = seg[node<<1].c1+seg[node<<1|1].c1;
    return;
}

void push(int node,int size) {
    if (seg[node].rs) {
        seg[node].c1 = size;//deal with reset
        seg[node].c2 = seg[node].c3 = 0;

        seg[node<<1].rs = seg[node<<1|1].rs = 1;//push
        seg[node<<1].lazt = seg[node<<1|1].lazt = 0;
        seg[node].rs = 0;//reset node
    }
    if (seg[node].lazt) {
        swp(seg[node],seg[node].lazt);//deal with lazy tag

        seg[node<<1].lazt += seg[node].lazt;//push
        seg[node<<1|1].lazt += seg[node].lazt;
        seg[node].lazt = 0;//lazy[node] = 0
    }
}

void setleaf(int node) {
    if (seg[node].rs) {
        seg[node].c1 = 1;
        seg[node].c2 = seg[node].c3 = 0;
        seg[node].rs = 0;
    }
    if (seg[node].lazt) {
        swp(seg[node],seg[node].lazt);
        seg[node].lazt = 0;
    }
}

void turn(int ql, int qr, int l, int r, int node) {
    if (l != r) push(node,r-l+1);
    else setleaf(node);
    if (ql <= l && r <= qr) {
        seg[node].lazt++;
        seg[node].lazt %= 3;
        return;
    }
    int mid = (l+r)>>1;
    if (qr <= mid) turn(ql,qr,l,mid,node<<1);
    else if (ql > mid) turn(ql,qr,mid+1,r,node<<1|1);
    else {
        turn(ql,qr,l,mid,node<<1);
        turn(ql,qr,mid+1,r,node<<1|1);
    }
    Merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

void Reset(int ql, int qr, int l, int r, int node) {
    if (l != r) push(node,r-l+1);
    else setleaf(node);
    if (ql <= l && r <= qr) {
        seg[node].rs = 1;
        return;
    }
    int mid = (l+r)>>1;
    if (qr <= mid) Reset(ql,qr,l,mid,node<<1);
    else if (ql > mid) Reset(ql,qr,mid+1,r,node<<1|1);
    else {
        Reset(ql,qr,l,mid,node<<1);
        Reset(ql,qr,mid+1,r,node<<1|1);
    }
    Merge(seg[node],seg[node<<1],seg[node<<1|1]);
}

Nd query(int ql, int qr, int l, int r, int node) {
    if (l != r) push(node,r-l+1);
    else setleaf(node);
    if (ql <= l && r <= qr) {
        return seg[node];
    }
    int mid = (l+r)>>1;
    if (qr <= mid) return query(ql,qr,l,mid,node<<1);
    if (ql > mid) return query(ql,qr,mid+1,r,node<<1|1);
    Nd ret, ls, rs;
    ls = query(ql,qr,l,mid,node<<1);
    rs = query(ql,qr,mid+1,r,node<<1|1);
    Merge(ret,ls,rs);
    return ret;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    seg.resize(n<<2);
    init(1,n,1);
    while(m--) {
        string cmd; cin>>cmd;
        int a, b; cin>>a>>b;
        if (cmd[0] == 'T') {
            turn(a,b,1,n,1);
        } else if (cmd[0] == 'R') {
            Reset(a,b,1,n,1);
        } else {
            Nd cur = query(a,b,1,n,1);
            cout<<cur.c1<<endl;
        }
    }
    return 0;
}

//<<' '<<cur.c2<<' '<<cur.c3