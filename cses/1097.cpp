#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

signed main() {
    int n;
    scanf("%d",&n);
    vector<ll> a(n+1,0);
    vector<vector<ll> > dp(n+1,vector<ll>(n+1,0));
    for (int i = 1; i <= n; ++i) scanf("%lld",&a[i]);
    for (int i = 1; i <= n; ++i) a[i] += a[i-1];
    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i+l-1 <= n; ++i) {
            if (l == 1) dp[i][i] = a[i]-a[i-1];
            else dp[i][i+l-1] = max(a[i+l-1]-a[i-1]-dp[i+1][i+l-1],a[i+l-1]-a[i-1]-dp[i][i+l-2]);
        }
    }
    printf("%lld\n",dp[1][n]);
    return 0;
}
