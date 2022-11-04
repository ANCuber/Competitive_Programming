#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT {
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
    int ask(int p) {
        int ret = 0;
        while(p > 0) {
            ret += a[p];
            p -= p &-p;
        }
        return ret;
    }
} bit;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    bit.init(n);
    vector<int> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin>>arr[i];
        bit.upd(i,1);
    }
    for (int i = 0; i < n; ++i) {
        int x; cin>>x;
        int l = 0, r = n;
        int mid = (l+r)>>1;
        while(r-l > 1) {
            if (bit.ask(mid) < x) l = mid;
            else r = mid;
            mid = (l+r)>>1;
        }
        if (i) printf(" ");
        printf("%d",arr[r]);
        bit.upd(r,-1);
    }
    return 0;
}
