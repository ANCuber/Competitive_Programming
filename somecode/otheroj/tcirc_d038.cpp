#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

inline long double cmp(pii x, pii y) {
    return 1.0*(x.second-y.second)/(y.first-x.first);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    vector< pii > a(n);
    vector<pair<long double, int> > stk;
    for (int i = 0; i < n; ++i) cin>>a[i].first>>a[i].second;
    sort(a.begin(),a.end());
    for (int i = 0; i < n; ++i) {
        while(!stk.empty() && a[i].first == a[stk.back().second].first) stk.pop_back();
        if (stk.empty()) {
            stk.pb({-1e8,i});
        } else {
            while(!stk.empty() && cmp(a[i],a[stk.back().second]) <= stk.back().first) {
                stk.pop_back();
            }
            stk.pb({stk.empty()?(-1e8):cmp(a[i],a[stk.back().second]),i});
        }
    }
    int ans = 0;
    while(m--) {
        long double c; cin>>c;
        int id = lower_bound(stk.begin(),stk.end(),make_pair(c,0ll))-stk.begin()-1;
        ans += (a[stk[id].second].first*c+a[stk[id].second].second);
    }
    cout<<ans<<endl;
    return 0;
}
