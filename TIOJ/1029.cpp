#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int dp[1005][1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    int s = 0;
    for (int i = 2; i <= n+1; ++i) {
        cin>>dp[i][i];
        s += dp[i][i];
        for (int j = i-1;j >= 2; --j) {
            dp[j][i] = max(dp[i][i]+min(dp[j][i-2],dp[j+1][i-1]),
            dp[j][j]+min(dp[j+1][i-1],dp[j+2][i]));
        }
    }
    cout<<dp[2][n+1]<<' '<<s-dp[2][n+1]<<endl;
    return 0;
}