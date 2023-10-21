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
    ll n, ans = 0, k;
    cin>>n>>k;
    ll a[k+5];
    for (int i = 0; i < k; ++i) cin>>a[i];
    
    for (ll i = 1; i < (1<<k); ++i) {
        ll tmp = 0, cur = n;
        for (ll j = 0; j < k; ++j) {
            if ((i>>j)&1) {
                tmp++;
                cur /= a[j];
            }
        }
        if (tmp&1) {
            ans += cur;
        } else {
            ans -= cur;
        }
    }
    cout<<ans<<endl;
    return 0;
}
