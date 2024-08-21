#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int n, m;

int Del(vector<vector<int> > &g) {
    for (int i = 1; i <= n; ++i) {
        int pre = -1, pid;
        for (int j = 1; j <= m; ++j) {
            if (pre == g[i][j] && pre != -1) {
                g[i][j] = g[i][pid] = -1;
                return pre;
            }
            if (g[i][j] != -1) {
                pre = g[i][j];
                pid = j;
            }
            //cout<<pre<<' ';
        }
        //cout<<endl;
    }
    for (int i = 1; i <= m; ++i) {
        int pre = -1, pid = 0;
        for (int j = 1; j <= n; ++j) {
            if (pre == g[j][i] && pre != -1) {
                g[j][i] = g[pid][i] = -1;
                return pre;
            }
            if (g[j][i] != -1) {
                pre = g[j][i];
                pid = j;
            }
        }
    }
    return -1;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    vector<vector<int> > g(n+5,vector<int>(m+5,-1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>g[i][j];
        }
    }
    int ans = 0, cur;
    while(true) {
        cur = Del(g);
        if (cur == -1) break;
        ans += cur;
    }
    cout<<ans<<'\n';
    return 0;
}
