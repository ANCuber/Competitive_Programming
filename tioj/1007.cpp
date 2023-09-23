#include <bits/stdc++.h>
using namespace std;

long long dp[100];

int main() {
    int n, m;
    cin>>n>>m;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] << 1;
    }
    dp[n+1] = 2*dp[n] - 1;
    for (int i = n+2; i <= m; i++) {
        dp[i] = 2*dp[i-1] - dp[i-n-2];
    }
    cout<<dp[m]<<'\n';
    return 0;
}
    
