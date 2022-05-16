#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m;
        cin>>n>>m;
        int coin[n][2];//c,k
        vector <int> item(1005);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin>>coin[i][0]>>coin[i][1];
            int v = coin[i][0];
            int k = coin[i][1];
            int base = 1;
            while (k) {
                if (base <= k) k -= base;
                else {
                    item[sum++] = k*v;
                    break;
                }
                item[sum++] = v*base;
                base<<=1;
            }
        }
        int dp[2][m+1];
        for (int i = 0; i < sum; ++i) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    if (j == item[0]) dp[0][j] = 1;
                    else dp[0][j] = 0;
                } else {
                    if (j == item[i]) dp[i%2][j] = 1;
                    else if (j > item[i]) dp[i%2][j] = max(dp[(i+1)%2][j],dp[(i+1)%2][j-item[i]]);
                    else dp[i%2][j] = dp[(i+1)%2][j];
                }
            }
        }
        if (dp[0][m] == 1 || dp[1][m] == 1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}