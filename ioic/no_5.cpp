#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)
#define int ll

struct SEG{
    vector<int> a, tg;
    void init(int _n) {
        a.assign(_n<<2,0);
        tg.assign(_n<<2,0);
    }
    void mdf(int l, int r, int p, int ql, int qr, int v) {
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
        a[p] = ((tg[p<<1])?(mid-l+1):(a[p<<1]))+((tg[p<<1|1])?(r-mid):(a[p<<1|1]));
    }
    int query() {
        return tg[1]?(1e6+1):a[1];
    }
} seg;

struct item{
    int l, r, p, t;
    bool operator<(item b) {
        return p < b.p;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    seg.init(1e6);
    ll ans = 0;
    vector<item> v;
    for (int i = 0; i < n; ++i) {
        int l, r, d, u;
        cin>>l>>r>>d>>u;
        v.pb({l,r,u,-1});
        v.pb({l,r,d,1});
    }
    sort(v.begin(),v.end());
    int pre = v[0].p;
    for (int i = 0; i < (n<<1); ++i) {
        ans += (v[i].p-pre)*seg.query();
        pre = v[i].p;
        seg.mdf(1,1e6,1,v[i].l+1,v[i].r,v[i].t);
    }
    cout<<ans<<endl;
    return 0;
}
