#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int,int>
#define pll pair<ll,ll>
#define p_q priority_queue

int n, t, k;
vector<int> a;
vector<int> bit;

struct Mid{
    int lrg, sml;
};

void add(int p) {
    while(p <= 1e5) {
        bit[p]++;
        p += (p&-p);
    }
}

int query(int p) {
    int ret = 0;
    while(p > 0) {
        ret += bit[p];
        p -= (p&-p);
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n;
        k = 0;
        a.assign(n+1,0);
        bit.assign(1e5+5,0);
        vector<Mid> m(n+1);
        for (int i = 1; i <= n; ++i) cin>>a[i];
        for (int i = 1; i <= n; ++i) {
            add(a[i]);
            m[i].sml = query(a[i]-1);
            m[i].lrg = i-m[i].sml-1;
        }
        bit.assign(1e5+5,0);
        for (int i = n; i > 0; --i) {
            add(a[i]);
            int cur = query(a[i]-1);
            k += cur*m[i].lrg;
            k += m[i].sml*((n-i)-cur);
        }
        cout<<k<<endl;
    }
    return 0;
}
