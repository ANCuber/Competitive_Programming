#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

const int mod = 1e9+7;

struct SEG{
    vector<int> a, mul;
    void merge(int p) {
        mul[p] = mul[p<<1]*mul[p<<1|1]%mod;
        a[p] = __gcd(a[p<<1],a[p<<1|1]);
    }
    void setup(int l, int r, int p, vector<int> &c) {
        if (l == r) {
            a[p] = c[l];
            mul[p] = c[l];
            return;
        }
        setup(l,mid,p<<1,c), setup(mid+1,r,p<<1|1,c);
        merge(p);
    }
    void init(int _n, vector<int> &c) {
        a.assign(_n<<2,0);
        mul.assign(_n<<2,0);
        setup(1,_n,1,c);
    }
    pii query(int l, int r, int p, int ql, int qr) {
        if (l == r) return {a[p],mul[p]};
        if (qr <= mid) return query(l,mid,p<<1,ql,qr);
        else if (ql > mid) return query(mid+1,r,p<<1|1,ql,qr);
        else {
            pii lc = query(l,mid,p<<1,ql,qr);
            pii rc = query(mid+1,r,p<<1|1,ql,qr);
            return {__gcd(lc.first,rc.first),lc.second*rc.second%mod};
        }
    }
} seg;

int power(int x, int k) {
    int ans = 1, bs = x;
    while(k) {
        if (k&1) ans = ans*bs%mod;
        bs = bs*bs%mod;
        k >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector<int> c(n+2);
    for (int i = 1; i <= n; ++i) cin>>c[i];
    seg.init(n,c);
    while(q--) {
        int l, r; cin>>l>>r;
        pii cur = seg.query(1,n,1,l,r);
        cout<<cur.second*power(cur.first,mod-2)%mod<<endl;
    }
    return 0;
}
