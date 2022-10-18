#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int,int>
#define p_q priority_queue
#define endl '\n'
#define pb push_back

int dx[8] = {0,0,1,-1,-1,1,-1,1};
int dy[8] = {1,-1,0,0,1,1,-1,-1};

void dfs(int x, int y, vector<vector<int> > &g) {
    g[x][y] = 0;
    for (int i = 0; i < 8; ++i) {
        if (g[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i],g);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    while(cin>>m>>n) {
        vector<vector<int> > g1(m+2,vector<int>(n+2,0)), g2(m+2,vector<int>(n+2,0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                char x; cin>>x;
                g1[i][j] = x-'0';
                g2[i][j] = (x=='2');
            }
        }
        int cnt = 0, num = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (g1[i][j]) {
                    dfs(i,j,g1);
                    cnt++;
                }
                if (g2[i][j]) {
                    dfs(i,j,g2);
                    num++;
                }
            }
        }
        cout<<cnt<<' '<<num<<endl;
    }
    
    return 0;
}
