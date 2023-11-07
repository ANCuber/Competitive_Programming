#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

const ll MXN = 1e15;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n; cin>>n;    
    vector<ll> f(__lg(MXN)+5,0);
    for (ll i = 0; i <= __lg(MXN)+1; ++i) f[i] = i*(1ll<<(i-1));
    ll ans = 0, cur = 0, cnt = 0;
    for (ll i = __lg(MXN)+1; i >= 0; --i) {
        if ((1ll<<i) > n) continue;
        ans += f[i];
        n -= (1ll<<i);
        ans += n*cnt;
        cnt++;
    }
    cout<<ans<<endl;
    return 0;
}
