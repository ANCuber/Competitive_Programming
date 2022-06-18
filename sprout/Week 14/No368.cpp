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

void Merge(Nd &ret, Nd &a, Nd &b) {

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

Nd query(int l, int r, int node) {

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
    
}

void change(int l, int r, int node, int x) {

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

        } else {
            cin>>x;

        }
    }
}