#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(), cout.tie();
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        int a[n], b[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin>>a[i]>>b[i];
            sum += b[i];
        }
        vector <int> dp(sum+1,2e9);
        dp[b[0]] = a[0];
        for (int i = 1; i < n; ++i) {
            for (int j = sum; j >= 0; --j) {
                if (j == b[i]) dp[j] = min(dp[j],a[i]);
                if (b[i] <= j) {
                    //cout<<'@'<<dp[j]<<' '<<dp[j-b[i]]+a[i]<<endl;
                    dp[j] = min(dp[j],dp[j-b[i]]+a[i]);
                } else {
                    dp[j] = dp[j];
                }
            }
        }
        int ans = -1;
        for (int i = 0; i <= sum; ++i) {
            if (dp[i] <= m) ans = i;
        }
        cout<<ans<<endl;
    }
    return 0;
}