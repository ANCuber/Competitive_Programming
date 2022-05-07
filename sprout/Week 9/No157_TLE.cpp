#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int solve(int n, int m, int a[], int b[]) {
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(), cout.tie();
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin>>a[i]>>b[i];
        }
        int dp[m+1];
        for (int i = 0; i <= m; ++i) {
            if (a[0] <= i) dp[i] = b[0];
            else dp[i] = -1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = m; j >= 0; j--) {
                if (a[i] <= j) {
                    dp[j] = max(dp[j],dp[j-a[i]]+b[i]);
                } else {
                    dp[j] = dp[j];
                }
            }
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}