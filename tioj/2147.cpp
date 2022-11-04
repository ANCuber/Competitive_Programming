#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
ll ans = 2e18;

signed main() {
    scanf("%d%d",&n,&k);
    vector<ll> a(n+1,0);
    vector<vector<pair<ll,ll> > > dp(n+1,vector<pair<ll,ll> >(k+1,{2e18,2e18}));
    for (int i = 1; i <= n; ++i) scanf("%lld",&a[i]);
    for (int i = 1; i <= n; ++i) {
        dp[i][1] = {0,a[i]};
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= min(k,i); ++j) {
            pair<ll,ll> tmp = {2e18,2e18};
            for (int l = 1; l <= i-1; ++l) {
                ll cur = dp[l][j-1].first+max(0ll,dp[l][j-1].second-a[i]);
                if (tmp.first > cur || (tmp.first == cur && tmp.second > dp[l][j-1].second)) {
                    tmp = {cur,dp[l][j-1].second};
                }
            }
            dp[i][j] = {tmp.first,max(tmp.second,a[i])};
        }
    }
    /*for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            cerr<<dp[j][i].first<<':'<<dp[j][i].second<<' ';
        }
        cerr<<endl;
    }*/
    for (int i = 1; i <= n; ++i) ans = min(ans,dp[i][k].first);
    printf("%lld\n",ans);
    return 0;
}

