#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin>>n>>m>>k;
    vector<vector<vector<int> > > a(n+2, vector<vector<int> > (m+2, vector<int>(k+2,1)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int l = 1; l <= k; ++l) {
                cin>>a[i][j][l];
            }
        }
    }
    int cx = 1, cy = 1, cz = 1;
    while(true) {
        a[cx][cy][cz] = 1;
        //cout<<cx<<' '<<cy<<' '<<cz<<endl;
        int flg = 0;
        for (int i = 0; i < 6; ++i) {
            if (!a[cx+dx[i]][cy+dy[i]][cz+dz[i]]) {
                cx += dx[i], cy += dy[i], cz += dz[i];
                flg = 1;
                break;
            }
        }
        if (!flg) break;
    }
    cout<<--cx<<' '<<--cy<<' '<<--cz<<'\n';
    return 0;
}

