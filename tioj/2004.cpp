#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

const ll mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        int p = (n-1)<<1;
        ll base = 2, ans = 1;
        while(p) {
            if (p&1) ans = ans*base%mod;
            base = base*base%mod;
            p >>= 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
