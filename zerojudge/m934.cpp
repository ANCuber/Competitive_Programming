#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;    
    vector<int> a(n+2);
    vector<vector<int> > dp(n+2,vector<int>(n+2,1e9));
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; ++i) dp[i][i] = 0;
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i+l-1 <= n; ++i) {
            for (int j = 1; j < l; ++j) {
                dp[i][i+l-1] = min(dp[i][i+l-1],dp[i][i+j-1]+dp[i+j][i+l-1]+abs((a[i+l-1]-a[i+j-1])-(a[i+j-1]-a[i-1])));
            }
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}
