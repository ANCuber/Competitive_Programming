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
    struct Node{
        int lmx, rmx, ans, sum;
    };
    vector<Node> a;
    void init(int _n) {
        a.assign(_n<<2,{0,0,0,0});
    }
    void merge(int p) {
        a[p].lmx = max(a[p<<1].lmx,a[p<<1].sum+a[p<<1|1].lmx);
        a[p].rmx = max(a[p<<1|1].rmx,a[p<<1|1].sum+a[p<<1].rmx);
        a[p].sum = a[p<<1].sum+a[p<<1|1].sum;
        a[p].ans = max({a[p<<1].ans,a[p<<1|1].ans,a[p<<1].rmx+a[p<<1|1].lmx});
    }
    void mdf(int l, int r, int p, int k, int x) {
        if (l == r) {
            a[p].sum = x;
            a[p].ans = a[p].lmx = a[p].rmx = max(0ll,x);
            return;
        }
        if (k <= mid) mdf(l,mid,p<<1,k,x);
        else if (k > mid) mdf(mid+1,r,p<<1|1,k,x);
        merge(p);
    }
} seg;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    seg.init(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin>>x;
        seg.mdf(1,n,1,i,x);
    }
    while(m--) {
        int k, x; cin>>k>>x;
        seg.mdf(1,n,1,k,x);
        cout<<seg.a[1].ans<<endl;
    }
    return 0;
}
