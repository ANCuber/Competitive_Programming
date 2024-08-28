#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int NextStep(int x, int y, vector<vector<int> > &g) {
    int tmp = -1, mn = 1e9;
    for (int i = 0; i < 4; ++i) {
        if (g[x+dx[i]][y+dy[i]] == -1) continue;
        if (mn > g[x+dx[i]][y+dy[i]]) {
            mn = g[x+dx[i]][y+dy[i]];
            tmp = i;
        }
    }
    return tmp;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    int mn = 1e9, cx, cy;
    vector<vector<int> > g(n+2,vector<int>(m+2,-1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>g[i][j];
            if (g[i][j] < mn) {
                mn = g[i][j];
                cx = i, cy = j;
            }
        }
    }
    //cout<<"p"<<endl; return 0;
    int ans = 0;
    while(true) {
        ans += g[cx][cy];
        g[cx][cy] = -1;
        int tmp = NextStep(cx,cy,g);
        if (tmp == -1) break;
        cx += dx[tmp], cy += dy[tmp];
    }
    cout<<ans<<'\n';
    return 0;
}
