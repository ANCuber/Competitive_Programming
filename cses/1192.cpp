#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y, vector<vector<int> > &g) {
    g[x][y] = 0;
    for (int i = 0; i < 4; ++i) if (g[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i],g);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char a; cin>>a;
            if (a == '.') g[i][j] = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j]) {
                cnt++;
                dfs(i,j,g);
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
