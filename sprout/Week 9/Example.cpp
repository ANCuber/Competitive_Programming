#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    int n; cin>>n;
    int graph[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; j++) {
            cin>>graph[i][j];
        }
    }
    vector <int> dp(n);
    dp[0] = graph[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!j && !i) continue;
            if (!j) dp[j] = dp[j]+graph[i][j];
            else if (!i) dp[j] = dp[j-1]+graph[i][j];
            else dp[j] = max(dp[j],dp[j-1])+graph[i][j];
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}