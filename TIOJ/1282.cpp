#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

const int MAX = 1e5+5;

struct Node{int gcd, val;};

int a[MAX] = {0}, d[MAX] = {0};
int n, q, ql, qr, k, cmd;
Node seg[MAX<<2];

void merge(int p) {
    seg[p].gcd = __gcd(seg[p<<1],seg[p<<1|1]);
    seg[p].val = seg[p<<1].val+seg[p<<1|1].val;
}

void init(int p, int l, int r) {
    if (l == r) {
        seg[p].val = seg[p].gcd = d[l];
        return;
    }
    int mid = (l+r)>>1;
    init(p<<1,l,mid), init(p<<1|1,mid+1,r);
    merge(p);
}

void chg(int p, int l, int r, int tar) {
    if (l == r) {
        seg[p].val += tar;
        seg[p].gcd += tar;
        return 0;
    }
    int mid = (l+r)>>1;
    if (qr <= mid) chg(p<<1,l,mid,tar);
    else chg(p<<1|1,mid+1,r,tar);
    merge(p);
}

Node query(int p, int l, int r) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>q;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        d[i] = a[i]-a[i-1];
    }
    init(1,1,n);
    while(q--) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>ql>>qr>>k;
        } else {
            cin>>ql>>qr;
        }
    }
    return 0;
}
