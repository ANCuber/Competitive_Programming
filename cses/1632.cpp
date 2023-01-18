#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct sg{
    int l, r;
    bool operator<(sg b) {
        return r < b.r;
    }
};

struct SEG {
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void push(int p, int c) {
        if (tg[p]) {
            a[p] += tg[p];
            if (c) tg[p<<1] += tg[p];
            if (c) tg[p<<1|1] += tg[p];
            tg[p] = 0;
        }
    }
    void mdf(int l, int r, int p, int ql, int qr, int v) {
        push(p,r-l);
        if (ql <= l && r <= qr) {
            tg[p] += v;
            return;
        }
        if (qr <= mid) mdf(l,mid,p<<1,ql,qr,v);
        else if (ql > mid) mdf(mid+1,r,p<<1|1,ql,qr,v);
        else {
            mdf(l,mid,p<<1,ql,qr,v);
            mdf(mid+1,r,p<<1|1,ql,qr,v);
        }
        a[p] = max(a[p<<1]+tg[p<<1],a[p<<1|1]+tg[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        push(p,r-l);
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return max(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    vector<sg> arr(n);
    set<int> s;
    map<int,int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i].l>>arr[i].r;
        s.insert(arr[i].l), s.insert(arr[i].r);
    }
    for (auto i : s) {
        mp[i] = ++cnt;
    }
    for (int i = 0; i < n; ++i) {
        arr[i].l = mp[arr[i].l], arr[i].r = mp[arr[i].r];
    }
    sort(arr.begin(),arr.end());
    seg.init(cnt+2);
    int ans = 0;
    for (auto [l,r] : arr) {
        if (seg.query(1,cnt,1,l,r-1) < k) {
            ans++;
            seg.mdf(1,cnt,1,l,r-1,1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
