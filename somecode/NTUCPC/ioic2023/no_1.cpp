#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int ll

struct Rng{
    int l, r, k;
    bool operator<(Rng b) {
        return l < b.l;
    }
};

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;
    vector<int> a(n);
    vector<Rng> rg;
    unordered_map<int,int> mp;
    for (auto& i : a) cin>>i;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            rg.pb({i,j,a[i]+a[j]});
        }
    }
    vector<vector<int> > add(rg.size()+5);
    vector<int> v(rg.size()+5,0);
    sort(rg.begin(),rg.end());
    ll ans = 0;
    for (auto [l,r,k] : rg) {
        if (!v[l]) {
            for (auto i : add[l]) mp[i]++;
            v[l] = 1;
        }
        ans += (long long)(mp[x-k]);
        add[r+1].pb(k);
    }
    cout<<ans<<endl;
    return 0;
}
