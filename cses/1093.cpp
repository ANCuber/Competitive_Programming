#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    if (((n*(n+1))>>1)&1) {
        cout<<0<<endl;
        return 0;
    }
    int tar = ((n*(n+1))>>2);
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = tar; j >= 0; --j) {
            if (j-i < 0) break;
            dp[j] += dp[j-i];
            dp[j] %= mod;
        }
    }
    cout<<(dp[tar]*500000004%mod)<<endl;
    return 0;
}
