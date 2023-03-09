#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

struct SEG{
    vector<int> a;
    void init(int _n) {
        a.assign(_n<<2,-1e18);
    }
    void add(int l, int r, int p, int tar, int v) {
        if (l == r) {
            a[p] = v;
            return;
        }
        if (tar <= mid) add(l,mid,p<<1,tar,v);
        else add(mid+1,r,p<<1|1,tar,v);
        a[p] = max(a[p<<1],a[p<<1|1]);
    }
    int query(int l, int r, int p, int ql, int qr) {
        if (ql <= l && r <= qr) return a[p];
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else return max(query(l,mid,p<<1,ql,qr),query(mid+1,r,p<<1|1,ql,qr));
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, a, b;
    cin>>n>>a>>b;
    seg.init(n);
    vector<int> arr(n+1,0);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        arr[i] += arr[i-1];
        seg.add(1,n,1,i,arr[i]);
    }
    int ans = -1e18;
    for (int i = 1; i+a-1 <= n; ++i) {
        int cur = seg.query(1,n,1,i+a-1,min(i+b-1,n));
        ans = max(ans,cur-arr[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
