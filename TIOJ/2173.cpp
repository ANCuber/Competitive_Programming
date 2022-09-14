#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'
#define int long long

int m, n;

int solve(vector<vector<int> > &g, int f) {
    vector<vector< pll > > dp(m+2,vector< pll >(n+2,{0,0}));//from top = 1, from left = 2
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            //if (g[i][j] < 0) continue;
            if (dp[i-1][j].first > dp[i][j-1].first) {
                dp[i][j].first = g[i][j] + dp[i-1][j].first;
                dp[i][j].second = 1;
            } else {
                dp[i][j].first = g[i][j] + dp[i][j-1].first;
                dp[i][j].second = 2;
            }
        }
    }
    if (f || dp[m][n].first < 0) return dp[m][n].first;
    int i = m, j = n;
    while(true) {
        g[i][j] = 0;
        if (dp[i][j].second == 1) {
            i--;
        } else if (dp[i][j].second == 2) {
            j--;
        } else {
            break;
        }
    }

    return dp[m][n].first;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>m>>n;    
    vector<vector<int> > g(m+2,vector<int>(n+2,0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin>>g[i][j];
            if (g[i][j] < 0) g[i][j] = -1e8;
        }
    }
    int ans = 0;
    ans += solve(g,0);
    ans += solve(g,1);
    if (ans <= 0) cout<<0<<endl;
    else cout<<ans<<endl;

    return 0;
}
