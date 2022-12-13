#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

#define int unsigned long long

int dp[15][15][(1<<14)+5] = {0};

int solve(int n, int m) {
    int msk = (1<<(m+1));
    for (int i = 0; i < 15; ++i) 
        for (int j = 0; j < 15; ++j) 
            for (int k = 0; k < (1<<14)+5; ++k) dp[i][j][k] = 0;
    
    dp[0][m][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int s = 0; s < msk; ++s) dp[i][0][s<<1] += dp[i-1][m][s];//from i-1 to i
        for (int j = 1; j <= m; ++j) {
            for (int s = 0; s < msk; ++s) {
                int l = s&(1<<(j-1)), u = s&(1<<j);
                if (!l && !u) {
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s];
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s];
                } else if (l && !u) {
                    dp[i][j][s^(1<<(j-1))] += dp[i][j-1][s];
                } else if (!l && u){
                    dp[i][j][s^(1<<j)] += dp[i][j-1][s];
                }
            }
        }
    }
    return dp[n][m][0];
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    while(cin>>n>>m && n && m) {
        cout<<solve(n,m)<<endl;
    }
    return 0;
}
