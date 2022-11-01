#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const int maxn = 1e5+5;

int n;
vector<int> ans(maxn,0);

struct Point { 
    int x, y, z, id; 
    bool operator<(Point b) {
        if (x == b.x) return y < b.y;
        return x > b.x;
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

void solve(int l, int r, vector<Point> &a) {
    if (l == r) return;
    int mid = (l+r)>>1;
    solve(l,mid,a), solve(mid+1,r,a);
    int lp = l, rp = mid+1;
    vector<Point> tmp;
    while(lp <= mid && rp <= r) {
        if (a[lp].y > a[rp].y) {
            bit.upd(a[lp].z,1);
            tmp.pb(a[lp++]);
        } else {
            ans[a[rp].id] += (bit.sum(maxn)-bit.sum(a[rp].z));
            tmp.pb(a[rp++]);
        }
    }
    while(lp <= mid) {
        bit.upd(a[lp].z,1);
        tmp.pb(a[lp++]);
    }
    while(rp <= r) {
        ans[a[rp].id] += (bit.sum(maxn)-bit.sum(a[rp].z));
        tmp.pb(a[rp++]);
    }
    for (int i = l; i <= mid; ++i) bit.upd(a[i].z,-1);
    for (int i = l; i <= r; ++i) a[i] = tmp[i-l];
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    vector<Point> a(n);
    bit.init(maxn);
    for (int i = 0; i < n; ++i) {
        cin>>a[i].x>>a[i].y>>a[i].z;
        a[i].id = i;
    }
    sort(a.begin(),a.end());
    solve(0,n-1,a);
    for (int i = 0; i < n; ++i) cout<<ans[i]<<endl;
    return 0;
}
