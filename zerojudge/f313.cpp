#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int r, c, k, m;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>r>>c>>k>>m;
    vector<vector<int> > g(r+2,vector<int>(c+2,-1)), buf(r+2,vector<int>(c+2,0));
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin>>g[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= r; ++j) {
            for (int l = 1; l <= c; ++l) {
                if (g[j][l] == -1) continue;
                for (int h = 0; h < 4; ++h) {
                    if (g[j+dx[h]][l+dy[h]] == -1) continue;
                    buf[j][l] -= g[j][l]/k;
                    buf[j+dx[h]][l+dy[h]] += g[j][l]/k;
                }
            }
        }
        for (int j = 1; j <= r; ++j) {
            for (int l = 1; l <= c; ++l) {
                g[j][l] += buf[j][l];
                buf[j][l] = 0;
            }
        }
    }
    int mx = -1, mn = 1e9;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (g[i][j] == -1) continue;
            mx = max(mx,g[i][j]);
            mn = min(mn,g[i][j]);
        }
    }
    cout<<mn<<'\n'<<mx<<'\n';
    return 0;
}
