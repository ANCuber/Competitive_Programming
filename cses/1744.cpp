#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int a, b, mn;

signed main() {
    scanf("%d%d",&a,&b);
    if (b < a) swap(a,b);
    vector<vector<int> > dp(a+1,vector<int>(b+2,1e9));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) dp[i][j] = 0;
            else if (i == 1 || j == 1) dp[i][j] = max(i,j)-1;
            else {
                mn = 1e9;
                for (int k = 1; k <= (i>>1); ++k) mn = min(mn,dp[k][j]+dp[i-k][j]+1);
                for (int k = 1; k <= (j>>1); ++k) mn = min(mn,dp[i][k]+dp[i][j-k]+1);
                dp[i][j] = mn;
            }
            //cerr<<dp[i][j]<<' ';
        }
        //cerr<<endl;
    }
    printf("%d\n",dp[a][b]);
    return 0;
}
