#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int dp[105][105] = {0};

int solve(int x, int y) {
    if (dp[x][y]) return dp[x][y];
    if (x == y) return dp[x][y] = 1;
    int ans = 1e9;
    for (int i = 1; i < x; ++i) ans = min(ans,solve(i,y)+solve(x-i,y));
    for (int i = 1; i < y; ++i) ans = min(ans,solve(x,i)+solve(x,y-i));
    return dp[x][y] = ans;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    cout<<solve(n,m)<<'\n';
    return 0;
}
