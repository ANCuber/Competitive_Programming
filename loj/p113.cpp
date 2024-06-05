#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

vector<ll> bas;

void add(ll cur) {
    for (auto i : bas) cur = min(cur,cur^i);
    if (cur) bas.pb(cur);
    //if (cur) cout<<cur<<endl;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    for (int i = 1; i <= n; ++i) {
        ll a; cin>>a;
        add(a);
    }
    ll ans = 0;
    for (auto i : bas) ans = max(ans,ans^i);
    cout<<ans<<endl;
    return 0;
}
