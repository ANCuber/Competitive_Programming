#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

struct Range{
    vector<int> L;
    vector<int> R;
};

void Run() {
    int n, m; cin>>n>>m;
    vector<Range> but(n+2);
    for (int i = 1; i <= n; ++i) {
        int pre = 0, str = 0;
        for (int j = 1; j <= m+1; ++j) {
            char x;
            if (j <= m) cin>>x;
            else x = '*';
            if (x == '*' && pre == 1) {
                but[i].L.pb(str);
                but[i].R.pb(j-1);
                pre = 0;
            } else if (x == '-' && pre == 0) {
                str = j;
                pre = 1;
            }
        }
    }
    
    vector<vector<vector<int> > > dp(2,vector<vector<int> >(m+2,vector<int>(m+2,0)));
    for (int i = 1; i <= m; ++i) dp[0][i][0] = 1;
    //dp1
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = 0, tmp;
        for (int j = 1; j <= m; ++j) {
            if (!but[i].L.size()) tmp = 1;
            else tmp = (but[i].L.size() == 1)&&(j >= but[i].L[0])&&(j <= but[i].R[0]);
            dp[i&1][j][0] = tmp&(dp[i&1^1][j-1][0]|dp[i&1^1][j][0]|dp[i&1^1][j+1][0]);
            cur |= dp[i&1][j][0];
        }
        ans &= cur;
    }
    if (ans) {
        cout<<1<<endl;
        return;
    }
    //dp2
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) dp[0][i][j] = (i!=j);
    ans = 1;
    for (int i = 1; i <= n; ++i) {
        int cur = 0;
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= m; ++k) {
                if (j == k) {
                    dp[i&1][j][k] = 0;
                    continue;
                }
                
                int tmp = 1;
                if (but[i].L.size() == 1) {
                    tmp = 0;
                    tmp |= ((but[i].L[0] <= j)&&(j <= but[i].R[0]));
                    tmp |= ((but[i].L[0] <= k)&&(k <= but[i].R[0]));
                } else if (but[i].L.size()) {
                    int a = min(j,k), b = max(j,k);
                    tmp &= ((but[i].L[0] <= a)&&(but[i].R[0] >= a));
                    tmp &= ((but[i].L[1] <= b)&&(but[i].R[1] >= b));
                }
                
                dp[i&1][j][k] = 0;
                for (int u = -1; u <= 1; ++u) {
                    for (int v = -1; v <= 1; ++v) {
                        dp[i&1][j][k] |= dp[i&1^1][j+u][k+v];
                    }
                }
                dp[i&1][j][k] &= tmp;
                cur |= dp[i&1][j][k];
            }
        }
        ans &= cur;
    }
    if (ans) cout<<2<<endl;
    else cout<<3<<endl;
    return;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin>>t;    
    while(t--) Run();
    return 0;
}

