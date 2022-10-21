#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(n);
        for (auto &i:arr) cin >> i;
        vector< vector<int> > dp(n, vector<int> (2, 0));
        dp[0][0] = s[0]=='1' ? arr[0] : 0;
        dp[0][1] = s[0]=='1' ? -1e9 : arr[0];
        for (int i = 1; i < n; ++i) {
            if (s[i] == '1') {
                dp[i][0] = max(dp[i-1][0] + arr[i], dp[i-1][1]);
                dp[i][1] = dp[i-1][1] + arr[i];
            } else {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] + arr[i];
            }
        }
        cout << dp[n-1][0] << endl;
    }
    
    return 0;
}

/*if has 
    dp[1] = dp[i-1][1] + a[i]
    dp[0] = dp[i-1][0] + a[i], dp[i-1][1]
dp[1] = dp[i-1][0] + a[i]
dp[0] = dp[i-1][0]
*/



