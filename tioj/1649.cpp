#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll h;
    cin>>n>>h;    
    vector<ll> mon(n);
    ll mx = 0;
    for (auto &i : mon) {
        cin>>i;
        mx = max(mx,i);
    }
    if (mx >= h) {
        cout<<"-1"<<endl;
        return 0;
    }
    ll cur = h;
    int ans = 0;
    for (auto i : mon) {
        if (i >= cur) {
            cur = h-i;
            ans++;
        } else {
            cur -= i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
