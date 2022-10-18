#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n, a; cin>>m>>n;    
    vector<vector<int> > dp(2,vector<int>(n+2,-1e9));
    int ans = 0;
    for (int i = 1 ;i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>a;
            dp[i%2][j] = max({0,dp[i%2][j-1],dp[(i+1)%2][j]})+a;
            ans = max(ans,dp[i%2][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
