#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N; cin>>N;    
    vector<int> A(N+2,0), B(N+2,0), C(N+2,0);
    for (int i = 1; i <= N; ++i) {
        cin>>A[i];
        A[i] += A[i-1];
    }
    for (int i = 1; i <= N; ++i) cin>>B[i];
    for (int i = 1; i <= N; ++i) cin>>C[i];

    vector<vector<int> > dp(2,vector<int>(A[N]+2,0));
    for (int i = 0; i <= A[N]; ++i) {
        if (B[1] <= i && i <= C[1] && i <= A[1]) dp[1][i] = 1;
        else dp[1][i] = 0;
        //cout<<dp[1][i]<<' ';
        if (i) dp[1][i] += dp[1][i-1];
    }
    //cout<<endl;
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= A[N]; ++j) {
            if (j > A[i]) {
                dp[i&1][j] = 0;
            } else {
                if (j-B[i] < 0) {
                    dp[i&1][j] = 0;
                    //cout<<0;
                } else if (j-B[i] == 0) {
                    dp[i&1][j] = dp[i&1^1][0];
                } else if (j-C[i] <= 0) {
                    dp[i&1][j] = dp[i&1^1][j-B[i]];
                    //cout<<0<<"~"<<j-B[i];
                } else {
                    dp[i&1][j] = (dp[i&1^1][j-B[i]]-dp[i&1^1][j-C[i]-1]+mod)%mod;
                    //cout<<j-C[i]<<"~"<<j-B[i];
                }
            }
            //cout<<dp[i&1][j]<<' ';
            if (j) dp[i&1][j] = (dp[i&1][j]+dp[i&1][j-1])%mod;
        }
        //cout<<endl;
    }
    cout<<dp[N&1][A[N]]<<endl;
    return 0;
}
