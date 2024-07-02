#pragma GCC optimize("Ofast","unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

//123
//456

bool check(char x, char y, int tag) {
    if (x == '0' || y == '0') return 0;
    if (!tag) {//horizontal
        if (x == 'X' || x == 'H' || x == 'L' || x == 'F') {
            return (y != 'I' && y != 'F' && y != 'L');
        } else {
            return 0;
        }
    } else {//vertical
        if (x == 'X' || x == 'I' || x == 'F' || x == '7') {
            return (y != '7' && y != 'F' && y != 'H');
        } else {
            return 0;
        }

    }
}

int dfs(int cur, vector<int> &vis, vector<vector<int> > &g) {
    vis[cur] = 1;
    int ret = 1;
    for (auto v : g[cur]) {
        if (!vis[v]) ret += dfs(v,vis,g);
    }
    return ret;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin>>n>>m;
    vector<vector<char> > G(n+2,vector<char>(m+2));
    vector<vector<int> > g(n*m+5);
    vector<int> vis(n*m+5,0);
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin>>G[i][j];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check(G[i][j],G[i+1][j],1)) {
                g[m*(i-1)+j].push_back(m*i+j);
                g[m*i+j].push_back(m*(i-1)+j);
            }
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (check(G[j][i],G[j][i+1],0)) {
                g[(j-1)*m+i].push_back((j-1)*m+i+1);
                g[(j-1)*m+i+1].push_back((j-1)*m+i);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!vis[(i-1)*m+j]) {
                ans = max(ans,dfs((i-1)*m+j,vis,g));
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
