#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

ll n, m;

ll power(ll a, ll x) {
    ll ret = a, base = 1;
    while(x) {
        if (x&1) ret = ret*base%m;
        base = base*base%m;
        x >>= 1;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n>>m && n && m) {
        vector<ll> c(n+1);
        c[1] = 1;
        for (ll i = 1; i < n; ++i) {
            c[i+1] = c[i]*(4*i+2)%m*power(i+2,m-2)%m;
        }
        cout<<c[n]<<endl;
    }
    return 0;
}
