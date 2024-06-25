#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct Cut{
    ll x; int k;
    bool operator<(Cut y) {
        return k < y.k;
    }
};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll L; 
    cin>>n>>L;
    vector<Cut> a(n);
    for (int i = 0; i < n; ++i) {
        cin>>a[i].x>>a[i].k;
    }
    sort(a.begin(),a.end());
    set<ll> s;
    s.insert(0); s.insert(L);
    ll ans = 0;
    
    for (int i = 0; i < n; ++i) {
        auto iter = s.upper_bound(a[i].x);
        int tp = *iter;
        --iter;
        ans += (tp-*iter);
        s.insert(a[i].x);
    }
    cout<<ans<<'\n';
    return 0;
}
