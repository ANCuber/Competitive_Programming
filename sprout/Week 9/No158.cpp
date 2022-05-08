#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(), cout.tie();
    int t; cin>>t;
    while(t--) {
        int n, m, k; cin>>n>>m>>k;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin>>a[i]>>b[i];
        }
        int dp[2][m+1][k+1];
        for (int j = 0; j <= m; ++j) {
            for (int h = 0; h <= k; ++h) {
                dp[0][j][h] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int h = 0; h <= k; ++h) {
                    if (j == 0 || h == 0) {
                        dp[(i+1)%2][j][h] = 0;
                        continue;
                    }
                    if (a[i] <= j && h >= 1) {
                        dp[(i+1)%2][j][h] = max(dp[i%2][j][h],dp[i%2][j-a[i]][h-1]+b[i]);
                    } else {
                        dp[(i+1)%2][j][h] = dp[i%2][j][h];
                    }
                }
            }
        }
        cout<<dp[n%2][m][k]<<endl;
    }
    return 0;
}