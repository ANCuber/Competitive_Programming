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
    string s;
    while (cin >> s && s[0] != '0') {
        int n = s.size();
        vector< vector<int> > dp(n, vector<int> (2, 0));
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                dp[i][0] = 0;
                dp[i][1] = dp[i-1][0];
            }
            else {
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
                dp[i][1] = 0;
                if (s[i-1] == '1' || (s[i-1]=='2' && s[i] <= '6' ) ) {
                    dp[i][1] = dp[i-1][0];
                }
            }
        }
        cout << dp[n-1][0] + dp[n-1][1] << endl;
    }
    
    return 0;
}
