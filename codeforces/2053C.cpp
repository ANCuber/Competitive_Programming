#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t;
    ll n, k, ans, cnt;
    while(t--) {
        cint>>n>>k;
        cnt = ans = 0;
        while(n < k) {
            if (n&1) {
                ans += (n>>1)+1;
            } else {
                
            }
            n >>= 1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
