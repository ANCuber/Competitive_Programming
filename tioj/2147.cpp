#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, k;
ll ans = 2e18;

signed main() {
    scanf("%d%d",&n,&k);
    vector<vector<ll> > dp(n+1,vector<ll>(k+1,2e18));
    vector<ll> mn(k+1,0), a(n+1,0);
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%lld",&a[i]);
        for (int j = 2; j <= k; ++j) {
            for (int l = 1; l <= i-1; ++l) {
                ll cur = dp[l][j-1]+max(a[l]-a[i],0LL);
                if (dp[i][j] > cur || (dp[i][j] == cur && a[i]-a[l] )) {
                    a[i] = a[l];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) ans = min(ans,dp[i][k]);
    printf("%lld\n",ans);
    return 0;
}
