#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a;
    int sz, lg;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
        lg = __lg(_n);
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int query(int k) {
        int s = 0, p = 0;
        for (int i = lg; i >= 0; --i) {
            if (p+(1<<i) < sz && s+a[p+(1<<i)] < k) {
                s += a[p+(1<<i)];
                p += (1<<i);
            }
        }
        return p+1;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;    
    int sz = 1<<(__lg(n)+1);
    int p = 0;
    bit.init(sz);
    for (int i = 1; i <= n; ++i) bit.add(i,1);
    for (int i = n; i >= 1; --i) {
        p = (p+k)%i;
        int cur = bit.query(p+1);
        if (i != n) cout<<' ';
        cout<<cur;
        //cout<<' '<<p<<endl;
        bit.add(cur,-1);
    }
    cout<<endl;
    return 0;
}
