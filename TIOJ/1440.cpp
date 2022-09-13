#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define p_q priority_queue

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];
    sort(a.begin(),a.end());

    int m; cin>>m;
    multiset < pii > s;
    int b, c;
    while(m--) {
        cin>>b>>c;
        s.insert({b,c});
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound({a[i],0});
        if (it != s.end()) {
            ans += it->second;
            s.erase(it);
        } else {
            cout<<"Impossible."<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}
