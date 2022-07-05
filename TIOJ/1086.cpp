#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int dp[20];
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i < 20; ++i) {
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }
    while(cin>>n && n) {
        cout<<dp[n]<<endl;
    }
    return 0;
}
