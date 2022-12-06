#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int n, s, t, l, r, mid, cur;

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
} dp;

signed main() {
    scanf("%d",&n);
    dp.init(n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d",&s,&t);
        s++,t++;
        l = t, r = n+1;
        mid = (l+r)>>1;
        cur = dp.val(t);
        while(r-l > 1) {
            if (dp.val(mid) <= cur) l = mid;
            else r = mid;
            mid = (l+r)>>1;
        }
        dp.upd(s,1), dp.upd(r,-1);
    }
    printf("%d\n",dp.val(n));
    return 0;
}
