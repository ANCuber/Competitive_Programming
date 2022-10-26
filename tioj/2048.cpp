#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int mx = -2e18-5;
    vector<int> a(n+1,0);
    vector<vector<int> > dp(n+1,vector<int>(2,0));
    for (int i = 1; i <= n; ++i) cin>>a[i];

    dp[1][1] = a[1];
    dp[1][0] = dp[2][0] = -2e18-5;
    dp[2][1] = max(0LL,a[1])+a[2];
    mx = max(dp[1][1],mx);
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = max(0LL,dp[i-1][1])+a[i];
        dp[i][0] = mx+a[i];
        mx = max({mx,dp[i][0],dp[i-1][1]});
    }
    int ans = -2e18-5;
    for (int i = 3; i <= n; ++i) ans = max(ans,dp[i][0]);
    cout<<ans<<endl;
    return 0;
}
