#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT {
    vector <long double> a;
    int sz;
    void add(int p, long double v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    void init(int _n) {
        sz = _n;
        a.assign(_n+5,0);
    }
    long double idx(int p) {
        long double ret = 0;
        while(p > 0) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit, w;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;    
    vector<long double> v(n+5,0), ww(n+5);
    vector<int> s(n+5,0);
    for (int i = 1; i <= n; ++i) {
        cin>>v[i];
        v[i] += v[i-1];
    }
    for (int i = 1; i <= n; ++i) cin>>ww[i];
    bit.init(n), w.init(n);
    for (int i = 1; i <= n; ++i) {
        bit.add(i,1);
        w.add(i,(long double)(ww[i]));
    }
    int cmd, k, t, x, u;
    while(q--) {
        cin>>cmd;
        if (cmd == 1) {
            cin>>k;
            if (s[k]) {
                int cur = bit.idx(k);
                int l = 0, r = n;
                int mid = (l+r)>>1;
                while(r-l > 1) {
                    if(bit.idx(mid) < cur) l = mid;
                    else r = mid;
                    mid = (l+r)>>1;
                }
                int tl = 1, tr = n+1;
                int m = (tl+tr)>>1;
                while(tr-tl > 1) {
                    if (bit.idx(m) >= cur+1) tr = m;
                    else tl = m;
                    m = (tl+tr)>>1;
                }
                long double sumw = w.idx(tl)-w.idx(r-1), lw = w.idx(k)-w.idx(r-1), rw = w.idx(tl)-w.idx(k);
                long double lv = v[k]-v[r-1], rv = v[tl]-v[k];
                w.add(k,sumw*lv/(lv+rv)-lw);
                w.add(k+1,sumw*rv/(lv+rv)-rw);
                
                bit.add(k+1,1);
            } else {
                bit.add(k+1,-1);
            }
            s[k] = 1-s[k];
        } else if (cmd == 2) {
            cin>>t>>x;
            w.add(t,x);
        } else {
            cin>>u;
            int cur = bit.idx(u);
            int l = 0, r = n;
            int mid = (l+r)>>1;
            while(r-l > 1) {
                if(bit.idx(mid) < cur) l = mid;
                else r = mid;
                mid = (l+r)>>1;
            }
            int tl = 1, tr = n+1;
            int m = (tl+tr)>>1;
            while(tr-tl > 1) {
                if (bit.idx(m) >= cur+1) tr = m;
                else tl = m;
                m = (tl+tr)>>1;
            }
            long double curv = v[tl]-v[r-1], curw = w.idx(tl)-w.idx(r-1);
            cout<<(curw/curv)<<endl;
        }
    }
    return 0;
}
