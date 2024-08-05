#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int T;
    cin >> T;

    while (T--) {
        int N;
        string s;
        cin >> N >> s;
    
        vector< vector< vector<int> > > dp(N + 1, vector< vector<int> >(4, vector<int>(2, -1e8)));
        dp[0][0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (int msk = 0; msk < 4; msk++) {
                for (int j = 0; j < 2; j++) {
                    if (((msk & (1 << j)) > 0) != (s[i] == 'L')) continue;
                    for (int k = 0; k < 2; k++) {
                        auto& nxt = dp[i + 1][msk ^ (1 << k)][k];
                        nxt = max(nxt, dp[i][msk][j] + (k == 0));
                    }
                }
            }
        }

        int ans = -1;
        for (int i = 0; i < 4; i++) for (int j = 0; j < 2; j++) ans = max(ans, dp[N][i][j]);
        cout << ans << '\n';
    }

    return 0;
}
