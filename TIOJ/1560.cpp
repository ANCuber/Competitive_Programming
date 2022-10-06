#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    vector<vector<int> > dp(2,vector<int>(55));
    dp[0][1] = dp[1][1] = 1;
    for (int i = 2; i <= 50; ++i) {
        dp[0][i] = dp[1][i-1];
        dp[1][i] = dp[1][i-1]+dp[0][i-1];
    }
    while(cin>>n) {
        cout<<dp[0][n]+dp[1][n]<<endl;
    }
    
    return 0;
}

