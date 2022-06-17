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
int sz = 1;
int n, q;

void push(int node) {
    
}

void pull(int node) {
    
}

void add(int l, int r, int x) {//[l,r)

}

int query(int l, int r) {//[l,r)
    
}

void init() {
    for (int i = 0; i < n; ++i) {
        int a; cin>>a;
        seg[sz+i].val = a;
    }
    for (int i = n-1; i >= 0; ++i) {
        seg[i].val = max(seg[i<<1].val,seg[i<<1|1].val);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    while(sz < n) sz <<= 1;
    seg.resize(sz<<1);
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