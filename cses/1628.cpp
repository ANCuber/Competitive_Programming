#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int t[40];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin>>n>>x;
    for (int i = 0; i < n; ++i) cin>>t[i];
    int k = (n>>1);
    ll ans = 0, sum = 0;
    unordered_map<ll,ll> mp;

    for (int i = 0; i < (1<<k); ++i) {
        sum = 0;
        for (int j = 0; j < k; ++j) {
            if (i&(1<<j)) sum += t[j];
        }
        if (sum <= x) mp[sum]++;
    }
    for (int i = 0; i < (1<<(n-k)); ++i) {
        sum = 0;
        for (int j = 0; j < (n-k); ++j) {
            if (i&(1<<j)) sum += t[j+k];
        }
        if (sum <= x) ans += mp[x-sum];
    }
    cout<<ans<<endl;
    return 0;
}
