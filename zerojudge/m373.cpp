#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k; cin>>n>>k;
    vector<int> a(n+2);
    for (int i = 1; i <= n; ++i) cin>>a[i];
    vector<vector<int> > dp(2,vector<int>(k+5,-1e9));
    dp[1][k] = a[1]; 
    if (k > 0) dp[1][k-1] = 0;
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            dp[i&1][j] = max(dp[i&1^1][j]+a[i],dp[i&1^1][j+1]);
            ans = max(ans,dp[i&1][j]);
        }
        dp[i&1][k] = max(a[i],dp[i&1^1][k]+a[i]);
        ans = max(ans,dp[i&1][k]);
    }
    cout<<ans<<endl;
    return 0;
}
