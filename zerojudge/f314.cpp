#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n; cin>>m>>n;
    vector <int> arr(n+1);
    vector <int> l(n+1);
    vector <int> r(n+1);
    vector <vector<int> > dp(m+1,vector<int>(n+1,0));
    for (int i = 1;i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>arr[j];
            if (j == 1) {
                l[j] = dp[i-1][j] + arr[j];
            } else {
                l[j] = max(dp[i-1][j],l[j-1]) + arr[j];
            }  
        }
        for (int j = n; j > 0; --j) {
            if (j == n) {
                r[j] = dp[i-1][j] + arr[j];
            } else {
                r[j] = max(dp[i-1][j],r[j+1]) + arr[j];
            }
            dp[i][j] = max(l[j],r[j]);
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans,dp[m][i]);
    }
    cout<<ans<<endl;
    return 0;
}