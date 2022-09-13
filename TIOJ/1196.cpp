#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    vector<vector<int> > g(n+1,vector<int>(n+1,0));
    char x;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>x;
            if (x-'0' >= 0 && x-'0' <= 9) {
                g[i][j] = x-'0';
            } else if (x == 'X') {
                g[i][j] = -1e9;
            } else {
                g[i][j] = 0;
            }
        }
    }
    vector<int> dp(n+1,0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (g[i][j] < 0) dp[j] = -1e9;
            else if (i == 1) dp[j] = dp[j-1]+g[i][j];
            else if (j == 1) dp[j] = dp[j]+g[i][j];
            else dp[j] = max(dp[j],dp[j-1])+g[i][j];
            //cout<<dp[j]<<' ';
        }
        //cout<<endl;
    }
    if (dp[n] < 0) cout<<'X'<<endl;
    else cout<<dp[n]<<endl;
    return 0;
}
