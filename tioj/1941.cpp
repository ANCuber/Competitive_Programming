#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define mid ((l+r)>>1)

int n, s, t, tmp, nx, cl;

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void upd(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int val(int p) {
        int ret = 0;
        while(p > 0) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} dp, lp, rp;

signed main() {
    scanf("%d",&n);
    dp.init(), lp.init(), rp.init();
    rp.upd(1,n);
    lp.upd(1,1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&s,&t);
        s++,t++;
        tmp = rp.val(t);
        cl = lp.val(s);
        rp.upd(cl,(s-1)-rp.val(cl)), rp.upd(s,rp.val(cl)-s+1);
        lp.upd(s,), lp.upd();

        if (tmp < n) nx = rp.val(tmp+1);
        else nx = n;
        
        dp.upd(s,1), dp.upd(tmp+1,-1);
        rp.upd(), rp.upd();
        
    }
    printf("%d\n",dp.val(n));
    return 0;
}
