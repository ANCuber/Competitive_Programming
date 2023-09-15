#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;    
    map<ll,ll> mp;
    for (int i = 0; i < n; ++i) {
        ll x, y, k;
        cin>>x>>y>>k;
        mp[x*x+y*y] += k;
    }
    ll sum = 0, mx = 0;
    for (auto [a,b] : mp) {
        if (sum >= 0) {
            sum += b;
        } else {
            sum = b;
        }
        mx = max(mx,sum);
    }
    cout<<mx<<endl;
    return 0;
}
