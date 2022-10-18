#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pii pair<int,int>

int dx[8] = {0,0,1,-1,-1,1,1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

int ans[3] = {0,0,0};

void dfs(int x, int y, vector<vector<int> > &g, int ty) {
    g[x][y] = 0;
    for (int i = 0; i < 8; ++i) {
        if (g[x+dx[i]][y+dy[i]] == ty) {
            dfs(x+dx[i],y+dy[i],g,ty);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, h; cin>>w>>h;
    vector<vector<int> > g(h+2,vector<int>(w+2,0)), sp;
    char a;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin>>a;
            if (a == '-') {
                g[i][j] = 1;
            } else if (a == 'G') {
                g[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (g[i][j]) {
                ans[g[i][j]]++;
                dfs(i,j,g,g[i][j]);
            }
        }
    }
    cout<<ans[2]<<' '<<ans[1]<<endl;
    return 0;
}
