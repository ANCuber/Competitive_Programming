#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) {
        ll n, m;
        cin>>n>>m;
        if (n >= 2*m) {
            cout<<0<<endl;
            continue;
        }
        if (m > n) {
            vector<int> f(n+5,1), r(n+5,n);
            for (ll i = 2; i <= n; ++i) f[i] = f[i-1]*i%m;
            for (ll i = n-1; i > 0; --i) r[i] = r[i+1]*i%m;
            r[n+1] = 1;
            ll ans = 0;
            for (int i = 1; i <= n; ++i) {
                ans = (ans+__lg(i)*f[i-1]%m*r[i+1]%m)%m;
            }
            cout<<ans<<endl;
        } else {
            ll ans = __lg(m)%m;
            for (ll i = 1; i <= n; ++i) {
                if (i == m) continue;
                ans = ans*i%m;
            }
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
