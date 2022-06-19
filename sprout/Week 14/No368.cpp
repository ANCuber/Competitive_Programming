#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int n, q, a, b;

struct Nd{
    int mx = 0;
    int tag = 0;
    int chg = 0;
};

vector<Nd> seg;
vector<int> arr;

void init(int l, int r, int node) {
    if (l == r) {
        seg[node].mx = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    init(l,mid,node<<1);
    init(mid+1,r,node<<1|1);
    seg[node].mx = max(seg[node<<1].mx,seg[node<<1|1].mx);
}

void push(int node, int d) {
    if (seg[node].chg) {
        seg[node].mx = seg[node].chg;
        if(d) seg[node<<1].chg = seg[node<<1|1].chg = seg[node].chg;
        if(d) seg[node<<1].tag = seg[node<<1|1].tag = 0;
        seg[node].chg = 0;
    }
    if (seg[node].tag) {
        seg[node].mx += seg[node].tag;
        if(d) seg[node<<1].tag += seg[node].tag;
        if(d) seg[node<<1|1].tag += seg[node].tag;
        seg[node].tag = 0;
    }
}

int query(int l, int r, int node) {
    push(node,r-l);
    if (a <= l && r <= b) return seg[node].mx;
    int mid = (l+r)>>1;
    if (b <= mid) return query(l,mid,node<<1);
    else if (a > mid) return query(mid+1,r,node<<1|1);
    else {
        int a = query(l,mid,node<<1);
        int b = query(mid+1,r,node<<1|1);
        return max(a,b);
    }
}

void add(int l, int r, int node, int x) {
    push(node,r-l);
    if (a <= l && r <= b) {
        seg[node].tag += x;
        return;
    }
    int mid = (l+r)>>1;
    if (b <= mid) add(l,mid,node<<1,x);
    else if (a > mid) add(mid+1,r,node<<1|1,x);
    else {
        add(l,mid,node<<1,x);
        add(mid+1,r,node<<1|1,x);
    }
    int ls = (seg[node<<1].chg?seg[node<<1].chg:seg[node<<1].mx)+seg[node<<1].tag;
    int rs = (seg[node<<1|1].chg?seg[node<<1|1].chg:seg[node<<1|1].mx)+seg[node<<1|1].tag;
    seg[node].mx = max(ls,rs);
}

void change(int l, int r, int node, int x) {
    push(node,r-l);
    if (a <= l && r <= b) {
        seg[node].chg = x;
        return;
    }
    int mid = (l+r)>>1;
    if (b <= mid) change(l,mid,node<<1,x);
    else if (a > mid) change(mid+1,r,node<<1|1,x);
    else {
        change(l,mid,node<<1,x);
        change(mid+1,r,node<<1|1,x);
    }
    int ls = (seg[node<<1].chg?seg[node<<1].chg:seg[node<<1].mx)+seg[node<<1].tag;
    int rs = (seg[node<<1|1].chg?seg[node<<1|1].chg:seg[node<<1|1].mx)+seg[node<<1|1].tag;
    seg[node].mx = max(ls,rs);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    seg.resize(n<<2);
    arr.resize(n+1);
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    init(1,n,1);
    int cmd, x;
    while(q--){
        cin>>cmd>>a>>b;
        if (cmd == 1) {
            cin>>x;
            add(1,n,1,x);
        } else if (cmd == 2) {
            cout<<query(1,n,1)<<endl;
        } else {
            cin>>x;
            change(1,n,1,x);
        }
    }
    return 0;
}