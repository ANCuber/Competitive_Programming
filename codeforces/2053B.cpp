#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

struct BIT{
    vector<int> a;
    int sz;
    void init(int _n) {
        a.assign(_n+5,0);
        sz = _n;
    }
    void mdf(int p) {
        while(p <= sz) {
            a[p]++;
            p += p&-p;
        }
    }
    int sum(int p) {
        int ret = 0;
        while(p) {
            ret += a[p];
            p -= p&-p;
        }
        return ret;
    }
} bit;

void Run() {
    int n; cin>>n;
    bit.init(2*n);
    vector<pair<int,int> > a(n);
    vector<int> cnt(2*n+5,0);
    for (int i = 0; i < n; ++i) {
        cin>>a[i].first>>a[i].second;
        if (a[i].first == a[i].second && bit.sum(a[i].second)-bit.sum(a[i].second-1) == 0) bit.mdf(a[i].second);
        if (a[i].first == a[i].second) cnt[a[i].second]++;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].second == a[i].first) {
            if (cnt[a[i].second] > 1) cout<<"0";
            else cout<<"1";
        }
        if (a[i].second != a[i].first && bit.sum(a[i].second)-bit.sum(a[i].first-1) == a[i].second-a[i].first+1) cout<<"0";
        else if (a[i].second != a[i].first) cout<<"1";
    }
    cout<<'\n';
    return;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    while(t--) Run();
    return 0;
}
