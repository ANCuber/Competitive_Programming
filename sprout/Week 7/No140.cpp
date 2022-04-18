#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mod 1000007

//red 0, green 1, blue 2
long long dp[100001][3][3];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    dp[1][0][0] = 1;
    dp[1][1][1] = 1;
    dp[1][2][2] = 1;
    for (int i = 2; i <= 100000; ++i) {
        dp[i][0][0] = (dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][0][2])%mod;
        dp[i][1][1] = (dp[i-1][1][0]+dp[i-1][1][1])%mod;
        dp[i][2][2] = (dp[i-1][2][0]+dp[i-1][2][2])%mod;
        dp[i][0][1] = (dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][0][2] = (dp[i-1][0][0]+dp[i-1][0][2])%mod;
        dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1])%mod;
        dp[i][2][0] = (dp[i-1][0][0]+dp[i-1][0][2])%mod;
    }
    while(t--) {
        int n; cin>>n;
        long long ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                ans += dp[n][i][j];
                ans %= mod;
            }
        }
        cout<<ans<<endl;
    }
}