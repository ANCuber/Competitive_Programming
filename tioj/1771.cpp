#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back
#define int long long

const int maxn = 1e5+1;
int n, m, x;
vector<int> ans(100005,0);

struct node{
    int p, v, t = 0;
    bool operator<(node b) {
        if (t == b.t) return p < b.p;
        return t < b.t;
    }
};

struct BIT {
    vector<int> arr;
    int sz;
    void init(int _n) {
        sz = _n;
        arr.assign(sz+5,0);
    }
    void upd(int p, int v) {
        while(p <= sz) {
            arr[p] += v;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p > 0) {
            ret += arr[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

//ti >= tj, pi > pj, vi < vj
void solve1(int l, int r, vector<node> &a) {
    if (l == r) return;
    int mid = (l+r)>>1;
    solve1(l,mid,a), solve1(mid+1,r,a);
    int lp = l, rp = mid+1;
    vector<node> tmp;
    while(lp <= mid && rp <= r) {
        if (a[lp].p < a[rp].p) {
            bit.upd(a[lp].v,1);
            tmp.pb(a[lp++]);
        } else {
            ans[a[rp].t] += bit.sum(maxn)-bit.sum(a[rp].v);
            tmp.pb(a[rp++]);
        }
    }
    while(lp <= mid) {
        bit.upd(a[lp].v,1);
        tmp.pb(a[lp++]);
    }
    while(rp <= r) {
        ans[a[rp].t] += bit.sum(maxn)-bit.sum(a[rp].v);
        tmp.pb(a[rp++]);
    }
    for (int i = l; i <= mid; ++i) bit.upd(a[i].v,-1);
    for (int i = l; i <= r; ++i) a[i] = tmp[i-l];
}

//ti >= tj, pi < pj, vi > vj
void solve2(int l, int r, vector<node> &a) {
    if (l == r) return;
    int mid = (l+r)>>1;
    solve2(l,mid,a), solve2(mid+1,r,a);
    int lp = l, rp = mid+1;
    vector<node> tmp;
    while(lp <= mid && rp <= r) {
        if (a[lp].p > a[rp].p) {
            bit.upd(a[lp].v,1);
            tmp.pb(a[lp++]);
        } else {
            ans[a[rp].t] += bit.sum(a[rp].v-1);
            tmp.pb(a[rp++]);
        }
    }
    while(lp <= mid) {
        bit.upd(a[lp].v,1);
        tmp.pb(a[lp++]);
    }
    while(rp <= r) {
        ans[a[rp].t] += bit.sum(a[rp].v-1);
        tmp.pb(a[rp++]);
    }
    for (int i = l; i <= mid; ++i) bit.upd(a[i].v,-1);
    for (int i = l; i <= r; ++i) a[i] = tmp[i-l];
}

signed main() {
    scanf("%lld%lld",&n,&m);
    vector<node> a(n);
    vector<int> pos(n+1);
    bit.init(maxn);
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&a[i].v);
        a[i].p = pos[a[i].v] = i;
    }
    for (int i = m; i > 0; --i) {
        scanf("%lld",&x);
        a[pos[x]].t = i;
    }
    sort(a.begin(),a.end());
    solve1(0,n-1,a);
    sort(a.begin(),a.end());
    solve2(0,n-1,a);
    for (int i = 1; i <= m; ++i) ans[i] += ans[i-1];
    for (int i = m; i > 0; --i) printf("%lld\n",ans[i]);
    return 0;
}
