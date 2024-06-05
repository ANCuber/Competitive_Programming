#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back
#define int long long

int pre[MAX_D][MAX_D];

void init(){
    for (int i=0 ; i<MAX_D ; i++){
        for (int j=0 ; j<MAX_D ; j++){
            pre[i][j] = (i*j)%D;
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K, D; cin>>N>>K>>D; 
    if (N > 500) return 0;
    vector<int> w(n+2),v(n+2);
    init();
    for (int i = 1; i <= N; ++i) cin>>w[i]>>v[i];
    int dp[2][K+5][D+5];
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k < D; ++k) {
                dp[i&1][j][k] = dp[i&1^1][j][k];
                if (j) dp[i&1][j][k] = max(dp[i&1][j][k],dp[i&1^1][j-1][pre[k][inv[w[i]]]]+v[i]);
            }
        }
    }
    for (int i = 0; i < D; ++i) { 
        if (i) cout<<' ';
        
    }
    
    return 0;
}
