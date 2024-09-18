#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void paint(int x, int y, vector<vector<int> > &g) {
    g[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        if (!g[x+dx[i]][y+dy[i]]) paint(x+dx[i],y+dy[i],g);
    }
}

signed main() {
    int n, m; cin>>n>>m;
    vector<vector<int> > g(n+2,vector<int>(m+2,0)), pre(n+2,vector<int>(m+2,0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x; cin>>x;
            g[i][j] = (x == '#');
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            pre[i][j] = pre[i][j-1]+g[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j]) {
                int k = 0;
                while(g[i+k][j+k] && g[i+k][j-k] && 
                (pre[i+k][j+k-1]-pre[i+k][j-k] == 0 || !k)) {
                    k++; 
                }
                int tk = k;
                k -= 2;
                while(g[i+tk][j+k] && g[i+tk][j-k] && 
                (pre[i+tk][j+k-1]-pre[i+tk][j-k] == 0 || !k) && k >= 0) {
                    k--;
                    tk++;
                }
                k++, tk--;
                //cout<<i<<' '<<j<<' '<<k<<' '<<tk<<endl;
                if (!k && g[i+tk][j] && tk) ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

