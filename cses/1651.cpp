#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct BIT{
    vector<int> d;
    int sz;
    void init(int _n) {
        sz = _n;
        d.assign(_n,0);
    }
    void upd(int p, int v) {
        while(p <= sz) {
            d[p] += v;
            p += p&-p;
        }
    }
    int val(int p) {
        int ret = 0;
        while(p > 0) {
            ret += d[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    bit.init(n);
    int pre = 0, a;
    for (int i = 1; i <= n; ++i) {
        cin>>a;
        bit.upd(i,a-pre);
        pre = a;
    }
    int cmd, b, u, k;
    while(q--) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>a>>b>>u;
            bit.upd(a,u);
            bit.upd(b+1,-u);
        } else {
            cin>>k;
            cout<<bit.val(k)<<endl;
        }
    }
    return 0;
}
