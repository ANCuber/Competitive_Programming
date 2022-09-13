#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
#define p_q priority_queue
#define endl '\n'

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dfs(int x, int y, vector<vector<int> > &g) {
    int clr = g[x][y];
    int cnt = 1;
    g[x][y] = -1;
    for (int i = 0; i < 4; ++i) {
        if (g[x+dx[i]][y+dy[i]] == clr) {
            cnt += dfs(x+dx[i],y+dy[i],g);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;    
    vector<vector<int> > g(n+2,vector<int>(m+2,-1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin>>g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] >= 0) {
                ans = max(ans,dfs(i,j,g));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
