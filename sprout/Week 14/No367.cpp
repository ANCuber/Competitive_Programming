#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Nd{
    int val = 0;
    int tag = 0;
    void upd(ll x) {
        val += x;
        tag += x;
    }
};

vector<Nd> seg;
int n, q;

void push(int node) {
    for (int h = __lg(n); h >= 0; --h) {
        int i = node>>h;
        if (seg[i>>1].tag) {
            seg[i].upd(seg[i>>1].tag);
            seg[i^1].upd(seg[i>>1].tag);
            seg[i>>1].tag = 0;
        }
    }
}

void pull(int node) {
    while(node>1) {
        seg[node>>1].val = max(seg[node].val,seg[node^1].val)+seg[node>>1].tag;
        node>>=1;
    }
}

void add(int l, int r, int x) {//[l,r)
    push(l+n), push(r-1+n);
    int tl = l, tr = r;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
        if (l&1) seg[l++].upd(x);
        if (r&1) seg[--r].upd(x);
    }
    pull(tl+n), pull(tr-1+n);
}

int query(int l, int r) {//[l,r)
    push(l+n), push(r-1+n);
    int res = -1;
    for (l+=n,r+=n; l<r; l>>=1,r>>=1) {
        if (l&1) res = max(res,seg[l++].val);
        if (r&1) res = max(res,seg[--r].val);
    }
    return res;
}

void init() {
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        seg[n+i].val = a;
    }
    for (int i = n-1; i >= 0; --i) {
        seg[i].val = max(seg[i<<1].val,seg[i<<1|1].val);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    seg.resize(n<<1);
    init();
    int cmd, l, r, x;
    while(q--) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>l>>r>>x;
            add(--l,r,x);
        } else {
            cin>>l>>r;
            cout<<query(--l,r)<<endl;
        }
    }
    return 0;
}