#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct BIT{
    vector<int> a; 
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void add(int p, int v) {
        while(p <= sz) {
            a[p] += v;
            p += p&-p;
        }
    }
    int query(int p) {
        int ans = 0;
        while(p) {
            ans += a[p];
            p -= p&-p;
        }
    }
} bit[];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    for (int i = 0; i <= 21; ++i) bit[i].init(n);
    while(q--) {
        char c; cin>>c;
        if (c == 'S') {
            int k; cin>>k;
        } else {
            int l, r; cin>>l>>r;
            
        }
    }
    return 0;
}
