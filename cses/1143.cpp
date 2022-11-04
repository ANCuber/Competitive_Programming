#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, m, q;
int arr[200005];

struct SEGTREE{
    vector<int> s;
    int sz;
    void setup(int l, int r, int p) {
        if (l == r) {
            s[p] = arr[l];
            return;
        }
        int mid = (l+r)>>1;
        setup(l,mid,p<<1), setup(mid+1,r,p<<1|1);
        s[p] = max(s[p<<1],s[p<<1|1]);
    }
    void init(int _n) {
        sz = _n;
        s.assign(_n<<2,0);
        setup(1,_n,1);
    }
    void upd(int l, int r, int tar, int p, int v) {
        if (l == r) {
            s[p] -= v;
            return;
        }
        int mid = (l+r)>>1;
        if (tar <= mid) upd(l,mid,tar,p<<1,v);
        else upd(mid+1,r,tar,p<<1|1,v);
        s[p] = max(s[p<<1],s[p<<1|1]);
    }
    int query(int l, int r, int ql, int qr, int p) {
        if (ql <= l && r <= qr) return s[p];
        int mid = (l+r)>>1;
        if (qr <= mid) return query(l,mid,ql,qr,p<<1);
        else if (ql > mid) return query(mid+1,r,ql,qr,p<<1|1);
        else return max(query(l,mid,ql,qr,p<<1),query(mid+1,r,ql,qr,p<<1|1));
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>m;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) cin>>arr[i];
    seg.init(n);
    while(m--) {
        cin>>q;
        int l = 0, r = n+1;
        int mid = (l+r)>>1;
        while(r-l > 1) {
            if(seg.query(1,n,1,mid,1) < q) l = mid;
            else r = mid;
            mid = (l+r)>>1;
        }
        if (r == n+1) ans.pb(0);
        else {
            ans.pb(r);
            seg.upd(1,n,r,1,q);
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        if (i) cout<<' ';
        cout<<ans[i];
    }
    return 0;
}
